#include <Wire.h>
byte sensor = 2; //hall effect sensor
int RPM = 0;
int count = 0;
int totRPM = 0;
int avgRPM = 0;
byte lastReading;
byte reading;
unsigned long stateChangeTime;
unsigned long previousStateChangeTime;
unsigned long duration;
unsigned long lastDisplay;
boolean newDurationValue = false;

void setup() {
  pinMode (sensor, INPUT_PULLUP);
  Serial.begin(115200);
}
void loop() {

  lastReading = reading;
  reading = digitalRead(sensor);
  if (reading == LOW && lastReading == HIGH)
  {
    stateChangeTime = micros();
    duration = stateChangeTime - previousStateChangeTime;
    previousStateChangeTime = stateChangeTime;
    count++;
  }

  if (micros() - stateChangeTime >= 5000000) //5 seconds without a transition
  {
    RPM = 0;//unclear what you want to do with tot and avg at this point
    avgRPM = 0;
  }
  else if(count)
  {
    count = 0;
    RPM = 60000000 / duration;
   //create moving average of 6 values
    avgRPM = (avgRPM * 5 + RPM)/6;
  } 

  if (millis() - lastDisplay >= 1000)
  {
     Serial.print ("avgRPM ");
     Serial.println (RPM);
    

    lastDisplay += 1000;
  }
}
