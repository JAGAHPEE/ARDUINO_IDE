#include <Servo.h>
int pirValue;                   // Place to store read PIR Value
int pinValue;                   //Variable to read virtual pin
#define pirPin 5                // Input for HC-S501
int angle = 0;          // the current angle of servo motor
const int SERVO_PIN         = 4; // Arduino pin connected to servo motor's pin
Servo servo; // create servo object to control a servo

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(10);
  servo.attach(SERVO_PIN);
}

void loop() {

  pirValue = digitalRead(pirPin);
  Serial.println(pirValue);
  delay(100);
  if (pirValue)
  {
    Serial.println("Baby is Moving");
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

}
