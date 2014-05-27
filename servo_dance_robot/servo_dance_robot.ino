// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;

int pos = 0;
int pos1 = 0;
int pos2 = 0;
int pos3 = 0;
int pos4 = 0;
 
void setup() 
{ 
  myservo1.attach(4); 
  myservo2.attach(5); 
  myservo3.attach(6); 
  myservo4.attach(7); 
  
    myservo1.write(0);
    myservo2.write(0);
    myservo3.write(0);
    myservo4.write(0);
  
} 
 
 
void loop() 
{ 
  pos1 =0;
  pos2 =100;
  pos3 = 100;
  pos4 = 100;
  
  for(pos = 0; pos < 100; pos += 1)  
  {                     
    pos2--;
    myservo2.write(pos2);
    delay(5);                       
  } 
    
  for(pos = 0; pos < 100; pos += 1)  
  {                     
    pos3--;
    myservo3.write(pos3);
    delay(10);                       
  } 
    
  for(pos = 0; pos < 100; pos += 1)  
  {                     
    pos4--;
    myservo4.write(pos4);
    delay(5);                       
  }

  for(pos = 0; pos < 100; pos += 1)  
  {                     
    pos1++;    
    myservo1.write(pos1);
    delay(10);                       
  } 
  
    
    
  for(pos = 100; pos>=1; pos-=1)     
  {                                
    pos3++;
    myservo3.write(pos3);
    delay(5);                       
  } 
  for(pos = 100; pos>=1; pos-=1)     
  {                                
    pos1--;    
    myservo1.write(pos1);
    delay(5);                       
  } 

  for(pos = 100; pos>=1; pos-=1)     
  {                                
    pos2++;
    myservo2.write(pos2);
    delay(5);                       
  } 

  for(pos = 100; pos>=1; pos-=1)     
  {                                
    pos4++;
    myservo4.write(pos4);
    
    delay(10);                       
  } 
  


//-----------------------  
  for(pos = 0; pos < 100; pos += 1)  
  {                     
    pos2--;
    myservo2.write(pos2);
    pos3--;
    myservo3.write(pos3);
    pos4--;
    myservo4.write(pos4);
    pos1++;    
    myservo1.write(pos1);
    delay(10);                       
  } 
  
  
  for(pos = 100; pos>=1; pos-=1)     
  {                                
    pos3++;
    myservo3.write(pos3);
    pos1--;    
    myservo1.write(pos1);
    pos2++;
    myservo2.write(pos2);
    pos4++;
    myservo4.write(pos4);
    
    delay(10);                       
  } 
  
} 
