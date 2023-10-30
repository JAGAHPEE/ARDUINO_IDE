#define IR1 34
#define IR2 35
#include <ESP32Servo.h>

Servo myservo;
int pos = 0;
int Total = 6;
int slot;
int f, g;
void setup()
{
  Serial.begin(115200);
  myservo.attach(33);
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  slot = Total;
  myservo.write(0);
  f = 0;
  g = 0;
}
void loop()
{
  if (digitalRead(IR1) == 0)
  {
    if (slot > 0 && slot <= 6)
    {
      f = 1;
      slot = slot - 1;
    }
    delay(50);
  }
  else if (digitalRead(IR2) == 0)
  {
    if (slot >= 0 && slot < 6)
    {
      f = 1;
      slot = slot + 1;
    }
    delay(50);
  }
  if (f == 1 || g == 1)
  { for (pos = 0; pos <= 100; pos += 5)
    {
      myservo.write(pos);
      delay(10);
    }
    if(f==1)
    {
      while((digitalRead(IR2)==0)||(digitalRead(IR1)==0))
      {
        delay(500);
      }
    }
    else if(g==1)
    {
      while(digitalRead(IR1)==0 || digitalRead(IR2)==0)
      {
        delay(500);
      }
    }
    for (pos = 100; pos >= 0; pos -= 5)
    {
      myservo.write(pos);
      delay(10);
    }
    f = 0;
    g = 0;
  }
  Serial.println(slot);
  delay(1000);
}
