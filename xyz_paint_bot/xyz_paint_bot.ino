#include <Stepper.h>
 
//Stepper ZStepper(100, 11, 12, 10, 13);
Stepper YStepper(100, 6, 8, 7, 9);
Stepper XStepper(100, 2, 3, 4, 5);

int CurrentX = 0;
int CurrentY = 0;
int CurrentZ = 0;

int xStep,yStep,zStep = 0;

float DeltaX,DeltaY,DeltaZ,DeltaXDelay,DeltaYDelay,DeltaZDelay,DeltaXCounter,DeltaYCounter,DeltaZCounter = 0;

int readCommand,readXPos,readYPos,readZPos;

int DataRead = 0;

void setup()
{
  Serial.begin(115200);
  Serial.setTimeout(50);  
  
//  ZStepper.setSpeed(100);
  YStepper.setSpeed(200);
  XStepper.setSpeed(200);
}

void loop()
{
 if (Serial.available()) {
    DataRead=1;
    readCommand = Serial.parseInt();
    readXPos=CurrentX;
    readYPos=CurrentY;
    readZPos=CurrentZ;
    
    if (Serial.available()) { DataRead++; readXPos = Serial.parseInt()-10000; }
    if (Serial.available()) { DataRead++; readYPos = Serial.parseInt()-10000; }
    if (Serial.available()) { DataRead++; readZPos = Serial.parseInt()-10000; }

//    Serial.print(" c:");
//    Serial.print(readCommand);
//    Serial.print("- ");

    if (DataRead!=4)
    {
      Serial.println("X");
    } else
    {
      if (readCommand==1)
      {
        /*
       Serial.print(readCommand);
       Serial.print(" ");
       Serial.print(readXPos);
       Serial.print(" ");
       Serial.print(readYPos);
       Serial.print(" ");
       Serial.println(readZPos);
      */
       MoveToX(readXPos,readYPos,readZPos);
      } else
      if (readCommand==2)
      {
//        ZStepper.setSpeed(readZPos);
        YStepper.setSpeed(readYPos);
        XStepper.setSpeed(readXPos);
      } else
      if (readCommand==3)
      {
        CurrentZ = readZPos;
        CurrentY = readYPos;
        CurrentX = readXPos;
      }
     Serial.println("Z");
     while( Serial.read() != -1 );
    }
  }
  
   
/*  
 MoveToX(0,0,-50);
 MoveToX(100,100,-50);
 MoveToX(200,100,-50);
 MoveToX(200,150,-50);
 MoveToX(500,100,-50);
 MoveToX(500,100,0);
 MoveToX(700,500,0);
 MoveToX(700,500,-50);
 MoveToX(300,400,-50);
 MoveToX(250,550,-50);
 MoveToX(150,400,-50);
 MoveToX(100,300,-50);
 MoveToX(50,200,-50);
 MoveToX(0,100,-50);
 MoveToX(0,0,-50);
 MoveToX(0,0,0);
 */
}

void MoveToX(int NewX, int NewY, int NewZ)
{
  //0,0042 cm resolution of one step
  //0.00165 inch for each step == 600dpi
/*  
  Serial.print("START XYZ: ");
  Serial.print(CurrentX);
  Serial.print(" ");
  Serial.print(CurrentY);
  Serial.print(" ");
  Serial.println(CurrentZ);
  
  Serial.print("TARGET XYZ: ");
  Serial.print(NewX);
  Serial.print(" ");
  Serial.print(NewY);
  Serial.print(" ");
  Serial.println(NewZ);
*/  

  if (NewX==CurrentX) {xStep = 0; } else
  if (NewX<CurrentX) {xStep=-1; DeltaX = CurrentX-NewX;} else {xStep=1; DeltaX = NewX-CurrentX; }
  
  if (NewY==CurrentY) {yStep = 0; } else
  if (NewY<CurrentY) {yStep=-1; DeltaY = CurrentY-NewY;} else {yStep=1; DeltaY = NewY-CurrentY; }

//  if (NewZ==CurrentZ) {zStep = 0; } else
//  if (NewZ<CurrentZ) {zStep=-1; DeltaZ = CurrentZ-NewZ;} else {zStep=1; DeltaZ = NewZ-CurrentZ; }
  

  DeltaXDelay = 1;
  DeltaYDelay = 1;
  DeltaZDelay = 1;

  DeltaXCounter = 0;
  DeltaYCounter = 0;
  DeltaZCounter = 0;
  
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
/*  
    Serial.print("DeltaX: ");
    Serial.println(DeltaXDelay);
  
    Serial.print("DeltaY: ");
    Serial.println(DeltaYDelay);
*/  
  while ((CurrentX!=NewX) or (CurrentY!=NewY)) // or (CurrentZ!=NewZ))
  {
    DeltaXCounter++;
    DeltaYCounter++;
//    DeltaZCounter++;
/*    
    Serial.print("Delta X: ");
    Serial.print(DeltaXCounter);
    Serial.print(" --> ");
    Serial.print(DeltaXDelay);
    Serial.print(" !!!! Delta Y: ");

    Serial.print(DeltaYCounter);
    Serial.print(" --> ");
    Serial.print(DeltaYDelay);
    Serial.println();
  */  
    
    if ((CurrentX!=NewX) && (DeltaXCounter>=DeltaXDelay)) { CurrentX = CurrentX + xStep; XStepper.step(xStep); DeltaXCounter=DeltaXCounter-DeltaXDelay; }
    if ((CurrentY!=NewY) && (DeltaYCounter>=DeltaYDelay)) { CurrentY = CurrentY + yStep; YStepper.step(yStep); DeltaYCounter=DeltaYCounter-DeltaYDelay; }

//    if ((CurrentZ!=NewZ)) { CurrentZ = CurrentZ + zStep; ZStepper.step(zStep); DeltaZCounter=0; }
/*   
    Serial.print("X: ");
    Serial.print(CurrentX);
    Serial.print(" --> ");
    Serial.print(NewX);
    Serial.print(" !!!! Y: ");

    Serial.print(CurrentY);
    Serial.print(" --> ");
    Serial.print(NewY);
    Serial.println();
    */
/*
    Serial.print(CurrentZ);
    Serial.print(" ");
    Serial.print(NewZ);
    Serial.println();
    */
  }
}

