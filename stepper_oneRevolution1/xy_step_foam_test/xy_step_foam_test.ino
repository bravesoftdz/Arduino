
/* 
 Stepper Motor Control - one revolution
 
 This program drives a unipolar or bipolar stepper motor. 
 The motor is attached to digital pins 8 - 11 of the Arduino.
 
 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.  
 
  
 Created 11 Mar. 2007
 Modified 30 Nov. 2009
 by Tom Igoe
 
 */

#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
                                     // for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper1(stepsPerRevolution, 2,3,4,5);            
Stepper myStepper2(stepsPerRevolution, 6,8,7,9);            

void setup() {
  myStepper1.setSpeed(60);
  myStepper2.setSpeed(60);

  Serial.begin(9600);
}

void loop() {

  Serial.println("clockwise");
  myStepper1.step(200);
  myStepper2.step(200);
  myStepper1.step(200);
  myStepper2.step(200);
  delay(500);
  
  Serial.println("counterclockwise");
  myStepper1.step(-200);
  myStepper2.step(-200);
  myStepper1.step(-200);
  myStepper2.step(-200);
  delay(500); 
}

