#define BLUE_LED_DIO 10     /* Select the DIO for driving the BLUE LED */
#define RED_LED_DIO 11       /* Select the DIO for driving the RED LED */
#define GREEN_LED_DIO 9    /* Select the DIO for driving the GREEN LED */

#define BLUE_LED_DIO_2 5     /* Select the DIO for driving the BLUE LED */
#define RED_LED_DIO_2 6       /* Select the DIO for driving the RED LED */
#define GREEN_LED_DIO_2 7    /* Select the DIO for driving the GREEN LED */

int RedColor,BlueColor,GreenColor = 255;
int incRed,incBlue,incGreen = 0;
int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin 
int xcounter = 0;
int xcounter2 = 0;
int xstate = 0;

void setup() {
  Serial.begin(9600);    

  pinMode(BLUE_LED_DIO, OUTPUT); 
  pinMode(RED_LED_DIO, OUTPUT); 
  pinMode(GREEN_LED_DIO, OUTPUT); 

  analogWrite(BLUE_LED_DIO, 255);  
  analogWrite(RED_LED_DIO, 255);
  analogWrite(GREEN_LED_DIO, 255);  

  pinMode(BLUE_LED_DIO_2, OUTPUT); 
  pinMode(RED_LED_DIO_2, OUTPUT); 
  pinMode(GREEN_LED_DIO_2, OUTPUT); 

  analogWrite(BLUE_LED_DIO, 255);  
  analogWrite(RED_LED_DIO, 255);
  analogWrite(GREEN_LED_DIO, 255);  

  analogWrite(BLUE_LED_DIO_2, 255);  
  analogWrite(RED_LED_DIO_2, 255);
  analogWrite(GREEN_LED_DIO_2, 255);  

  pinMode(12, OUTPUT); 
  digitalWrite(12,0);

  RedColor = 128;
  BlueColor = 64;
  GreenColor = 192;
  Serial.begin(9600);
  
}

void loop() {
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
  val = map(val, 0, 1023, 1, 100);     // scale it to use it with the servo (value between 0 and 180) 
//  Serial.println(val); 

  xcounter++;
  if ((xcounter>(val*50)) && (xstate==1)) { xstate = 0; digitalWrite(12,xstate); xcounter=0; Serial.println("0"); }
  if ((xcounter>((100-val)*50)) && (xstate==0)) { xstate = 1; digitalWrite(12,xstate); xcounter=0; Serial.println("1"); }

  xcounter2++;
  if (xcounter2>val)
  {
      Serial.print(val);
      Serial.print(" ");
      Serial.print(xstate);
      Serial.print(" ");
      Serial.println(xcounter);
      xcounter2=0;
      analogWrite(RED_LED_DIO, RedColor);
      analogWrite(RED_LED_DIO_2, 255-RedColor);
      if (incRed==0) {  RedColor -=1; } else { RedColor +=1; }
      if (RedColor<=0) { incRed=1; } else
      if (RedColor>=255) { incRed=0; }
      
      analogWrite(GREEN_LED_DIO, GreenColor);
      analogWrite(GREEN_LED_DIO_2, 255-GreenColor);
      if (incGreen==0) {  GreenColor -=1; } else { GreenColor +=1; }
      if (GreenColor<=0) { incGreen=1; } else
      if (GreenColor>=255) { incGreen=0; }
      
      analogWrite(BLUE_LED_DIO, BlueColor);
      analogWrite(BLUE_LED_DIO_2, 255-BlueColor);
      if (incBlue==0) {  BlueColor -=1; } else { BlueColor +=1; }
      if (BlueColor<=0) { incBlue=1; } else
      if (BlueColor>=255) { incBlue=0; }
  }   
      delay(2);
}
