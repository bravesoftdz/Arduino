#include <NewPing.h>

#define TRIGGER_PIN  5  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     4  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

#define BLUE_LED_DIO 9     /* Select the DIO for driving the BLUE LED */
#define RED_LED_DIO 11       /* Select the DIO for driving the RED LED */
#define GREEN_LED_DIO 10    /* Select the DIO for driving the GREEN LED */

int val;
int valX;
int k=0;
unsigned int uS=0;

// establish variables for duration of the ping, 
// and the distance result in inches and centimeters:
long duration, inches, cm;

const int trigPin = 5;
const int echoPin = 4;

void setup() {

  /* Configure the DIO pins used by the analogWrite PWM function  */
  pinMode(BLUE_LED_DIO, OUTPUT); 
  pinMode(RED_LED_DIO, OUTPUT); 
  pinMode(GREEN_LED_DIO, OUTPUT); 
  analogWrite(BLUE_LED_DIO, 255);  
  analogWrite(RED_LED_DIO, 255);
  analogWrite(GREEN_LED_DIO, 255);  
  
  val = 5;
  valX = 0;
  
  // initialize serial communication:
  Serial.begin(115200);
}

void loop()
{
//  val = analogRead(1);            // reads the value of the potentiometer (value between 0 and 1023) 
//  val = map(val, 0, 1023, 3, 30);     // scale it to use it with the servo (value between 0 and 180) 
  for (k = 0; k <=255; k++)
  {
    analogWrite(RED_LED_DIO, 255-k);
    delay(val);
  }

  uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  Serial.print("Ping: ");
  Serial.print(uS / US_ROUNDTRIP_CM); // Convert ping time to distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
  val = uS / US_ROUNDTRIP_CM / 20;

  for (k = 0; k <=255; k++)
  {
    analogWrite(RED_LED_DIO, k);
    analogWrite(BLUE_LED_DIO, 255-k);
    delay(val);
    valX = valX+val;
    
    if (valX>=50) {
        valX =0;
        uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
        Serial.print("Ping: ");
        Serial.print(uS / US_ROUNDTRIP_CM); // Convert ping time to distance in cm and print result (0 = outside set distance range)
        Serial.println("cm");
        val = uS / US_ROUNDTRIP_CM / 40;
        if (val<1) {val=1;}
    }

  }
  
  for (k = 0; k <=255; k++)
  {
    analogWrite(BLUE_LED_DIO, k);
    analogWrite(GREEN_LED_DIO, 255-k);
    delay(val);
    valX = valX+val;
    
    if (valX>=50) {
        valX =0;
        uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
        Serial.print("Ping: ");
        Serial.print(uS / US_ROUNDTRIP_CM); // Convert ping time to distance in cm and print result (0 = outside set distance range)
        Serial.println("cm");
        val = uS / US_ROUNDTRIP_CM / 40;
        if (val<1) {val=1;}
    }
  }

  for (k = 0; k <=255; k++)
  {
    analogWrite(GREEN_LED_DIO, k);
    delay(val);
    valX = valX+val;
    
    if (valX>=50) {
        valX =0;
        uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
        Serial.print("Ping: ");
        Serial.print(uS / US_ROUNDTRIP_CM); // Convert ping time to distance in cm and print result (0 = outside set distance range)
        Serial.println("cm");
        val = uS / US_ROUNDTRIP_CM / 40;
        if (val<1) {val=1;}
    }
  }
}

long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

/*
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  
  val = cm/20;
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(100);
*/

