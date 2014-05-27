
#include <Servo.h> 
 
Servo myservo1;
Servo myservo2;

int JoystickButton = 0;
               
 
int pos = 0;   
int Direction =0;
int Servo1Pos =100; //top
int Servo2Pos =110; //bottom

int BlinkCounter =0;


#define BLUE_LED_DIO 5     /* Select the DIO for driving the BLUE LED */
#define RED_LED_DIO 6       /* Select the DIO for driving the RED LED */
#define GREEN_LED_DIO 3    /* Select the DIO for driving the GREEN LED */

int RedColor,BlueColor,GreenColor = 255;
int incRed,incBlue,incGreen = 0;

 
void setup() 
{ 
  myservo1.attach(2);
  myservo2.attach(4);
  myservo1.write(Servo1Pos);
  myservo2.write(Servo2Pos);

  pinMode(BLUE_LED_DIO, OUTPUT); 
  pinMode(RED_LED_DIO, OUTPUT); 
  pinMode(GREEN_LED_DIO, OUTPUT); 
  analogWrite(BLUE_LED_DIO, 255);  
  analogWrite(RED_LED_DIO, 255);
  analogWrite(GREEN_LED_DIO, 255);  
  RedColor = 128;
  BlueColor = 64;
  GreenColor = 192;
  
  Serial.begin(9600);  
  
} 
 
 
void loop() 
{ 
  Direction =0;

  JoystickButton = analogRead(0);
  if (JoystickButton < 20) { Direction = 1; } //left
  if ((JoystickButton > 480) && (JoystickButton < 520)) { Direction = 2; } //right
  if ((JoystickButton > 120) && (JoystickButton < 160)) { Direction = 3; } //up
  if ((JoystickButton > 300) && (JoystickButton < 340)) { Direction = 4; } //down
  if ((JoystickButton > 720) && (JoystickButton < 760)) { Direction = 5; } //fire

//  Serial.println(Direction);  

  if (Direction == 1) { Servo1Pos--; myservo1.write(Servo1Pos); delay(30); } else
  if (Direction == 2) { Servo1Pos++; myservo1.write(Servo1Pos); delay(30); } else

  if (Direction == 3) { Servo2Pos--; myservo2.write(Servo2Pos); delay(30); } else
  if (Direction == 4) { Servo2Pos++; myservo2.write(Servo2Pos); delay(30); } else  
/*  
  if (Direction == 5) {
//     myservo1.detach();
//     myservo2.detach();
 
        for(pos = 85; pos < 120; pos += 1)  {   myservo1.write(pos);   delay(25);     } 
        for(pos = 50; pos < 85; pos += 1)  {   myservo2.write(pos);   delay(25);     } 
        
        for(pos = 120; pos > 85; pos -= 1)  {   myservo1.write(pos);   delay(25);     } 
        for(pos = 85; pos > 50; pos -= 1)  {   myservo2.write(pos);   delay(25);     } 

        int Servo1Pos =100; //top
        int Servo2Pos =65; //bottom
        
        myservo1.write(Servo1Pos); 
        myservo2.write(Servo2Pos); 
        
  }
*/  
  if (Servo1Pos>120) { Servo1Pos=120; }
  if (Servo1Pos<85)  { Servo1Pos= 85; }
  
  if (Servo2Pos>140) { Servo2Pos=140; }
  if (Servo2Pos<90)  { Servo2Pos= 90; }
  
  BlinkCounter++;

  if (BlinkCounter>15) { BlinkCounter=0; }
  
  if (BlinkCounter>2)
  {
      analogWrite(RED_LED_DIO, RedColor);
      if (incRed==0) {  RedColor -=1; } else { RedColor +=1; }
      if (RedColor<=0) { incRed=1; } else
      if (RedColor>=255) { incRed=0; }
      
      analogWrite(GREEN_LED_DIO, GreenColor);
      if (incGreen==0) {  GreenColor -=1; } else { GreenColor +=1; }
      if (GreenColor<=0) { incGreen=1; } else
      if (GreenColor>=255) { incGreen=0; }
      
      analogWrite(BLUE_LED_DIO, BlueColor);
      if (incBlue==0) {  BlueColor -=1; } else { BlueColor +=1; }
      if (BlueColor<=0) { incBlue=1; } else
      if (BlueColor>=255) { incBlue=0; }
  } else
  {
      analogWrite(RED_LED_DIO, 255);
      analogWrite(GREEN_LED_DIO, 255);
      analogWrite(BLUE_LED_DIO, 255);
  }

  delay(10);

} 
