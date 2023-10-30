#include <ESP32Servo.h>
#include <analogWrite.h>
#include <ESP32Tone.h>
#include <ESP32PWM.h>

#include <WiFi.h>
Servo myservo1;

int IR1 = 2;
int IR2 = 15;

int Total = 5;
int Space;

int flag1 = 0;
int flag2 = 0;

void setup() {
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);

  myservo1.attach(25);
  myservo1.write(100);

  Serial.begin(115200);
  Space = Total;
}

void loop() {

  if (digitalRead (IR1) == LOW && flag1 == 0) {
    if (Space > 0) {
      flag1 = 1;
      if (flag2 == 0) {
        myservo1.write(0);
        Space = Space - 1;
      }
    } else {
      Serial.println("No Space");
    }
  }

  if (digitalRead (IR2) == LOW && flag2 == 0) {
    flag2 = 1;
    if (flag1 == 0) {
      myservo1.write(0);
      Space = Space + 1;
    }
  }

  if (flag1 == 1 && flag2 == 1) {
    delay (1000);
    myservo1.write(100);
    flag1 = 0, flag2 = 0;
  }
  Serial.print("Total Space: ");
  Serial.println(Total);
  Serial.println(Space);
}
