int xPin = 0;
int yPin = 0;
int WalkSpeed = 25;
int potpin = 0;  // analog pin used to connect the potentiometer
int WalkDirection = 0;
int WalkRGB = 0;
int OldWalkSpeed = 0;

int RedColor   = 255;
int BlueColor  = 255;
int GreenColor = 255;
int LedLimit   = 0;
int OldLedLimit   = 0;
int PotInput = 0;
int PotInput2 = 0;
int WalkCounter  = 0;

int LedDirection = 1;

int LedColor = 1;

#define BLUE_LED_DIO 10     /* Select the DIO for driving the BLUE LED */
#define RED_LED_DIO 11       /* Select the DIO for driving the RED LED */
#define GREEN_LED_DIO 9    /* Select the DIO for driving the GREEN LED */


void setup() {    

  pinMode(BLUE_LED_DIO, OUTPUT); 
  pinMode(RED_LED_DIO, OUTPUT); 
  pinMode(GREEN_LED_DIO, OUTPUT); 
  analogWrite(BLUE_LED_DIO, 255);  
  analogWrite(RED_LED_DIO, 255);
  analogWrite(GREEN_LED_DIO, 255);  
  
  for (int xPin = 2; xPin < 10; xPin++)
  {
    if (xPin==9) {yPin=12;} else {yPin=xPin;}
    pinMode(yPin, OUTPUT);
    digitalWrite(yPin, HIGH);    // turn the LED off by making the voltage LOW
  }
  WalkDirection=1;
  WalkRGB = 1;
  xPin = 1;
  
  Serial.begin(115200);
  
}

