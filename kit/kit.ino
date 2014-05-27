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
    digitalWrite(yPin, LOW);    // turn the LED off by making the voltage LOW
  }
  WalkDirection=1;
  WalkRGB = 1;
  xPin = 1;
  
  Serial.begin(115200);
  
}

void loop() {

  OldWalkSpeed = WalkSpeed;
  WalkSpeed = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
  WalkSpeed = 1024-WalkSpeed;
  WalkSpeed = map(WalkSpeed, 0, 1023, 0, 200);     // scale it to use it with the servo (value between 0 and 180) 

  
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
  

  if (WalkDirection == 1)
  {
    xPin++;
    if (xPin==9) {yPin=12;} else {yPin=xPin;}
    digitalWrite(yPin, LOW);   // turn the LED
    delay(WalkSpeed);
    if (xPin==9) { WalkDirection=2; xPin=1; }
  } else
  if (WalkDirection == 2)
  {
    xPin++;
    if (xPin==9) {yPin=12;} else {yPin=xPin;}
    digitalWrite(yPin, HIGH);   // turn the LED
    delay(WalkSpeed);
    if (xPin==9) { WalkDirection=3; xPin=10;}
  } else
  if (WalkDirection == 3)
  {
    xPin--;
    if (xPin==9) {yPin=12;} else {yPin=xPin;}
    digitalWrite(yPin, LOW);   // turn the LED
    delay(WalkSpeed);
    if (xPin==2) { WalkDirection=4; xPin=10; }
  } else
  if (WalkDirection == 4)
  {
    xPin--;
    if (xPin==9) {yPin=12;} else {yPin=xPin;}
    digitalWrite(yPin, HIGH);   // turn the LED
    delay(WalkSpeed);
    if (xPin==2) { WalkDirection=1; xPin=1; }
  }
}
