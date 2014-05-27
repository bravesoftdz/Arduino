int E1 = 5;     //M1 Speed Control PWM
int E2 = 6;     //M2 Speed Control PWM
int M1 = 4;    //M1 Direction Control
int M2 = 7;    //M1 Direction Control

int LifeCounter = 0;
int EachRun = 100;
int SleepDelay = 5000;

boolean FollowPersonMode = false;
boolean ExploreMode = false;

#define speed 250

void stop(void)                    //Stop
{
  digitalWrite(E1,LOW);   
  digitalWrite(E2,LOW);      
}   
void advance(char a,char b)          //Move forward
{
  //turn_L (0,b);
  //delay(20);
  //turn_R (a,0);
  digitalWrite(M1,HIGH); 
  digitalWrite(M2,HIGH);
  analogWrite (E1,a);  
  analogWrite (E2,b);

}  
void back_off (char a,char b)          //Move backward
{ 
  digitalWrite(M1,LOW); 
  digitalWrite(M2,LOW);
  analogWrite (E1,a);  
  analogWrite (E2,b);   
}
void turn_L (char a,char b)             //Turn Left
{
  digitalWrite(M1,LOW);
  digitalWrite(M2,HIGH);
  analogWrite (E1,a);    
  analogWrite (E2,b);    

}
void turn_R (char a,char b)             //Turn Right
{   
  
  digitalWrite(M1,HIGH); 
  digitalWrite(M2,LOW);
  analogWrite (E1,a);   
  analogWrite (E2,b); 
}
void setup(void) 
{ 

  pinMode(E1, OUTPUT); 
  pinMode(E2, OUTPUT); 
  pinMode(M1, OUTPUT); 
  pinMode(M2, OUTPUT);  
  Serial.begin(19200);      //Set Baud Rate

} 
void loop(void) 
{ 
  char val = Serial.read();
  int LeftSensor = digitalRead(9);
  int RightSensor = digitalRead(8);  
  
/*  Serial.print( "left sensor: ");
  Serial.println(LeftSensor );
  Serial.print( "right sensor: ");
  Serial.println( RightSensor ) ;
*/

  if (FollowPersonMode)
  {
        if ( (LeftSensor==1) && (RightSensor==1) )  //do nothing
        {
        }
      
        if ( (LeftSensor==0) && (RightSensor==0) )  //do nothing
        {
          advance (speed,speed);
          delay(1000);
        }
        
        if ( (LeftSensor==0) && (RightSensor==1) )  //left side obstacle detected
        {
          turn_L (speed,speed);
          delay(500);
        }
        
        
        if ( (LeftSensor==1) && (RightSensor==0) )  //right  side obstacle detected
        {
          turn_R (speed,speed);
          delay(500);
        }
  }
  
  if (ExploreMode)
  {
        if (LifeCounter>=EachRun)
        {
          LifeCounter=0;
          delay(SleepDelay);
        }
        if ( (LeftSensor==1) && (RightSensor==1) )  //clear move forward
        {
          advance (speed,speed);
          LifeCounter++;
          delay(40);
        }
        
        if ( (LeftSensor==0) && (RightSensor==0) )  //totally blocked
        {
          back_off (speed,speed);
          LifeCounter++;
          delay(1000);
        }
        
        if ( (LeftSensor==0) && (RightSensor==1) )  //left side obstacle detected
        {
          turn_R (speed,speed);
          LifeCounter++;
          delay(2000);
        }
        
        if ( (LeftSensor==1) && (RightSensor==0) )  //right  side obstacle detected
        {
          turn_L (speed,speed);
          LifeCounter++;
          delay(2000);
        }
  }

  if(val!=-1)
  {
    switch(val)
    {
      Serial.println(val);
    case 'w':
      back_off (speed,speed);
      break;
      
    case 's':
      advance (speed,speed); //this is not working
      break;
      
    case 'd':
      turn_L (speed,speed);
      break;    
      
    case 'a':
      turn_R (speed,speed);
      break;          
    
    
    case '1':
      stop();
      break;          
    }
    delay(40); 
  }
  
  
  
}
