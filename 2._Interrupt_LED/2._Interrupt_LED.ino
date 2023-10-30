#include<TimerOne.h>
String LEDStatus="OFF";
int RED=9;
int YELLOW=10;

void setup() {
  pinMode(RED,OUTPUT);
  pinMode(YELLOW,OUTPUT);
  Timer1.initialize(250000);   //Units are n microsecond
  Timer1.attachInterrupt(Blink_yellow);
}

void loop() {
  delay(250);
  digitalWrite(RED,HIGH);
  delay(250);
  digitalWrite(RED,LOW);
  
}
void Blink_yellow()
{
  if(LEDStatus=="ON")
  {
    digitalWrite(YELLOW,LOW);
    LEDStatus="OFF";
    return;
  }

  if(LEDStatus=="OFF")
  {
    digitalWrite(YELLOW,HIGH);
    LEDStatus="ON";
  }
}
