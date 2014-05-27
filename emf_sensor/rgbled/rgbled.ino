

#define BLUE_LED_DIO 9     /* Select the DIO for driving the BLUE LED */
#define RED_LED_DIO 11       /* Select the DIO for driving the RED LED */
#define GREEN_LED_DIO 10    /* Select the DIO for driving the GREEN LED */

int val;

/* Initialise serial and DIO */
void setup()
{
  /* Configure the DIO pins used by the analogWrite PWM function  */
  pinMode(BLUE_LED_DIO, OUTPUT); 
  pinMode(RED_LED_DIO, OUTPUT); 
  pinMode(GREEN_LED_DIO, OUTPUT); 
  analogWrite(BLUE_LED_DIO, 255);  
  analogWrite(RED_LED_DIO, 255);
  analogWrite(GREEN_LED_DIO, 255);  
}

/* Main program loop */
void loop()
{
  int k;
/*  
    analogWrite(9, 255);  
    analogWrite(10, 255);
    analogWrite(11, 0);  
    digitalWrite(13,HIGH);
  delay(1000);
  
    analogWrite(9, 255);  
    analogWrite(10, 255);
    analogWrite(11, 255);  
    digitalWrite(13,LOW);    
  delay(1000);
*/    

  val = analogRead(1);            // reads the value of the potentiometer (value between 0 and 1023) 
  val = map(val, 0, 1023, 3, 30);     // scale it to use it with the servo (value between 0 and 180) 

  for (k = 0; k <=255; k++)
  {
  val = analogRead(1);            // reads the value of the potentiometer (value between 0 and 1023) 
  val = map(val, 0, 1023, 3, 30);     // scale it to use it with the servo (value between 0 and 180) 
    analogWrite(RED_LED_DIO, 255-k);
    delay(val);
  }

  for (k = 0; k <=255; k++)
  {
  val = analogRead(1);            // reads the value of the potentiometer (value between 0 and 1023) 
  val = map(val, 0, 1023, 3, 30);     // scale it to use it with the servo (value between 0 and 180) 
    analogWrite(RED_LED_DIO, k);
    analogWrite(BLUE_LED_DIO, 255-k);
    delay(val);
  }
  

  for (k = 0; k <=255; k++)
  {
  val = analogRead(1);            // reads the value of the potentiometer (value between 0 and 1023) 
  val = map(val, 0, 1023, 3, 30);     // scale it to use it with the servo (value between 0 and 180) 
    analogWrite(BLUE_LED_DIO, k);
    analogWrite(GREEN_LED_DIO, 255-k);
    delay(val);
  }

  for (k = 0; k <=255; k++)
  {
  val = analogRead(1);            // reads the value of the potentiometer (value between 0 and 1023) 
  val = map(val, 0, 1023, 3, 30);     // scale it to use it with the servo (value between 0 and 180) 
    analogWrite(GREEN_LED_DIO, k);
    delay(val);
  }
}

