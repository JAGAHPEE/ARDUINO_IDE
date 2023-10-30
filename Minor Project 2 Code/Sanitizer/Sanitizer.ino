#include <Servo.h>
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int IR1=5;      //Right sensor
int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(6);  // attaches the servo on pin 9 to the servo object
   myservo.write(10);
   pinMode(IR1,INPUT);
}

void loop() {
if(digitalRead(IR1)==0)
{
  delay(150); 
  myservo.write(90); 
  delay(500); 
  myservo.write(180);
  delay(500); 
}
else
{
  myservo.write(90);
}
 
   
}
