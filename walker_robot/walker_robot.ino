// Controlling a servo position using a potentiometer (variable resistor) 
// by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

#include <Servo.h> 
 
Servo BackRight;
Servo FrontRight;
Servo BackLeft;
Servo FrontLeft;

Servo BalRight;
Servo BalLeft;

int counter; 
int pos;

int BackRightNeutral,FrontRightNeutral,BackLeftNeutral,FrontLeftNeutral,BalLeftNeutral,BalRightNeutral;

int BackRightPos,FrontRightPos,BackLeftPos,FrontLeftPos,BalLeftPos,BalRightPos;

boolean BackRightOpenInc,FrontRightOpenInc,BackLeftOpenInc,FrontLeftOpenInc,BalLeftOpenInc,BalRightOpenInc;

int TargetPos,LegMoveLength,BalMoveLength,MoveDelay;

int FrontRightServo,FrontLeftServo,BackRightServo,BackLeftServo,BalLeftServo,BalRightServo;

void setup() 
{ 
  counter = 0;
  LegMoveLength = 30;
  BalMoveLength = 70;
  MoveDelay = 8;

  FrontRightServo = 4;  
  FrontLeftServo = 5;
  BackRightServo = 6;
  BackLeftServo = 7;
  BalRightServo = 9;
  BalLeftServo = 8;
  
  FrontRight.attach(FrontRightServo); 
  FrontLeft.attach(FrontLeftServo); 
  
  
  BackRight.attach(BackRightServo);
  BackLeft.attach(BackLeftServo);

  BalRight.attach(BalRightServo);
  BalLeft.attach(BalLeftServo);

  //home position



  BackRightNeutral = 100;
  BackRight.write(BackRightNeutral); //higher is outwards
  BackRightPos = 100;
  BackRightOpenInc = true;
 
  BackLeftNeutral = 80;
  BackLeft.write(BackLeftNeutral); // lower is outwards
  BackLeftPos = 80;
  BackLeftOpenInc = false;


  FrontRightNeutral = 80;
  FrontRight.write(FrontRightNeutral); //lower is outwards
  FrontRightPos = 80;
  FrontRightOpenInc = false;

  FrontLeftNeutral = 100;
  FrontLeft.write(FrontLeftNeutral); // higher is outwards
  FrontLeftPos = 100;
  FrontLeftOpenInc = true;


  BalRightNeutral = 60;
  BalRight.write(BalRightNeutral); // higher is forwards
  BalRightPos = 60;
  BalRightOpenInc = true;
  
  BalLeftNeutral = 106;
  BalLeft.write(BalLeftNeutral); // lower is forwards
  BalLeftPos = 106;
  BalLeftOpenInc = false;

  delay(1000);
  BalLeft.detach(); 
  BalRight.detach(); 

  FrontRight.detach();
  FrontLeft.detach();
  
  BackRight.detach();
  BackLeft.detach();
} 


//-------------------------------------------------------------------------------------------------------------------------------------------
void FrontRightMove(char XAction[15])
{
  FrontRight.attach(FrontRightServo);
  
  if (XAction=="neutral") {
    while (FrontRightPos!=FrontRightNeutral)
    {
      if (FrontRightPos>FrontRightNeutral) { FrontRightPos--; } else
      if (FrontRightPos<FrontRightNeutral) { FrontRightPos++; }
      FrontRight.write(FrontRightPos);
      delay(MoveDelay);
    }
  } else
  {
    TargetPos = FrontRightNeutral;
    if (XAction=="forward")  {
      if (FrontRightOpenInc) { TargetPos = FrontRightNeutral+LegMoveLength; }
      if (!FrontRightOpenInc) { TargetPos = FrontRightNeutral-LegMoveLength; }
    }
    if (XAction=="backward")  {
      if (FrontRightOpenInc) { TargetPos = FrontRightNeutral-LegMoveLength; }
      if (!FrontRightOpenInc) { TargetPos = FrontRightNeutral+LegMoveLength; }
    }
  
    while (FrontRightPos!=TargetPos)
    {
      if (FrontRightPos>TargetPos) { FrontRightPos--; } else
      if (FrontRightPos<TargetPos) { FrontRightPos++; }
      FrontRight.write(FrontRightPos);
      delay(MoveDelay);
    }
  }
  
  FrontRight.detach();
}