void loop() {

  PotInput = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
/*
  WalkCounter++;
  if (WalkCounter>2) 
  {  
    WalkCounter = 0;
  }
*/
  OldLedLimit = LedLimit;
  LedLimit = map(PotInput, 0, 64, 0, 8);     // scale it to use it with the servo (value between 0 and 180) 
  
  if (LedLimit==0) {  LedLimit  = OldLedLimit;  }
  
  if (PotInput!=0)
  {
    PotInput2 = PotInput;
  Serial.print("Sound: ");
  Serial.print(PotInput);
  Serial.print(" Delay: ");
  Serial.println(WalkSpeed); // Convert ping time to distance in cm and print result (0 = outside set distance range)
  }
  
  if (LedDirection==1)
  {
    xPin++;
    if (xPin==9) {yPin=12;} else {yPin=xPin;}
    digitalWrite(yPin, LOW);   // turn the LED
    delay(WalkSpeed);

    if (LedColor==1)
    {
        RedColor -=30;
        analogWrite(RED_LED_DIO, RedColor);
        if (RedColor<=0) { RedColor=0; analogWrite(RED_LED_DIO, RedColor);  }
    }
    
    if (LedColor==2)
    {
        GreenColor -=30;
        analogWrite(GREEN_LED_DIO, GreenColor);
        if (GreenColor<=0) { GreenColor=0; analogWrite(GREEN_LED_DIO, GreenColor); }
    }

    if (LedColor==3)
    {
        BlueColor -=30;
        analogWrite(BLUE_LED_DIO, BlueColor);
        if (BlueColor<=0) { BlueColor=0; analogWrite(BLUE_LED_DIO, RedColor);  }
    }
    
    if (LedColor==4)
    {
        RedColor -=30;
        analogWrite(RED_LED_DIO, RedColor);
        if (RedColor<=0) { RedColor=0; analogWrite(RED_LED_DIO, RedColor); }

        BlueColor -=30;
        analogWrite(BLUE_LED_DIO, BlueColor);
        if (BlueColor<=0) { BlueColor=0; analogWrite(BLUE_LED_DIO, RedColor); }
    }
    
    if (LedColor==5)
    {
        RedColor -=30;
        analogWrite(RED_LED_DIO, RedColor);
        if (RedColor<=0) { RedColor=0; analogWrite(RED_LED_DIO, RedColor); }

        BlueColor -=30;
        analogWrite(BLUE_LED_DIO, BlueColor);
        if (BlueColor<=0) { BlueColor=0; analogWrite(BLUE_LED_DIO, RedColor);}

        GreenColor -=30;
        analogWrite(GREEN_LED_DIO, GreenColor);
        if (GreenColor<=0) { GreenColor=0; analogWrite(GREEN_LED_DIO, GreenColor); }
    }


    if (LedColor==6)
    {
        RedColor -=30;
        analogWrite(RED_LED_DIO, RedColor);
        if (RedColor>=255) { RedColor=255; analogWrite(RED_LED_DIO, RedColor); }

        GreenColor -=30;
        analogWrite(GREEN_LED_DIO, GreenColor);
        if (GreenColor>=255) { GreenColor=255; analogWrite(GREEN_LED_DIO, GreenColor); }
    }

    
    
    if (xPin>=LedLimit) { 
      LedDirection = 2; xPin++;
      WalkSpeed = map(PotInput, 0, 32, 1, 35);     // scale it to use it with the servo (value between 0 and 180) 
    } else
    if (xPin==9) { 
      LedDirection = 2; xPin++; 
      WalkSpeed = map(PotInput, 0, 32, 1, 35);     // scale it to use it with the servo (value between 0 and 180) 
    }
  } else
  
  if (LedDirection==2)
  {
    xPin--;
    if (xPin==9) {yPin=12;} else {yPin=xPin;}
    digitalWrite(yPin, HIGH);   // turn the LED off
    delay(WalkSpeed);
    if (xPin<=2) { LedDirection = 1; xPin--;         LedColor=random(1,6);  RedColor=255; analogWrite(RED_LED_DIO, RedColor);  GreenColor=255; analogWrite(GREEN_LED_DIO, GreenColor); BlueColor=255; analogWrite(BLUE_LED_DIO, RedColor); }


    if (LedColor==1)
    {
        RedColor +=30;
        analogWrite(RED_LED_DIO, RedColor);
        if (RedColor>=255) { RedColor=255; analogWrite(RED_LED_DIO, RedColor); }
    }
    
    if (LedColor==2)
    {
        GreenColor +=30;
        analogWrite(GREEN_LED_DIO, GreenColor);
        if (GreenColor>=255) { GreenColor=255; analogWrite(GREEN_LED_DIO, GreenColor); }
    }

    if (LedColor==3)
    {
        BlueColor +=30;
        analogWrite(BLUE_LED_DIO, BlueColor);
        if (BlueColor>=255) { BlueColor=255; analogWrite(BLUE_LED_DIO, RedColor); }
    }
    
    if (LedColor==4)
    {
        RedColor +=30;
        analogWrite(RED_LED_DIO, RedColor);
        if (RedColor>=255) { RedColor=255; analogWrite(RED_LED_DIO, RedColor); }

        BlueColor +=30;
        analogWrite(BLUE_LED_DIO, BlueColor);
        if (BlueColor>=255) { BlueColor=255; analogWrite(BLUE_LED_DIO, RedColor); }
    }
    
    if (LedColor==5)
    {
        RedColor +=30;
        analogWrite(RED_LED_DIO, RedColor);
        if (RedColor>=255) { RedColor=255; analogWrite(RED_LED_DIO, RedColor); }

        BlueColor +=30;
        analogWrite(BLUE_LED_DIO, BlueColor);
        if (BlueColor>=255) { BlueColor=255; analogWrite(BLUE_LED_DIO, RedColor); }

        GreenColor +=30;
        analogWrite(GREEN_LED_DIO, GreenColor);
        if (GreenColor>=255) { GreenColor=255; analogWrite(GREEN_LED_DIO, GreenColor); }
    }


    if (LedColor==6)
    {
        RedColor +=30;
        analogWrite(RED_LED_DIO, RedColor);
        if (RedColor>=255) { RedColor=255; analogWrite(RED_LED_DIO, RedColor); }

        GreenColor +=30;
        analogWrite(GREEN_LED_DIO, GreenColor);
        if (GreenColor>=255) { GreenColor=255; analogWrite(GREEN_LED_DIO, GreenColor); }
    }
    
    
  }
  
/*
  if (WalkRGB == 1)
  {
    analogWrite(RED_LED_DIO, RedColor);
    RedColor -=10;
    if (RedColor<=0) { WalkRGB=2; RedColor=0; analogWrite(RED_LED_DIO, RedColor); }
  }

  if (WalkRGB == 2)
  {
    analogWrite(RED_LED_DIO, RedColor);
    RedColor +=10;
    if (RedColor>=255) { RedColor=255; analogWrite(RED_LED_DIO, RedColor); }
  }
  

  if (WalkRGB == 2)
  {
    analogWrite(BLUE_LED_DIO, BlueColor);
    BlueColor -=5;
    if (BlueColor<=0) { WalkRGB=5; BlueColor=0; analogWrite(BLUE_LED_DIO, BlueColor);  }
  }

  if (WalkRGB == 5)
  {
    analogWrite(BLUE_LED_DIO, BlueColor);
    BlueColor +=10;
    if (BlueColor>=255) { BlueColor=255; analogWrite(BLUE_LED_DIO, BlueColor); }
  }
  

  if (WalkRGB == 5)
  {
    analogWrite(GREEN_LED_DIO, GreenColor);
    GreenColor -=5;
    if (GreenColor<=0) { WalkRGB=6; GreenColor=0; analogWrite(GREEN_LED_DIO, GreenColor);  }
  }

  if (WalkRGB == 6)
  {
    analogWrite(GREEN_LED_DIO, GreenColor);
    GreenColor +=10;
    if (GreenColor>=255) { WalkRGB=1; GreenColor=255; analogWrite(GREEN_LED_DIO, GreenColor);  BlueColor=255; }
  }
  */
}
