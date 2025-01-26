#! /usr/bin/env ruby
require 'pathname'

def file_path(name)
  Pathname.new(File.dirname(__FILE__)).join(name)
end

source_file_name = 'page_design.html'
c_file_name = 'index_page.h'

puts "Generating #{c_file_name} from #{source_file_name}..."

content = File.read(file_path(source_file_name))
content.gsub!('\\', '\\\\\\\\')  # quote backslashes
content.gsub!('"', '\"') # quote quotes
content.gsub!("\n", "\\n\\\n") # line end/continuations
content.gsub!(/Compiled.*<\/p>/, %(Compiled on " __DATE__ " at " __TIME__ "</p>)) # compilation replacements

File.open(file_path(c_file_name), 'w') do |f|
  f.write "// main web page content. Generated from #{source_file_name} at #{Time.now}\n"
  f.write %(char index_page[] = ")
  f.write content
  f.write %(";\n)
end

puts "...done!"