//-------------------------------------------------------------------------------------------------------------------------------------------
void FrontLeftMove(char XAction[15])
{
  FrontLeft.attach(FrontLeftServo);
  
  if (XAction=="neutral") {
    while (FrontLeftPos!=FrontLeftNeutral)
    {
      if (FrontLeftPos>FrontLeftNeutral) { FrontLeftPos--; } else
      if (FrontLeftPos<FrontLeftNeutral) { FrontLeftPos++; }
      FrontLeft.write(FrontLeftPos);
      delay(MoveDelay);
    }
  } else
  {
    TargetPos = FrontLeftNeutral;
    if (XAction=="forward")  {
      if (FrontLeftOpenInc) { TargetPos = FrontLeftNeutral+LegMoveLength; }
      if (!FrontLeftOpenInc) { TargetPos = FrontLeftNeutral-LegMoveLength; }
    }
    if (XAction=="backward")  {
      if (FrontLeftOpenInc) { TargetPos = FrontLeftNeutral-LegMoveLength; }
      if (!FrontLeftOpenInc) { TargetPos = FrontLeftNeutral+LegMoveLength; }
    }
  
    while (FrontLeftPos!=TargetPos)
    {
      if (FrontLeftPos>TargetPos) { FrontLeftPos--; } else
      if (FrontLeftPos<TargetPos) { FrontLeftPos++; }
      FrontLeft.write(FrontLeftPos);
      delay(MoveDelay);
    }
  }
  
  FrontLeft.detach();
}

//-------------------------------------------------------------------------------------------------------------------------------------------
void BackRightMove(char XAction[15])
{
  BackRight.attach(BackRightServo);
  
  if (XAction=="neutral") {
    while (BackRightPos!=BackRightNeutral)
    {
      if (BackRightPos>BackRightNeutral) { BackRightPos--; } else
      if (BackRightPos<BackRightNeutral) { BackRightPos++; }
      BackRight.write(BackRightPos);
      delay(MoveDelay);
    }
  } else
  {
    TargetPos = BackRightNeutral;
    if (XAction=="forward")  {
      if (BackRightOpenInc) { TargetPos = BackRightNeutral+LegMoveLength; }
      if (!BackRightOpenInc) { TargetPos = BackRightNeutral-LegMoveLength; }
    }
    if (XAction=="backward")  {
      if (BackRightOpenInc) { TargetPos = BackRightNeutral-LegMoveLength; }
      if (!BackRightOpenInc) { TargetPos = BackRightNeutral+LegMoveLength; }
    }
  
    while (BackRightPos!=TargetPos)
    {
      if (BackRightPos>TargetPos) { BackRightPos--; } else
      if (BackRightPos<TargetPos) { BackRightPos++; }
      BackRight.write(BackRightPos);
      delay(MoveDelay);
    }
  }
  
  BackRight.detach();
}

//-------------------------------------------------------------------------------------------------------------------------------------------
void BackLeftMove(char XAction[15])
{
  BackLeft.attach(BackLeftServo);
  
  if (XAction=="neutral") {
    while (BackLeftPos!=BackLeftNeutral)
    {
      if (BackLeftPos>BackLeftNeutral) { BackLeftPos--; } else
      if (BackLeftPos<BackLeftNeutral) { BackLeftPos++; }
      BackLeft.write(BackLeftPos);
      delay(MoveDelay);
    }
  } else
  {
    TargetPos = BackLeftNeutral;
    if (XAction=="forward")  {
      if (BackLeftOpenInc) { TargetPos = BackLeftNeutral+LegMoveLength; }
      if (!BackLeftOpenInc) { TargetPos = BackLeftNeutral-LegMoveLength; }
    }
    if (XAction=="backward")  {
      if (BackLeftOpenInc) { TargetPos = BackLeftNeutral-LegMoveLength; }
      if (!BackLeftOpenInc) { TargetPos = BackLeftNeutral+LegMoveLength; }
    }
  
    while (BackLeftPos!=TargetPos)
    {
      if (BackLeftPos>TargetPos) { BackLeftPos--; } else
      if (BackLeftPos<TargetPos) { BackLeftPos++; }
      BackLeft.write(BackLeftPos);
      delay(MoveDelay);
    }
  }
  
  BackLeft.detach();
}

//-------------------------------------------------------------------------------------------------------------------------------------------
void BalRightMove(char XAction[15])
{
  BalRight.attach(BalRightServo);
  
  if (XAction=="neutral") {
    while (BalRightPos!=BalRightNeutral)
    {
      if (BalRightPos>BalRightNeutral) { BalRightPos--; } else
      if (BalRightPos<BalRightNeutral) { BalRightPos++; }
      BalRight.write(BalRightPos);
      delay(MoveDelay);
    }
  } else
  {
    TargetPos = BalRightNeutral;
    if (XAction=="forward")  {
      if (BalRightOpenInc) { TargetPos = BalRightNeutral+BalMoveLength; }
      if (!BalRightOpenInc) { TargetPos = BalRightNeutral-BalMoveLength; }
    }
    if (XAction=="backward")  {
      if (BalRightOpenInc) { TargetPos = BalRightNeutral-BalMoveLength; }
      if (!BalRightOpenInc) { TargetPos = BalRightNeutral+BalMoveLength; }
    }
  
    while (BalRightPos!=TargetPos)
    {
      if (BalRightPos>TargetPos) { BalRightPos--; } else
      if (BalRightPos<TargetPos) { BalRightPos++; }
      BalRight.write(BalRightPos);
      delay(MoveDelay);
    }
  }
  
  BalRight.detach();
}

