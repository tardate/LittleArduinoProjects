#!/usr/bin/ruby

class WaveGenerator
  attr_accessor :wavetype, :steps
  attr_accessor :maximum_value
  attr_accessor :data
  attr_accessor :value_format

  def initialize(wavetype,steps)
    self.wavetype = wavetype
    self.steps = steps.to_i
    self.maximum_value = 0xFFFF
    self.value_format = "0x%X"
  end

  def generate!
    if respond_to? generator_method_name
      send generator_method_name
      print_data
    else
      usage
    end
  end

  def usage
    puts <<-EOS

  Usage:

    #{$0} <wavetype> <steps>

  Where <wavetype> is one of: triangle, sawtooth, sine, hump

    EOS
  end

  def generator_method_name
    "generate_#{wavetype}"
  end

  def title
    "#{wavetype} wave, one cycle in #{steps} data points"
  end

  def wave_key
    "#{wavetype.upcase}_WAVE"
  end

  def generate_triangle
    self.data = steps.times.each_with_object([]) do |step,memo|
      memo << (maximum_value * ((2.0 * step / steps) % 2.0 - 1.0).abs).to_i
    end
  end

  def generate_sawtooth
    self.data = steps.times.each_with_object([]) do |step,memo|
      memo << (maximum_value * ((1.0 * step / steps) % 1.0).abs).to_i
    end
  end

  def generate_sine
    self.data = steps.times.each_with_object([]) do |step,memo|
      memo << ( maximum_value * ( 0.5 * Math.sin(20.0 * step / steps / Math::PI) + 0.5)).to_i
    end
  end

  def generate_hump # i.e. rectified sinusoid
    self.data = steps.times.each_with_object([]) do |step,memo|
      memo << ( maximum_value * ( Math.sin(20.0 * step / steps / Math::PI)).abs).to_i
    end
  end

  def print_data
    puts "// #{title}"
    puts "// generated with: ./wavetable_generator.rb #{wavetype} #{steps}"
    puts "#define #{wave_key}_SIZE #{steps}"
    puts "const unsigned int #{wave_key}_TABLE[#{wave_key}_SIZE] PROGMEM = {"
    data.each do |value|
      puts "    #{sprintf(value_format,value)},"
    end
    puts "};"
  end

end

wavetype,steps = ARGV
wave_generator = WaveGenerator.new(wavetype,steps).generate!

