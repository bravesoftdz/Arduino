#include <IRremote.h>
/* 
   http://www.righto.com/2009/08/multi-protocol-infrared-remote-library.html
 */

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

//Standard PWM DC control
int E1 = 5;     //M1 Speed Control
int E2 = 6;     //M2 Speed Control
int M1 = 4;    //M1 Direction Control
int M2 = 7;    //M1 Direction Control


int adc_key_in=0;
boolean TurnOn = false;


int LedPin = 9;
int LedBrightness = 0;
int LedDirection = 1;
int LedStep = 1;

int seqStep = 0;

boolean StartDelay  = false;
int DelayCounter = 0;
int TargetDelay = 0;

int TurnOnMode=1;


void stop(void)                    //Stop
{
  digitalWrite(E1,LOW);   
  digitalWrite(E2,LOW);      
}   

void advance(char a,char b)          //Move forward
{
  analogWrite (E1,a);      //PWM Speed Control
  digitalWrite(M1,HIGH);    
  analogWrite (E2,b);    
  digitalWrite(M2,HIGH);
}  

void back_off (char a,char b)          //Move backward
{
  analogWrite (E1,a);
  digitalWrite(M1,LOW);   
  analogWrite (E2,b);    
  digitalWrite(M2,LOW);
}

void turn_L (char a,char b)             //Turn Left
{
  analogWrite (E1,a);
  digitalWrite(M1,LOW);    
  analogWrite (E2,b);    
  digitalWrite(M2,HIGH);
}

void turn_R (char a,char b)             //Turn Right
{
  analogWrite (E1,a);
  digitalWrite(M1,HIGH);    
  analogWrite (E2,b);    
  digitalWrite(M2,LOW);
}

void setup(void) 
{ 
  int i;
  for(i=4;i<=7;i++)
  {
    pinMode(i, OUTPUT);  
  }
  
  irrecv.enableIRIn(); // Start the receiver
  
  Serial.begin(9600);
  Serial.println("Run keyboard control");
} 

void loop(void) 
{
  
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    Serial.println("------------");
    irrecv.resume(); // Receive the next value
    
    if (results.value==16769565) { TurnOn = true; TurnOnMode=1; }
    if (results.value==16736925) { TurnOn = true; TurnOnMode=2; }
    
    if (results.value==16753245) { TurnOn = false; stop();  }
   
    if (results.value==16724175) { TurnOn = false; advance(0,255); TargetDelay=10; StartDelay=true;  } //1
    if (results.value==16718055) { TurnOn = false; advance(255,255); TargetDelay=10; StartDelay=true; } //2
    if (results.value==16743045) { TurnOn = false; advance(255,0); TargetDelay=10; StartDelay=true; } //3
    if (results.value==16716015) { TurnOn = false; turn_L(255,255); TargetDelay=10; StartDelay=true; } //4
    if (results.value==16726215) {} //5
    if (results.value==16734885) { TurnOn = false; turn_R(255,255); TargetDelay=10; StartDelay=true; } //6
    if (results.value==16728765) { TurnOn = false; back_off(255,0); TargetDelay=10; StartDelay=true; } //7
    if (results.value==16730805) { TurnOn = false; back_off(255,255); TargetDelay=10; StartDelay=true;  } //8
    if (results.value==16732845) { TurnOn = false; back_off(0,255); TargetDelay=10; StartDelay=true;} //9
   
    if (results.value==4294967295) { DelayCounter=0; TargetDelay=10; StartDelay=true;} //9
  }

   adc_key_in = analogRead(7);  
   if (adc_key_in < 200) { TurnOn = true; }
   if ((adc_key_in > 300) && (adc_key_in < 400)) { TurnOn = false; stop();  }
   
  
//   Serial.println(seqStep);
//   Serial.println(StartDelay);
   
  if (StartDelay)
  {
    DelayCounter++;
    if (DelayCounter>TargetDelay) { StartDelay = false; DelayCounter=0; stop(); }
  }
  
  if (LedDirection == 1)
  {
    LedBrightness+=LedStep;
    if (LedBrightness>=180) { LedBrightness=180; LedDirection=2; }
    analogWrite(LedPin, LedBrightness);
  } else
  if (LedDirection == 2)
  {
    LedBrightness-=LedStep;
    if (LedBrightness<=0) { LedBrightness=0; LedDirection=1; }
    analogWrite(LedPin, LedBrightness);
  }
//  Serial.println(LedBrightness);
  
  if ( (TurnOn) && (!StartDelay) )
  {
   
    LedStep = 15;
    seqStep++;
    //Serial.println(seqStep);
    
    if (TurnOnMode==1)
    {
          if (seqStep==1)
          {
              advance(255,255);
              StartDelay = true;
              TargetDelay = 225;
          }
      
          if (seqStep==2)
          {
              stop();
              StartDelay = true;
              TargetDelay = 25;
          }
              
          if (seqStep==3)
          {
              back_off(255,255);
              StartDelay = true;
              TargetDelay = 100;
          }
              
          if (seqStep==4)
          {
              stop();
              StartDelay = true;
              TargetDelay = 25;
          }
      
          if (seqStep==5)
          {
              advance(255,255);
              StartDelay = true;
              TargetDelay = 90;
          }
      
          if (seqStep==6)
          {
              stop();
              StartDelay = true;
              TargetDelay = 25;
          }
             
            
          if (seqStep==7)
          {
              back_off(255,255);
              StartDelay = true;
              TargetDelay = 250;
          }
              
          if (seqStep>=8)
          {
              stop();
              StartDelay = true;
              TargetDelay = 25;
              seqStep=0;
          }
    } else
    if (TurnOnMode==2)
    {
          if (seqStep==1)
          {
              advance(255,255);
              StartDelay = true;
              TargetDelay = 105;
          }
      
          if (seqStep==2)
          {
              stop();
              StartDelay = true;
              TargetDelay = 35;
          }
              
          if (seqStep==3)
          {
              back_off(255,255);
              StartDelay = true;
              TargetDelay = 125;
          }
              
          if (seqStep==4)
          {
              stop();
              StartDelay = true;
              TargetDelay = 35;
              seqStep=0;
          }
    }
  } else
  
  if ((!TurnOn) && (!StartDelay))  
  {
      LedStep=1;
  }
  delay(10);
  
  /*   
   if(Serial.available()){
   char val = Serial.read();
   if(val != -1)
   {
   switch(val)
   {
   case 'w'://Move Forward
   advance (255,255);   //move forward in max speed
   break;
   case 's'://Move Backward
   back_off (255,255);   //move back in max speed
   break;
   case 'a'://Turn Left
   turn_L (100,100);
   break;       
   case 'd'://Turn Right
   turn_R (100,100);
   break;
   case 'z':
   Serial.println("Hello");
   break;
   case 'x':
   stop();
   break;
   }
   }
   else stop();  
   }
   */
}

