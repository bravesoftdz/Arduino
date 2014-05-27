// LCD Thermostat
// www.hacktronics.com

#include <OneWire.h>

// Connections:
// rs (LCD pin 4) to Arduino pin 12
// rw (LCD pin 5) to Arduino pin 11
// enable (LCD pin 6) to Arduino pin 10
// LCD pin 15 to Arduino pin 13
// LCD pins d4, d5, d6, d7 to Arduino pins 5, 4, 3, 2

OneWire  ds(2);        // ds18b20 pin #2 (middle pin) to Arduino pin 8

byte i;
byte present = 0;
byte data[12];
byte addr[8];
  
int HighByte, LowByte, SignBit, Whole, Fract, TReading, Tc_100, FWhole;

void setup(void) {
  Serial.begin(9600);
  
    if ( !ds.search(addr)) {
      Serial.println("No more addrs");
      delay(1000);
      ds.reset_search();
      return;
  }

  if ( OneWire::crc8( addr, 7) != addr[7]) {
      Serial.println("CRC not valid!");
      delay(1000);
      return;
  }
}

void getTemp() {
  int foo, bar;
  
  ds.reset();
  ds.select(addr);
  ds.write(0x44,1);
  
  present = ds.reset();
  ds.select(addr);    
  ds.write(0xBE);

  for ( i = 0; i < 9; i++) {
    data[i] = ds.read();
  }
  
  LowByte = data[0];
  HighByte = data[1];
  TReading = (HighByte << 8) + LowByte;
  SignBit = TReading & 0x8000;  // test most sig bit
  
  Serial.println(TReading);
  
  if (SignBit) {
    TReading = -TReading;
  }
  Tc_100 = (6 * TReading) + TReading / 4;    // multiply by (100 * 0.0625) or 6.25
  Whole = Tc_100 / 100;          // separate off the whole and fractional portions
  Fract = Tc_100 % 100;
  if (Fract > 49) {
    if (SignBit) {
      --Whole;
    } else {
      ++Whole;
    }
  }

  if (SignBit) {
    bar = -1;
  } else {
    bar = 1;
  }
  foo = ((Whole * bar) * 18);      // celsius to fahrenheit conversion section
  FWhole = (((Whole * bar) * 18) / 10) + 32;
  if ((foo % 10) > 4) {            // round up if needed
       ++FWhole;
  }
}

void printTemp(void) {

/*  
  if (SignBit) {  
     lcd.print("-");
  }
  */
    Serial.println(Whole);
//  lcd.print(" C / ");
//  lcd.print(FWhole);
//  lcd.print(" F");
}

void loop(void) {
  getTemp();
  printTemp();
  delay(1000);
} 
