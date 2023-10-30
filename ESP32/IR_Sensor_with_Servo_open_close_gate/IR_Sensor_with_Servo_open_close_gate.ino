#define IR1 34
#define IR2 35
#include <ESP32Servo.h>

Servo myservo;

int pos = 0;
int Total = 6;
int Space;
int Slot = 6;           //Enter Total number of parking Slots

int flag1 = 0;
int flag2 = 0;

void setup() {
  Serial.begin(115200);
  myservo.attach(33);
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
}

void loop() {

  if (digitalRead (IR1) == LOW && flag1 == 0) {
    if (Slot > 0) {
      flag1 = 1;
      if (flag2 == 0) {
        myservo.write(0);
        Slot = Slot - 1;
      }
    } else {
      delay (3000);

    }
  }

  if (digitalRead (IR2) == LOW && flag2 == 0) {
    flag2 = 1;
    if (flag1 == 0) {
      myservo.write(0);
      Slot = Slot + 1;
    }
  }

  if (flag1 == 1 && flag2 == 1) {
    delay (1000);
    myservo.write(100);
    flag1 = 0, flag2 = 0;
  }
  Serial.print("Total Space: ");
  Serial.println(Total);
  Serial.println("Space: ");
  Serial.println(Slot);
  delay(800);
}
