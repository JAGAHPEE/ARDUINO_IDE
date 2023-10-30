#include <Servo.h>
Servo myservo;

int pirPin=5;
int angle = 0;  // servo position in degrees
int pos = 0;
int pirValue;                   // Place to store read PIR Value
int pinValue;                   //Variable to read virtual pin
Servo servo;

void setup()
{
  Serial.begin(9600);
  myservo.attach(6);  // attaches the servo on pin 9 to the servo object
  pinMode(pirPin, INPUT);
}
void loop() {
  pirValue = digitalRead(pirPin);
  Serial.println(pirValue);
  Serial.println("Motion detected");

  if (pinValue == 1)
  {
    Run_Servo();
  }
  else
  {
    
  }
  pirValue = 0;
  delay(5000);
}
void Run_Servo(void)        //Get PIR Data
{
  Serial.println(pirValue);
  Serial.println("Motion detected");

  for (angle = 0; angle <= 180; angle++)
  {
    servo.write(angle);
    //delay(30);
  }
  delay(100);
  for (angle = 180; angle >= 0; angle--)
  {
    servo.write(angle);
    //delay(30);
  }
  delay(3000);
}
