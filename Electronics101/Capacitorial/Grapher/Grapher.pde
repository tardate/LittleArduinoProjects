/*

 Graph ASCII-encoded strings read from the serial port at 9600 baud.
 It expects values in the range 0 to 1023, followed by a newline, or newline and carriage return

*/

import processing.serial.*;

String port_name = "/dev/tty.usbmodem14541";

Serial port;        // The serial port
int x_value = 1;    // horizontal position of the graph

void setup () {
  size(800, 600);  // set the window size
  colorMode(HSB);
  background(0);   // set inital background color

  println(Serial.list()); // List all the available serial ports

  port = new Serial(this, port_name, 9600);
  port.bufferUntil('\n'); // raise serialEvent on a newline

}

void draw () {
  // everything happens in the serialEvent()
}

void serialEvent (Serial myPort) {
  String value_string;
  float value;
  
  // try to read an incoming value
  try {
    value_string = port.readStringUntil('\n');
    value = float(trim(value_string));
  } catch (Exception e) {
    println("Unreadable input");
    value = -1;
  }
  
  if (value >= 0) {
    // transform to y-axis value
    float y_value = map(value, 0, 1023, 0, height);
    float hue_value = map(value, 0, 1023, 255, 0);
    float saturation_value = map(value, 0, 1023, 200, 255);
    float brightness_value = 255;

    // draw the line:
    stroke(hue_value,saturation_value,brightness_value);
    line(x_value, height, x_value, height - y_value);

    // increment or wrap the x position
    if (x_value >= width) {
      x_value = 0;
      background(0);
    } else {
      x_value++;
    }
  }

}


