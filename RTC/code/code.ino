// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
#include <Wire.h>
#include "RTClib.h"
#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,10,11,12,13);
int led1=5;
int led2=6;
int led3=7;
RTC_DS1307 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup () {
  while (!Serial); // for Leonardo/Micro/Zero
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("WELCOME TO IIST");
  lcd.setCursor(0,1);
  lcd.print("INDORE");
  delay(1000);
  lcd.clear();
  Serial.begin(57600);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    rtc.adjust(DateTime(2022,07,29,15,15,0));

  }
}

void loop () {
  DateTime now = rtc.now();

  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" (");
  Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
  Serial.print(") ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();

  
  lcd.setCursor(0,0);
  lcd.print(now.hour());
  
  lcd.setCursor(2,0);
  lcd.print(":");
  
  lcd.setCursor(3,0);
  lcd.print(now.minute());
  
  lcd.setCursor(5,0);
  lcd.print(":");
  
  lcd.setCursor(6,0);
  lcd.print(now.second());
  
  lcd.setCursor(0,1);
  lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);


  
  Serial.println("\n");
  if(now.minute()>32)
  {
    digitalWrite(led1,HIGH);
  }
  if(now.minute()>33)
  {
    digitalWrite(led2,HIGH);
  }
  if(now.minute()>34)
  {
    digitalWrite(led3,HIGH);
  }
  if(now.minute()>45)
  {
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
  }
  delay(1000);
  lcd.clear();
}
