#!/usr/bin/env ruby -w
require 'serialport'
require 'uri'

class EspyClient
  attr_accessor :socket

  GOOD_STATUS_CODES = ["OK","ready","Linked","Unlink"]
  BAD_STATUS_CODES = ["ERROR", "link is not"]
  ALL_STATUS_CODES = GOOD_STATUS_CODES + BAD_STATUS_CODES

  def initialize(port_name,port_options={},read_timeout=15)
    self.socket = SerialPort.new port_name, port_options
    self.socket.read_timeout = read_timeout
    puts "ESP8266 Client initialised for : #{port_name}"
    puts "            connection options : #{socket.modem_params.inspect}"
    puts "                       signals : #{socket.signals.inspect}"
    puts "Waiting to warm up the connection.."
    sleep(3)
    clear
  rescue Errno::ENOENT
    self.socket = nil
    puts "ERROR: Seems like that port is not available"
  end

  # Command:
  def status(*args)
    tx_with_echo("AT") && tx_with_echo("AT+GMR") && tx_with_echo("AT+CWMODE?") && tx_with_echo("AT+CWJAP?") && tx_with_echo("AT+CIFSR")
  end

  def reset(*args)
    tx_with_echo("AT+RST")
  end

  def ls(*args)
    tx_with_echo("AT+CWLAP")
  end

  def join(ssid,password)
    tx_with_echo(%{AT+CWJAP="#{ssid}","#{password}"})
  end

  def get(url)
    uri = URI.parse(url)
    get_request = "GET #{uri.path} HTTP/1.1" << "\r\n"
    get_request << "Host: #{uri.host}" << "\r\n"
    get_request << "User-Agent: EspyClient/0.9.2.4" << "\r\n"
    get_request << "Accept: */*" << "\r\n"

    if tx_with_echo(%{AT+CIPSTART="TCP","#{uri.host}",#{uri.port}})
      # CIPSEND is a little different - it returns to a > prompt
      socket.write %{AT+CIPSEND=#{get_request.length + 2}\r\n}
      sleep(0.3)
      begin
        print socket.getc
      end until socket.eof?
      tx_with_echo(get_request)
    end
    tx_with_echo("AT+CIPCLOSE")
  end

  def leave(*args)
    tx_with_echo("AT+CWQAP")
  end

  def clear(*args)
    return unless socket
    until socket.eof? do
      puts "clearing buffer: #{socket.readline}"
      sleep(0.3)
    end
  end

  protected

  def tx_with_echo(command,options={})
    result = tx(command,options) do |line|
      puts line.gsub("\r", "\n")
    end
    result_status = GOOD_STATUS_CODES.include?(result.last)
    puts "STATUS: Houston, we have a problem" unless result_status
    result_status
  end

  # Command: transmit the +command+ and return the result
  def tx(command,options={})
    return [] unless socket
    socket.write "#{command}\r\n"
    sleep(1)

    # hum, this is more involved than would be ideal to account for sketchy serial comms
    buffer =[]
    retries = 0
    retry_limit = options[:retry_limit]||10
    line_wait = options[:line_wait]||0.3
    unfinshed_line = nil
    begin
      lines = socket.readlines
      if lines.empty?
        sleep(line_wait)
        retries += 1
      else
        lines.each_with_object(buffer) do |raw_line,memo|
          line = raw_line.chomp.chomp
          if line == raw_line
            unfinshed_line ||= ''
            unfinshed_line << line
          else
            line, unfinshed_line = unfinshed_line + line, nil if unfinshed_line
            memo << line
            yield line if block_given?
          end
        end
      end
    end until ALL_STATUS_CODES.include?(buffer.last) || retries > retry_limit
    buffer
  end

end


# parse command parameters
port_spec,opcode,params = ARGV.shift, ARGV.shift, ARGV
port_name,baud_rate = port_spec.split(':') if port_spec
unless (baud_rate = baud_rate.to_i) > 0
  baud_rate = 9600
end

# invoke the requested operation, else show some help
if opcode && port_name
  EspyClient.new(port_name, { 'baud' => baud_rate }).send(opcode,*params)
else
  puts <<-EOS

Usage:
  #{$0} port_spec cmd

Where port_spec is the serial port name, with optional baud rate qualifier:
  /dev/tty.wchusbserial14540         # 9600 baud rate (default)
  /dev/tty.wchusbserial14540:115200  # 115200 baud rate

Where cmd is one of:

  status             : check ESP8266 status and get device info
  reset              : reset the ESP8266
  ls                 : list access points
  join ssid password : join access point "ssid" with "password"
  get url            : get web page with address "url"
  leave              : disconnect from access point

Example:
  #{$0} /dev/tty.wchusbserial14540 status
  #{$0} /dev/tty.wchusbserial14540:115200 ls
  #{$0} /dev/tty.wchusbserial14540:9600 join MySSID mypassword
  #{$0} /dev/tty.wchusbserial14540 get http://tycho.usno.navy.mil/timer.pl

  EOS
end
