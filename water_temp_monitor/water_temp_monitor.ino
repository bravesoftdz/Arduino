#include <OneWire.h>
#include <DallasTemperature.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address


// Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

float sensorread = 0;
float old_sensorread = 0;

int backlit_on = 0;

void setup() {
  Serial.begin(57600);
  Serial.println("Dallas Temperature IC Control Library AND LCD");


  lcd.begin(16,2);   // initialize the lcd for 16 chars 2 lines, turn on backlight

// ------- Quick 3 blinks of backlight  -------------
  for(int i = 0; i< 3; i++)
  {
    lcd.backlight();
    delay(100);
    lcd.noBacklight();
    delay(100);
  }
  lcd.backlight(); // finish with backlight on  
  
  backlit_on = 10;

  lcd.setCursor(0,0);
  lcd.print("Hello, world!");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("ELuo Temp Sensor");
  delay(1000);  


  sensors.begin();
  sensors.setResolution(12);  
  Serial.println(sensors.getResolution()); // Why "byIndex"? 
}


void loop() {
  
  
  sensors.requestTemperatures(); 
  sensorread =sensors.getTempCByIndex(0);
  Serial.println(sensorread); 
  
  backlit_on--;
  if (backlit_on>0) { lcd.backlight(); } else { lcd.noBacklight(); }
  
  if (old_sensorread != sensorread)
  {
    lcd.clear();
    lcd.setCursor(0,0); //Start at character 0 on line 0
    lcd.print("Temp: ");
    lcd.print(sensorread);
    lcd.print(" C");
    lcd.backlight();

    old_sensorread = sensorread;
    
    backlit_on = 10;
  }
  delay(50);
  
  
}
