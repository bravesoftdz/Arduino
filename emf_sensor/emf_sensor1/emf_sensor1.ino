// EMF Detector for 7-Segment LED Display v1.0
//
// original code/project by Aaron ALAI - aaronalai1@gmail.com
// modified for use w/ LED bargraph by Collin Cunningham - collin@makezine.com
// modified again by ComputerGeek for instructable & 7-segment display.

#define NUMREADINGS 25 // raise this number to increase data smoothing

int senseLimit = 15; // raise this number to decrease sensitivity (up to 1023 max)
int probePin = 5; // analog 5
int val = 0; // reading from probePin

// variables for smoothing

int readings[NUMREADINGS];                // the readings from the analog input
int index = 0;                            // the index of the current reading
int total = 0;                            // the running total
int average = 0;                          // final average of the probe reading

//CHANGE THIS TO affect the speed of the updates for numbers. Lower the number the faster it updates.
int updateTime = 25;

int adc_key_in;
int runthething=1;

void setup() {

  Serial.begin(9600);  // initiate serial connection for debugging/etc
  pinMode(3, OUTPUT); 
  digitalWrite(3, HIGH);
  
  for (int i = 0; i < NUMREADINGS; i++)
    readings[i] = 0;                      // initialize all the readings to 0

    intro(); //Runs the intro:'EFD0123456789'
}

void loop() {
  adc_key_in = analogRead(7);    // read the value from the sensor  
  
  if (adc_key_in<200) {     runthething=0;  }
  if ( (adc_key_in>200) && (adc_key_in<400) ) {     runthething=1;  }
  

  val = analogRead(probePin);  // take a reading from the probe
  
  if (runthething==1)
  {
    if(val >= 1){                // if the reading isn't zero, proceed
      val = constrain(val, 1, senseLimit);  // turn any reading higher than the senseLimit value into the senseLimit value
      val = map(val, 1, senseLimit, 1, 1023);  // remap the constrained value within a 1 to 1023 range
    
      
  
      total -= readings[index];               // subtract the last reading
      readings[index] = val; // read from the sensor
      total += readings[index];               // add the reading to the total
      index = (index + 1);                    // advance to the next index
  
      if (index >= NUMREADINGS)               // if we're at the end of the array...
        index = 0;                            // ...wrap around to the beginning
  
      average = total / NUMREADINGS;          // calculate the average
      Serial.println(average);
  
      delay(updateTime);
  
      digitalWrite(3,HIGH);
    }
  }
}


void intro(){
  //The nice little led intro 'EFD0123456789'
}

