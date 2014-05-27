int STP1 = 4;  // stepper 1 coil output
int STP2 = 5;  // stepper 2 coil output
int STP3 = 6;  // stepper 3 coil output 
int STP4 = 7;  // stepper 4 coil output

int STP1_2 = 8;  // stepper 1 coil output
int STP2_2 = 9;  // stepper 2 coil output
int STP3_2 = 10;  // stepper 3 coil output 
int STP4_2 = 11;  // stepper 4 coil output

int EngineDir = 2;  // stepper 4 coil output
int EngineOn = 3;  // stepper 4 coil output

int MotorDir=0;
int MotorPress=0;

int JoystickButton = 0;

int Direction = 0;

int DoneRunning=0;
int WasRunning=0;

int stepDelay = 3000; //bottom scanner

int stepDelay_2 = 5000;

int stepZoom = 1;

int SerialCommand0 = 0;
int SerialCommand = 0;
int SerialParameter = 0;

// the setup routine runs once when you press reset:

void setup() {                
  // initialize the digital pin as an output.
  pinMode(STP1, OUTPUT);
  pinMode(STP2, OUTPUT);
  pinMode(STP3, OUTPUT);
  pinMode(STP4, OUTPUT);
  
  pinMode(STP1_2, OUTPUT);
  pinMode(STP2_2, OUTPUT);
  pinMode(STP3_2, OUTPUT);
  pinMode(STP4_2, OUTPUT);

  pinMode(EngineDir, OUTPUT);
  pinMode(EngineOn, OUTPUT);
  
  // initialize the serial port:
  Serial.begin(57600);  
}

void stepLeft()
{
  for (int i=0; i<stepZoom; i++)
  {
      //start the spepper motor turning to 36 deg.
      digitalWrite(STP1, HIGH);   // turn the LED on (HIGH is the voltage level)
      delayMicroseconds(stepDelay);
      digitalWrite(STP1, LOW);    // turn the LED off by making the voltage LOW
      delayMicroseconds(stepDelay);
      digitalWrite(STP2, HIGH);   // turn the LED on (HIGH is the voltage level)
      delayMicroseconds(stepDelay);
      digitalWrite(STP2, LOW);    // turn the LED off by making the voltage LOW
      delayMicroseconds(stepDelay);
      digitalWrite(STP3, HIGH);   // turn the LED on (HIGH is the voltage level)
      delayMicroseconds(stepDelay);
      digitalWrite(STP3, LOW);    // turn the LED off by making the voltage LOW
      delayMicroseconds(stepDelay);
      digitalWrite(STP4, HIGH);   // turn the LED on (HIGH is the voltage level)
      delayMicroseconds(stepDelay);
      digitalWrite(STP4, LOW);    // turn the LED off by making the voltage LOW
      delayMicroseconds(stepDelay);
  } 
}


void stepRight()
{
  for (int i=0; i<stepZoom; i++)
  {
    //start the spepper motor turning to 36 deg.
    digitalWrite(STP4, HIGH);   // turn the LED on (HIGH is the voltage level)
    delayMicroseconds(stepDelay);
    digitalWrite(STP4, LOW);    // turn the LED off by making the voltage LOW
    delayMicroseconds(stepDelay);
    digitalWrite(STP3, HIGH);   // turn the LED on (HIGH is the voltage level)
    delayMicroseconds(stepDelay);
    digitalWrite(STP3, LOW);    // turn the LED off by making the voltage LOW
    delayMicroseconds(stepDelay);
    digitalWrite(STP2, HIGH);   // turn the LED on (HIGH is the voltage level)
    delayMicroseconds(stepDelay);
    digitalWrite(STP2, LOW);    // turn the LED off by making the voltage LOW
    delayMicroseconds(stepDelay);
    digitalWrite(STP1, HIGH);   // turn the LED on (HIGH is the voltage level)
    delayMicroseconds(stepDelay);
    digitalWrite(STP1, LOW);    // turn the LED off by making the voltage LOW
    delayMicroseconds(stepDelay);
  }
}



void stepUp()
{
  for (int i=0; i<stepZoom; i++)
  {
      //start the spepper motor turning to 36 deg.
      digitalWrite(STP1_2, HIGH);   // turn the LED on (HIGH is the voltage level)
      delayMicroseconds(stepDelay_2);
      digitalWrite(STP1_2, LOW);    // turn the LED off by making the voltage LOW
      delayMicroseconds(stepDelay_2);
      digitalWrite(STP2_2, HIGH);   // turn the LED on (HIGH is the voltage level)
      delayMicroseconds(stepDelay_2);
      digitalWrite(STP2_2, LOW);    // turn the LED off by making the voltage LOW
      delayMicroseconds(stepDelay_2);
      digitalWrite(STP3_2, HIGH);   // turn the LED on (HIGH is the voltage level)
      delayMicroseconds(stepDelay_2);
      digitalWrite(STP3_2, LOW);    // turn the LED off by making the voltage LOW
      delayMicroseconds(stepDelay_2);
      digitalWrite(STP4_2, HIGH);   // turn the LED on (HIGH is the voltage level)
      delayMicroseconds(stepDelay_2);
      digitalWrite(STP4_2, LOW);    // turn the LED off by making the voltage LOW
      delayMicroseconds(stepDelay_2);
  } 
}