//-------------------------------------------------------------------------------------------------------------------------------------------
void BalLeftMove(char XAction[15])
{
  BalLeft.attach(BalLeftServo);
  
  if (XAction=="neutral") {
    while (BalLeftPos!=BalLeftNeutral)
    {
      if (BalLeftPos>BalLeftNeutral) { BalLeftPos--; } else
      if (BalLeftPos<BalLeftNeutral) { BalLeftPos++; }
      BalLeft.write(BalLeftPos);
      delay(MoveDelay);
    }
  } else
  {
    TargetPos = BalLeftNeutral;
    if (XAction=="forward")  {
      if (BalLeftOpenInc) { TargetPos = BalLeftNeutral+BalMoveLength; }
      if (!BalLeftOpenInc) { TargetPos = BalLeftNeutral-BalMoveLength; }
    }
    if (XAction=="backward")  {
      if (BalLeftOpenInc) { TargetPos = BalLeftNeutral-BalMoveLength; }
      if (!BalLeftOpenInc) { TargetPos = BalLeftNeutral+BalMoveLength; }
    }
  
    while (BalLeftPos!=TargetPos)
    {
      if (BalLeftPos>TargetPos) { BalLeftPos--; } else
      if (BalLeftPos<TargetPos) { BalLeftPos++; }
      BalLeft.write(BalLeftPos);
      delay(MoveDelay);
    }
  }
  
  BalLeft.detach();
}

 
void loop() 
{ 
  counter++;
  if (counter<=4)
  {
    /*
    FrontRightMove("neutral");
    FrontRightMove("forward");
    FrontRightMove("backward");
    */
    
    FrontRightMove("forward"); delay(500);
    BalRightMove("forward"); delay(500);    
    BackLeftMove("backward"); delay(500);
    
    FrontRightMove("neutral"); delay(500);
    BackLeftMove("neutral"); delay(500);
    BalRightMove("neutral"); delay(500);    

    FrontLeftMove("forward"); delay(500);
    BalLeftMove("forward"); delay(500);    
    BackRightMove("backward"); delay(500);
    
    FrontLeftMove("neutral"); delay(500);
    BackRightMove("neutral"); delay(500);
    BalLeftMove("neutral"); delay(500);    
    
    
/*    
  //move front right forward
  for (pos = FrontRightNeutral; pos > 50; pos -= 1) { FrontRight.write(pos);  delay(5); } delay(250);
  
  //move right bal forward
  for(pos = BalRightNeutral; pos < 140; pos += 1) { BalRight.write(pos);  delay(5); } delay(250);


  //move front left forward
  for (pos = FrontLeftNeutral; pos < 120; pos += 1) { FrontLeft.write(pos);  delay(5); } delay(250);
  
  BalLeft.attach(8); 
  for(pos = BalLeftNeutral; pos > 40; pos -= 1) { BalLeft.write(pos);  delay(5); } delay(250);
  BalLeft.detach();   
  
  //move front right normal
  for(pos = 50; pos < FrontRightNeutral; pos += 1) { FrontRight.write(pos);  delay(5); } delay(250);

  //move front left forward
  for (pos = 120; pos > FrontLeftNeutral; pos -= 1) { FrontLeft.write(pos);  delay(5); } delay(250);

  //move right bal normal
  for(pos = 140; pos > BalRightNeutral; pos -= 1) { BalRight.write(pos);  delay(5); } delay(250);

  BalLeft.attach(8); 
  for(pos = 40; pos < BalLeftNeutral; pos += 1) { BalLeft.write(pos);  delay(5); } delay(250); 
  BalLeft.detach();   
*/    
/*  
  //move back right forward
  BackRight.write(60);
  delay(250);
  
  //move back left forward
  BackLeft.write(120);
  delay(250);
  
  //--------------
  
  //move front right backward
  FrontRight.write(70);
  delay(250);
  
  //move front left backward
  FrontLeft.write(80);
  delay(250);
  

  // ------------- Back to home position
  //--------------
  
  //move back right back
  BackRight.write(40);
  delay(250);
  
  //move back left back
  BackLeft.write(90);
  delay(250);

  //--------------
  
  //move front right forward
  FrontRight.write(90);
  delay(250);
  
  //move front left forward
  FrontLeft.write(60);
  delay(250);
  
  */
  
  }  
  delay(25);
  
} 
