#include <AFMotor.h>
#include <Servo.h> 

Servo servoX;
Servo servoY;

const int ldrLeft   = A0;
const int ldrRight  = A1;
const int ldrTop    = A2;
const int ldrBottom = A3;

int posX = 0;
int posY = 0;

const int targetRange = 120;
const int yTargetRange = 120;
const int xTargetRange = 120;
const int yTimeout = 20;
const int xTimeout = 100;

const int yIncrement = 2;
const int xIncrement = 3;

const int threshold = 50;
// apag aphemerus

void setup() {
  servoX.attach(9);
  servoY.attach(10);

  servoX.write(posX);
  servoY.write(posY);

  Serial.begin(9600);
}

void loop() {
   // Read LDRs
  int leftVal   = analogRead(ldrLeft);
  int rightVal  = analogRead(ldrRight);
  int topVal    = analogRead(ldrTop);
  int bottomVal = analogRead(ldrBottom);

  // Differences
  int diffX = leftVal - rightVal;
  int diffY = topVal - bottomVal;

  // LDR tracking
  if (diffX > threshold && posX < 180) posX++;       // move left
  else if (diffX < -threshold && posX > 0) posX--;  // move right

  if (diffY > threshold && posY < 180) posY++;       // move up
  else if (diffY < -threshold && posY > 0) posY--;  // move down

  // Write positions
  servoX.write(posX);
  servoY.write(posY);

  // Debug
  Serial.print("LDR Left: "); Serial.print(leftVal);
  Serial.print(" | Right: "); Serial.print(rightVal);
  Serial.print(" | Top: "); Serial.print(topVal);
  Serial.print(" | Bottom: "); Serial.print(bottomVal);
  Serial.print(" | ServoX: "); Serial.print(posX);
  Serial.print(" | ServoY: "); Serial.println(posY);
  
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