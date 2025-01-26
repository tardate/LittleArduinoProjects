/*

 Graph ASCII-encoded strings read from the serial port at 9600 baud.
 It expects a list of 1 or more comma-separated values in the range 0 to 1023, followed by a newline, or newline and carriage return.
 It will plot each series in its own chart area (stacked vertically).

*/

import processing.serial.*;

// set the serial port name to read data from. You might well need to change this..!
String port_name = "/dev/tty.usbmodem14541";

Serial port;               // The serial port
int x_value = 1;           // horizontal position of the graph
int value_max = 1023;      // max value expected; used to scale readings

int vertical_border = 20;  // vertical border to leave between traces
int background_color = 31; // default background color (just off black)

void setup () {
  size(1000, 600);               // set the window size
  colorMode(HSB);                // use hue/saturation/brightness to set colors
  background(background_color);  // set inital background color

  println(Serial.list());        // List all the available serial ports

  // initialise the serial port (to match that used by PlotNValues.ino)
  port = new Serial(this, port_name, 115200);
  // set it to raise serialEvent on a newline
  port.bufferUntil('\n');

}

void draw () {
  // everything happens in the serialEvent()
}

// plot data series n with values (x,y) in a viewport up to height_per_value high
void plotValue (int n, int x, float y, int height_per_value) {
    // transform to y-axis value
    float y_value = map(y, 0, value_max, 0, height_per_value - vertical_border * 2);

    // transform color based on y-axis value
    float hue_value = map(y, 0, value_max, 128, 255);
    float saturation_value = map(y, 0, value_max, 128, 255);
    float brightness_value = 255;

    // max y value
    int y_max = height - (n * height_per_value);

    println("value: " + n + ", " + y + " => " + y_value + ", hue: " + hue_value + ", sat: " + saturation_value);

    // draw the line
    stroke(hue_value,saturation_value,brightness_value);
    line(x, y_max - vertical_border, x, y_max - y_value - vertical_border);

}

void serialEvent (Serial myPort) {
  float[] values;

  // try to read an incoming value
  try {
    String[] value_strings = split(port.readStringUntil('\n'), ',');
    values = new float[value_strings.length];
    for (int i = 0; i < value_strings.length; i++) {
      values[i] = float(trim(value_strings[i]));
    }
  } catch (Exception e) {
    println("Unreadable input");
    values = new float[0];
  }

  if (values.length > 0) {
    int height_per_value = height / values.length;

    for (int n = 0; n < values.length; n++) {
      plotValue (n, x_value, values[n], height_per_value);
    }

    // increment or wrap the x position
    if (x_value >= width) {
      x_value = 0;
      background(background_color);
    } else {
      x_value++;
    }
  }

}



