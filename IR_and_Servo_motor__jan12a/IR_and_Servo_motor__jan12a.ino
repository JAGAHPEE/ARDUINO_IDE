#include<Servo.h>
int ir = 5;
int angle = 0;
int motion;
Servo servo;

void setup() {
  Serial.begin(9600);
  delay(10);
  servo.attach(6);
  pinMode(ir, INPUT);
  servo.write(90);
}

void loop()
{
  baby_cradel();
}

void baby_cradel() {
  motion = digitalRead(ir);
  Serial.print("Motion =");
  Serial.println(motion);
  delay(100);
  if (motion == 0)
  {
    for (angle = 90; angle <= 130;)
    {
      servo.write(angle);
      delay(100);
      angle = angle + 10;
    }
    delay(100);
    for (angle = 130; angle >= 50;)
    {
      servo.write(angle);
      angle = angle - 20;
      delay(100);
    }
    delay(100);
    for (angle = 50; angle <= 130;)
    {
      servo.write(angle);
      angle = angle + 20;
      delay(100);
    }
    delay(100);
    for (angle = 130; angle >= 50;)
    {
      servo.write(angle);
      angle = angle - 20;
      delay(100);
    }
    delay(100);
    for (angle = 50; angle <= 130;)
    {
      servo.write(angle);
      angle = angle + 20;
      delay(100);
    }
    delay(100);
    for (angle = 130; angle >= 50;)
    {
      servo.write(angle);
      angle = angle - 20;
      delay(100);
    }
    for (angle = 50; angle <= 90;)
    {
      servo.write(angle);
      angle = angle + 10;
      delay(100);
    }

  }


}
