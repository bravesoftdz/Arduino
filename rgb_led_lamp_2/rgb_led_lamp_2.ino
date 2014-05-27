#define BLUE_LED_DIO 3     /* Select the DIO for driving the BLUE LED */
#define RED_LED_DIO 5       /* Select the DIO for driving the RED LED */
#define GREEN_LED_DIO 6    /* Select the DIO for driving the GREEN LED */

int RedColor,BlueColor,GreenColor = 255;
int incRed,incBlue,incGreen = 0;
int potpin = 5;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin 

int Pin9 = 255;
int incPin9 = 0;

int Pin10 = 0;
int incPin10 = 1;

void setup() {    

  pinMode(BLUE_LED_DIO, OUTPUT); 
  pinMode(RED_LED_DIO, OUTPUT); 
  pinMode(GREEN_LED_DIO, OUTPUT); 
  analogWrite(BLUE_LED_DIO, 255);  
  analogWrite(RED_LED_DIO, 255);
  analogWrite(GREEN_LED_DIO, 255);  
  
  pinMode(9, OUTPUT); 
  pinMode(10, OUTPUT); 
  
  RedColor = 128;
  BlueColor = 64;
  GreenColor = 192;
  Serial.begin(9600);
  
}

void loop() {
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
  val = map(val, 0, 1023, 1, 100);     // scale it to use it with the servo (value between 0 and 180) 
//  Serial.println(val); 

   analogWrite(9, Pin9);
   analogWrite(10, Pin10);
   
   if (incPin9==0) {  Pin9 -=1; } else { Pin9 +=1; }
   if (Pin9<=0) { incPin9=1; } else
   if (Pin9>=255) { incPin9=0; }

   if (incPin10==0) {  Pin10 -=1; } else { Pin10 +=1; }
   if (Pin10<=0) { incPin10=1; } else
   if (Pin10>=255) { incPin10=0; }
   

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
}
