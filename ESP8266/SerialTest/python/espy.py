#! /usr/bin/env python
import sys
import serial
import time

def print_usage():
    print("Usage: espy.py <serial_port>[:baud_rate] <command> [<args>]")
    print("Commands:")
    print("  status")
    print("  reset")
    print("  join <ssid> <password>")
    print("  leave")

def send_command(ser, command, delay=1):
    ser.write((command + '\r\n').encode())
    time.sleep(delay)
    response = ser.read_all().decode(errors='ignore')
    print(response)

def main():
    if len(sys.argv) < 3:
        print_usage()
        sys.exit(1)

    port_info = sys.argv[1].split(':')
    port = port_info[0]
    baud_rate = int(port_info[1]) if len(port_info) > 1 else 9600
    command = sys.argv[2]

    try:
        ser = serial.Serial(port, baud_rate, timeout=15 , rtscts=False)
    except serial.SerialException as e:
        print(f"Error opening serial port {port}: {e}")
        sys.exit(1)

    if command == "status":
        for cmd in ["AT", "AT+GMR", "AT+CWMODE?", "AT+CWJAP?", "AT+CIFSR"]:
            send_command(ser, cmd)
    elif command == "reset":
        send_command(ser, "AT+RST")
    elif command == "join":
        if len(sys.argv) < 5:
            print("Error: join command requires ssid and password")
            print_usage()
            sys.exit(1)
        ssid = sys.argv[3]
        password = sys.argv[4]
        send_command(ser, 'AT+CWMODE=1')
        send_command(ser, f'AT+CWJAP="{ssid}","{password}"')
    elif command == "leave":
        send_command(ser, "AT+CWQAP")
    else:
        print(f"Unknown command: {command}")
        print_usage()
        sys.exit(1)

    ser.close()

if __name__ == "__main__":
    main()
