// Viral Science www.viralsciencecreativity.com www.youtube.com/c/viralscience
// Arduino Car Parking System

#include <Wire.h>
#include <ESP32Servo.h>
Servo myservo1;

int IR1 = 34;
int IR2 = 35;

int Slot = 4;           //Enter Total number of parking Slots

int flag1 = 0;
int flag2 = 0;

void setup() {
  Serial.begin(115200);
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);

  myservo1.attach(33);
  myservo1.write(100);

}

void loop() {

  if (digitalRead (IR1) == LOW && flag1 == 0) {
    if (Slot > 0) {
      flag1 = 1;
      if (flag2 == 0) {
        myservo1.write(0);
        delay(500);
        Slot = Slot - 1;
      }
    } else {
    }
  }

  if (digitalRead (IR2) == LOW && flag2 == 0) {
    flag2 = 1;
    if (flag1 == 0) {
      myservo1.write(0);
      delay(500);
      Slot = Slot + 1;
    }
  }

  if (flag1 == 1 && flag2 == 1) {
    myservo1.write(100);
    delay (1000);
    Serial.print("Open");

    flag1 = 0, flag2 = 0;
  }


  Serial.print("Slot Left: ");
  Serial.println(Slot);
  delay(1000);
}
