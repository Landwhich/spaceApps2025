#include <AFMotor.h>
#include <Servo.h> 

Servo servoX;
Servo servoY;

int pos = 0;
int targetRange = 180;
int timeout = 2;

void setup() {
  servoX.attach(10);
  servoY.attach(9);
}

void loop() {
  servoSweep();
}

void servoSweep(){
  xSweep();
  ySweep();
}

void xSweep(){
  for (pos = 0; pos <= targetRange; pos += 1) { 
    servoX.write(pos);              
    delay(timeout);                        
  }

  for (pos = targetRange; pos >= 0; pos -= 1) { 
    servoX.write(pos);              
    delay(timeout);                       
  }
}

void ySweep(){
  for (pos = 0; pos <= targetRange; pos += 1) { 
    servoY.write(pos);              
    delay(timeout);                        
  }

  for (pos = targetRange; pos >= 0; pos -= 1) { 
    servoY.write(pos);              
    delay(timeout);                       
  }
}

