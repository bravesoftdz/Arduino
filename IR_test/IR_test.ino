const int buttonPin = 7;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

int sensorValue = 0;
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  analogWrite(5,255);
  
  pinMode(ledPin, OUTPUT);      
  pinMode(buttonPin, INPUT);     
  Serial.begin(115200);
  
}

void loop(){
  
  analogWrite(5,255);
  sensorValue = analogRead(5);
  Serial.println(sensorValue);
  delay(10);
  /*
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {     
    digitalWrite(ledPin, HIGH);  
  } 
  else {
    digitalWrite(ledPin, LOW); 
  }
  */
}