void stepDown()
{
  for (int i=0; i<stepZoom; i++)
  {
    //start the spepper motor turning to 36 deg.
    digitalWrite(STP4_2, HIGH);   // turn the LED on (HIGH is the voltage level)
    delayMicroseconds(stepDelay_2);
    digitalWrite(STP4_2, LOW);    // turn the LED off by making the voltage LOW
    delayMicroseconds(stepDelay_2);
    digitalWrite(STP3_2, HIGH);   // turn the LED on (HIGH is the voltage level)
    delayMicroseconds(stepDelay_2);
    digitalWrite(STP3_2, LOW);    // turn the LED off by making the voltage LOW
    delayMicroseconds(stepDelay_2);
    digitalWrite(STP2_2, HIGH);   // turn the LED on (HIGH is the voltage level)
    delayMicroseconds(stepDelay_2);
    digitalWrite(STP2_2, LOW);    // turn the LED off by making the voltage LOW
    delayMicroseconds(stepDelay_2);
    digitalWrite(STP1_2, HIGH);   // turn the LED on (HIGH is the voltage level)
    delayMicroseconds(stepDelay_2);
    digitalWrite(STP1_2, LOW);    // turn the LED off by making the voltage LOW
    delayMicroseconds(stepDelay_2);
  }
}


void loop(){
  SerialParameter--;
  if (SerialParameter<=0) {  SerialCommand = 0; SerialParameter=0; }
//  Serial.println(SerialParameter);
  if (Serial.available() > 2) {
    if (SerialParameter==0)  {
      SerialCommand0 = Serial.read();
      if (SerialCommand0=177)
      {
        WasRunning=1;
//      SerialCommand = Serial.parseInt(); 
//      SerialParameter = Serial.parseInt(); 
        if (Serial.available() > 0) {
          SerialCommand = Serial.read()-70;
          if (Serial.available() > 0) {
            SerialParameter = Serial.read()-70;
          } else
          {
            SerialCommand=0;
            SerialParameter=0;
          }
        } else
        {
          SerialCommand=0;
          SerialParameter=0;
        }
        Serial.print("BEGIN:");
        Serial.print(SerialCommand);
        Serial.print(" - ");
        Serial.print(SerialParameter);
        Serial.println(";");
      }
    }  
  } else
  if (SerialParameter==0)
  {
    if (WasRunning==1) { DoneRunning = 1; WasRunning=0; }
  }
  
  if (DoneRunning==1)
  {
    DoneRunning=0;
    Serial.println("Z");  
  }
  Direction =0;
  
  JoystickButton = analogRead(0);
  if (JoystickButton < 20) { Direction = 1; } //left
  if ((JoystickButton > 480) && (JoystickButton < 520)) { Direction = 2; } //right
  if ((JoystickButton > 120) && (JoystickButton < 160)) { Direction = 3; } //up
  if ((JoystickButton > 300) && (JoystickButton < 340)) { Direction = 4; } //down
  
  if ((JoystickButton > 720) && (JoystickButton < 760)) { Direction = 5; } //fire
//  Serial.println( Direction );

  if (SerialCommand == 1) { Direction = 1; } else
  if (SerialCommand == 2) { Direction = 2; } else
  if (SerialCommand == 3) { Direction = 3; } else
  if (SerialCommand == 4) { Direction = 4; } else
  
  if (SerialCommand == 5) { //retract for 1 sec
      digitalWrite(EngineDir, HIGH);
      analogWrite(EngineOn,125);
      delay(10);
      digitalWrite(EngineDir, LOW);     
      analogWrite(EngineOn,LOW); 
  }  else

  if (SerialCommand == 6) { //retract for 1 sec
      digitalWrite(EngineDir, LOW);
      analogWrite(EngineOn,75);
      delay(10);
      digitalWrite(EngineDir, LOW);     
      analogWrite(EngineOn,LOW); 
  } 
  
  if (Direction == 1) { stepLeft(); } else
  if (Direction == 2) { stepRight(); }   else

  if (Direction == 3) { stepUp(); } else
  if (Direction == 4) { stepDown(); }  else  
  
  if (Direction == 5) {
    if (MotorPress==1) 
    {
      if (MotorDir==1) {MotorDir = 0; } else {MotorDir=1;}
    }
    MotorPress = 0;
      
    if (MotorDir == 1 )
    {
      digitalWrite(EngineDir, HIGH);
      analogWrite(EngineOn,125);  
    } else
    {
      digitalWrite(EngineDir, LOW);
      analogWrite(EngineOn,75);  
    }
    
  }   else
  
  if (Direction == 0) { 
    digitalWrite(EngineDir, LOW);     
    analogWrite(EngineOn,LOW); 
    MotorPress = 1;
  }
  
}
