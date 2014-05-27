#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

int relay = 4;
int button = 3;
int onoff = 0;
int press1 = 0;
float sensorread = 0;

void setup() {
  Serial.begin(57600);
  Serial.println("Dallas Temperature IC Control Library Demo");

  sensors.begin();
  sensors.setResolution(12);  
  Serial.println(sensors.getResolution()); // Why "byIndex"? 
  
  pinMode(relay, OUTPUT);     
  pinMode(button, INPUT);
  
  attachInterrupt(1, buttonx, CHANGE);
}

void buttonx() {
  if ((digitalRead(button)==LOW) && (press1==0))
  {
    press1=1;
    if (onoff==1) { onoff=0; } else
    if (onoff==0) { onoff=1; }
  }
  
  if (digitalRead(button)==HIGH)
  {
     press1=0;
  }
  
  if (onoff==1)
  {
//     digitalWrite(relay, HIGH);
  } else
  {
//    digitalWrite(relay, LOW);
  }
  
}

void loop() {
  
  
  sensors.requestTemperatures(); 
  sensorread =sensors.getTempCByIndex(0);
  Serial.println(sensorread); 
  if (sensorread>40) { digitalWrite(relay, HIGH); } else
  { digitalWrite(relay, LOW); }
  delay(5);
  
}
