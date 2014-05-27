//Standard PWM DC control
int E1 = 5;     //M1 Speed Control
int E2 = 6;     //M2 Speed Control
int M1 = 4;    //M1 Direction Control
int M2 = 7;    //M1 Direction Control

int potpin = 1;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin 


const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
int buttonState = 0;         // variable for reading the pushbutton status



void stop(void)                    //Stop
{
  digitalWrite(E1,LOW);   
  digitalWrite(E2,LOW);   
}   

void advance(char a)
{
  analogWrite (E1,a);
  digitalWrite(M1,HIGH);    
  
  analogWrite (E2,a);
  digitalWrite(M2,HIGH);    
}  

void setup(void) 
{ 
  int i;
  for(i=4;i<=7;i++)
    pinMode(i, OUTPUT);  
  Serial.begin(19200);      //Set Baud Rate
  Serial.println("Run keyboard control");
} 

void loop(void) 
{
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
  val = map(val, 0, 1023, 100, 255);     // scale it to use it with the servo (value between 0 and 180) 

  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {     
    advance (val);
    digitalWrite(ledPin, HIGH);  
  } 
  else {
    stop();
    digitalWrite(ledPin, LOW); 
  }
}
