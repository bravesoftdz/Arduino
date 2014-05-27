
#define BLUE_1  10 
#define RED_1   11
#define GREEN_1  9

#define BLUE_2  3
#define RED_2   5
#define GREEN_2 6

int Red_1,Blue_1,Green_1 = 255;
int incRed_1,incBlue_1,incGreen_1 = 0;

int Red_2,Blue_2,Green_2 = 255;
int incRed_2,incBlue_2,incGreen_2 = 0;

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin 

int LEDDelay =0;

int rgbLEDPower=255;
int rgbLEDCounter=0;



//------------------------------------
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address
int screenDir = 0;
int screenCount = 0;
int screenMax = 10;
int screenDelay = 75;
int screenDelayCount = 76;

//--------------------------------------
#include <Servo.h> 
Servo myservo;
int servoPos = 50;
int servoDir = 1;
int servoCount = 0;
int servoMax = 150;
int servoMin = 50;
int servoSpeed = 10;
int servoDelay = 1;
int servoDelayCount = 0;



int backlit_on = 0;
int i;

int led13 = 13;
int led13_on = 0;

void setup() {
  pinMode(led13, OUTPUT);     
  
/*  
  pinMode(BLUE_1, OUTPUT); 
  pinMode(RED_1, OUTPUT); 
  pinMode(GREEN_1, OUTPUT); 
  analogWrite(BLUE_1, 255);  
  analogWrite(RED_1, 255);
  analogWrite(GREEN_1, 255);  
  Red_1 = 1;
  Blue_1 = 1;
  Green_1 = 1;
*/

  pinMode(BLUE_2, OUTPUT); 
  pinMode(RED_2, OUTPUT); 
  pinMode(GREEN_2, OUTPUT); 
  analogWrite(BLUE_2, 255);  
  analogWrite(RED_2, 255);
  analogWrite(GREEN_2, 255);  
  Red_2 = 1;
  Blue_2 = 1;
  Green_2 = 1;
  
  myservo.attach(9);
  myservo.write(servoPos);
  
  Serial.begin(57600);
  lcd.begin(16,2);
  
  lcd.setCursor(0,0);
  lcd.print("    Riser");
  delay(100);
  lcd.setCursor(0,1);
  lcd.print("    Wake Me Up!");
  delay(100);

// ------- Quick 3 blinks of backlight  -------------
  for(int i = 0; i< 15; i++)
  {
    lcd.backlight();
    delay(250);
    lcd.noBacklight();
    delay(1000);
  }
  
  backlit_on = 10;

}


void loop() {

 //screen  
  screenDelayCount++;
  if (screenDelayCount>=screenDelay)
  {
    screenCount++;
    if (screenCount>screenMax) { if (screenDir==1) { screenDir = 0; } else {screenDir = 1; } screenCount = 0; }
    
    screenDelayCount=0;
    if (screenDir==1) { lcd.scrollDisplayLeft(); }
    if (screenDir==0) { lcd.scrollDisplayRight(); }
    if (led13_on==1) { digitalWrite(led13, HIGH); led13_on=0; } else { digitalWrite(led13, LOW); led13_on=1; }
  }

 //servo
  servoDelayCount++;
  if (servoDelayCount>=servoDelay)
  {
     servoCount++;
     LEDDelay++;
     
     if (servoCount>servoSpeed) { 
       if (servoDir==1) { 
          servoPos++; 
          myservo.write(servoPos); 
          
          rgbLEDCounter++;
          if (rgbLEDCounter>5)
          {
            rgbLEDCounter = 0;
            rgbLEDPower = rgbLEDPower-15;
            if (rgbLEDPower<0) { rgbLEDPower=0; }
          }

          analogWrite(BLUE_2, rgbLEDPower  );  
          analogWrite(RED_2,  rgbLEDPower  );  
          analogWrite(GREEN_2,  rgbLEDPower  );  
       }
       
       if (servoDir==0) { 
          servoPos--; 
          myservo.write(servoPos); 
          
          rgbLEDCounter++;
          if (rgbLEDCounter>5)
          {
            rgbLEDCounter = 0;
            rgbLEDPower = rgbLEDPower+15;
            if (rgbLEDPower>255) { rgbLEDPower=255; }
          }
          
          analogWrite(BLUE_2, rgbLEDPower  );  
          analogWrite(RED_2,  rgbLEDPower  );  
          analogWrite(GREEN_2,  rgbLEDPower  );  
          
       }
       servoCount = 0; 
     }
     
  lcd.setCursor(0,0);
  lcd.print(servoPos);
     
     
   if ( (servoDir==1) && (servoPos>=servoMax)) { servoDir = 2; servoSpeed = 2; LEDDelay=0;   lcd.backlight(); } else 
   if ( (servoDir==0) && (servoPos<=servoMin)) { servoDir = 1; servoSpeed = 10; lcd.noBacklight(); } else
   if ( (servoDir==2) && (LEDDelay>=500)) { servoDir = 0; servoSpeed = 2; }

    
   servoDelayCount=0;
  }
  
 //RGB
 
/*
     val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
     val = map(val, 0, 1023, 1, 100);     // scale it to use it with the servo (value between 0 and 180) 
     Serial.println(val); 

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
      delay(val);
*/      
  
  delay(10);
  
 
}
