#include <AFMotor.h>
#include <Servo.h> 

Servo servoX;
Servo servoY;

int posX = 0;
int posY = 0;
const int targetRange = 120;
const int yTargetRange = 120;
const int xTargetRange = 120;

const int yTimeout = 20;
const int xTimeout = 100;

const int yIncrement = 2;
const int xIncrement = 3;

// apag aphemerus

void setup() {
  servoX.attach(9);
  servoY.attach(10);
}

void loop() {
  servoSweep();
}

void servoSweep(){
  xSweep();
  ySweep();
}

void xSweep(){
  for (posX = 0; posX <= targetRange; posX += xIncrement) { 
    servoX.write(posX);
    delay(xTimeout);                        
  }

  for (posX = targetRange; posX >= 0; posX -= 1) { 
    servoX.write(posX);          
  }
}

void ySweep(){
  for (posY = 0; posY <= targetRange; posY += yIncrement) { 
    servoY.write(posY);              
    delay(yTimeout);                        
  }
  for (posY = targetRange; posY >= 0; posY -= 1) { 
    servoY.write(posY);          
  }
}