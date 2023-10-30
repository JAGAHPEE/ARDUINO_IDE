#include <Servo.h>
const int SERVO_PIN         = 4; // Arduino pin connected to servo motor's pin
Servo servo; // create servo object to control a servo
int angle = 0;          // the current angle of servo motor

void setup()
{
  servo.attach(SERVO_PIN);           // attaches the servo on pin 9 to the servo object

}

void loop() {
  for (angle = 0; angle <= 180;)
  {
    servo.write(angle);
    angle = angle + 10;
  }
  for (angle = 180; angle >= 0;)
  {
    servo.write(angle);
    angle = angle - 10;
  }

}
