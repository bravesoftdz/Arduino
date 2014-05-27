 #include <NewPing.h>
#include <RunningAverage.h>

#define TRIGGER_PIN_A  12
#define ECHO_PIN_A     13

#define TRIGGER_PIN_B  5
#define ECHO_PIN_B     6

#define TRIGGER_PIN_C  10
#define ECHO_PIN_C     9

#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar_A(TRIGGER_PIN_A, ECHO_PIN_A, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing sonar_B(TRIGGER_PIN_B, ECHO_PIN_B, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing sonar_C(TRIGGER_PIN_C, ECHO_PIN_C, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

const int numReadings = 300;

RunningAverage RA_A(10);
RunningAverage RA_B(10);
RunningAverage RA_C(10);


int index = 0; 

int total_A = 0; 
int total_B = 0; 
int total_C = 0; 

int average_A = 0;
int average_B = 0;
int average_C = 0;

unsigned int uS_A=0;
unsigned int uS_B=0;
unsigned int uS_C=0;
long duration, inches, cm;


void setup() {
  // initialize serial communication:
  Serial.begin(115200);
  
  RA_A.clear();  
  RA_B.clear();  
  RA_C.clear();  

}

void loop()
{
  delay(5);
  uS_A = sonar_A.ping(); // Send ping, get ping time in microseconds (uS).
  delay(5);
  uS_B = sonar_B.ping(); // Send ping, get ping time in microseconds (uS).
  delay(5);  
  uS_C = sonar_C.ping(); // Send ping, get ping time in microseconds (uS).
  delay(5);  
  
  RA_A.addValue((uS_A / US_ROUNDTRIP_CM)* 0.01);
  RA_B.addValue((uS_B / US_ROUNDTRIP_CM)* 0.01);
  RA_C.addValue((uS_C / US_ROUNDTRIP_CM)* 0.01);
  
  
  index++;

  if (index >= numReadings) 
  {
    index = 0;                             
    RA_A.clear();  
    RA_B.clear();  
    RA_C.clear();  
  }
  
  Serial.print("Ping: ");
  Serial.print(RA_A.getAverage());
  Serial.print(":");
  Serial.print(RA_B.getAverage());
  Serial.print(":");
  Serial.print(RA_C.getAverage());
  Serial.println(":");
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}


