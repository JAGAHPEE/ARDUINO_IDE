/*************************************************************

  Blynk using a LED widget on your phone!

  App project setup:
    LED widget on V1
 *************************************************************/

// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID "TMPLebsVk5uE"
#define BLYNK_DEVICE_NAME "LED"
#define BLYNK_AUTH_TOKEN "nNI5nM7QZy608wLogUGID5ybKOS2vCxW"


// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial

#define IR1 36
#define IR2 39
#define IR3 34
#define IR4 35
#define IR5 32
#define IR6 33
#define IR7 25
#define IR8 26
#define Buzzer 27
#define B_LED 2

int pos = 0;
int Total = 6;
int slot;
int f, g;

int s1 = 0;
int s2 = 0;
int s3 = 0;
int s4 = 0;
int s5 = 0;
int s6 = 0;
int s7 = 0;
int s8 = 0;
int s = 0;

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "LAPTOP";
char pass[] = "78799008333";
BlynkTimer timer;
WidgetLCD lcd(V0);
void control_function() {
  s1 = digitalRead(IR1) == 0 ? 1 : 0;
  s2 = digitalRead(IR2) == 0 ? 1 : 0;
  s3 = digitalRead(IR3) == 0 ? 1 : 0;
  s4 = digitalRead(IR4) == 0 ? 1 : 0;
  s5 = digitalRead(IR5) == 0 ? 1 : 0;
  s6 = digitalRead(IR6) == 0 ? 1 : 0;

  Blynk.virtualWrite(V2, s1);
  Blynk.virtualWrite(V3, s2);
  Blynk.virtualWrite(V4, s3);
  Blynk.virtualWrite(V5, s4);
  Blynk.virtualWrite(V6, s5);
  Blynk.virtualWrite(V7, s6);
  unsigned int q = s1 + s2 + s3 + s4 + s5 + s6;
  unsigned int st = s1 + s2 + s3 + s4 + s5 + s6;
  q=6-q;
  lcd.clear();
  lcd.print(0,0,"Smrt Car Parking");
  lcd.print(0,1,"Space Left :");
  lcd.print(13,1,q);
  Blynk.virtualWrite(V9, st);
  Blynk.virtualWrite(V1, q);
  

}




void setup() {
  // Debug console
  Serial.begin(115200);

  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR4, INPUT);
  pinMode(IR5, INPUT);
  pinMode(IR6, INPUT);
  pinMode(IR7, INPUT);
  pinMode(IR8, INPUT);

  pinMode(B_LED, OUTPUT);
  pinMode(Buzzer, OUTPUT);

  Blynk.begin(auth, ssid, pass);
  timer.setInterval(3000L, control_function);
}

void loop() {
  Blynk.run();
  timer.run();
}
int Sensor_data() {
  s1 = digitalRead(IR1) == 0 ? 1 : 0;
  s2 = digitalRead(IR2) == 0 ? 1 : 0;
  s3 = digitalRead(IR3) == 0 ? 1 : 0;
  s4 = digitalRead(IR4) == 0 ? 1 : 0;
  s5 = digitalRead(IR5) == 0 ? 1 : 0;
  s6 = digitalRead(IR6) == 0 ? 1 : 0;
  s7 = digitalRead(IR7) == 0 ? 1 : 0;
  s8 = digitalRead(IR8) == 0 ? 1 : 0;
  unsigned int q = s1 + s2 + s3 + s4 + s5 + s6;
  return q;
}
void BL_indication() {
  digitalWrite(B_LED, HIGH);
  digitalWrite(Buzzer, HIGH);
  delay(250);
  digitalWrite(B_LED, LOW);
  digitalWrite(Buzzer, LOW);
  delay(250);
}
void BL_Alert() {
  digitalWrite(B_LED, HIGH);
  digitalWrite(Buzzer, HIGH);
  delay(150);
  digitalWrite(B_LED, LOW);
  digitalWrite(Buzzer, LOW);
  delay(150);
}