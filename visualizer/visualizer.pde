import processing.serial.*;
import cc.arduino.*;

Arduino arduino;

//float xAxis[][] = new float[60][2];
//float yAxis[][] = new float[60][2];
boolean ready = false;
Serial myPort;

color off = color(4, 79, 111);
color on = color(84, 145, 158);
int sensorValue = 0;

void setup() {
  size(480,480); // 60 degrees on y (every 2), and 60 on x (every 3) 
  println(Serial.list());
  myPort = new Serial(this, Serial.list()[0], 9600);
  myPort.bufferUntil('\n'); // read full lines

  //println(Arduino.list());
  //arduino = new Arduino(this, Arduino.list()[0], 57600);
  //OR DO THIS arduino = new Arduino(this, "/dev/tty.usbmodem621", 57600);
}

void draw() {
  background(0,0,0);
  
  fill(map(sensorValue, 0, 1023, 0, 255));
  rect(0, 0, width, height);
}

void serialEvent(Serial p) {
  String line = trim(p.readStringUntil('\n'));
  if (line == null || line.length() == 0) return;

  try {
    sensorValue = int(line);
    ready = true;
  } catch(Exception e) {
    println("Bad data: " + line);
  }
}
