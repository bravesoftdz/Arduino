/* YourDuino.com Example Software Sketch
   Small Stepper Motor and Driver
   http://arduino-direct.com/sunshop/index.php?l=product_detail&p=126
   terry@yourduino.com */

#include <Stepper.h>
#include <Servo.h> 
 
Servo PenHolder;
int PenPos = 90;

Stepper XStepper(100, 9, 10, 8, 11);
Stepper YStepper(100, 5, 7, 6, 4);

int CurrentX = 0;
int CurrentY = 0;

int xStep,yStep = 0;

int DeltaX,DeltaY,DeltaXDelay,DeltaYDelay,DeltaXCounter,DeltaYCounter = 0;

void setup()
{
  Serial.begin(115200);
  
  PenHolder.attach(2);
  PenHolder.write(PenPos);
  XStepper.setSpeed(100);
  YStepper.setSpeed(200);
}

void loop()
{
  for(int i = 90; i > 71; i -= 1) { PenHolder.write(i); delay(25); } 


 MoveToX(0,0);
 MoveToX(100,1000);
 MoveToX(0,1000);
 MoveToX(100,0);
 MoveToX(50,0);
  
/*
  for (int i=0; i<1000; i++)
  {
   small_stepper.step(1);
  
   small_stepper2.step(1);
  }
  for(int i = 71; i < 90; i += 1) { PenHolder.write(i); delay(25); } 
  
  for (int i=0; i<1000; i++)
  {
   small_stepper.step(-1);
   small_stepper2.step(-1);
  }
*/
}

void MoveToX(int NewX, int NewY)
{
  //0,0042 cm resolution of one step
  //0.00165 inch for each step == 600dpi
  
  Serial.print("START XY: ");
  Serial.print(CurrentX);
  Serial.print(" ");
  Serial.println(CurrentY);
  
  Serial.print("TARGET XY: ");
  Serial.print(NewX);
  Serial.print(" ");
  Serial.println(NewY);
  

  if (NewX==CurrentX) {xStep = 0; } else
  if (NewX<CurrentX) {xStep=-1; DeltaX = CurrentX-NewX;} else {xStep=1; DeltaX = NewX-CurrentX; }
  
  if (NewY==CurrentY) {yStep = 0; } else
  if (NewY<CurrentY) {yStep=-1; DeltaY = CurrentY-NewY;} else {yStep=1; DeltaY = NewY-CurrentY; }

  DeltaXDelay = 1;
  DeltaYDelay = 1;
  
  if (DeltaX>DeltaY) 
  {
    DeltaYDelay = DeltaX / DeltaY;
    DeltaXDelay = 1;
  }
  
  if (DeltaY>DeltaX) 
  {
    DeltaXDelay = DeltaY / DeltaX;
    DeltaYDelay = 1;
  }
  
  
  while ((CurrentX!=NewX) or (CurrentY!=NewY))
  {
    DeltaXCounter++;
    DeltaYCounter++;
    
    if ((CurrentX!=NewX) && (DeltaXCounter>=DeltaXDelay)) { CurrentX = CurrentX + xStep; XStepper.step(xStep); DeltaXCounter=0; }
    if ((CurrentY!=NewY) && (DeltaYCounter>=DeltaYDelay)) { CurrentY = CurrentY + yStep; YStepper.step(yStep); DeltaYCounter=0; }
  }
  
  Serial.print("END XY: ");
  Serial.print(CurrentX);
  Serial.print(" ");
  Serial.println(CurrentY);
  
}

