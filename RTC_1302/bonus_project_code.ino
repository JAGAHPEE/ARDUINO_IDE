/*

Arduino Reminder

modified on 13 March 2019
by Saeed Hosseini @ Electropeak
https://electropeak.com/learn/

*/

#include <LiquidCrystal.h>
#include <Wire.h>
#include "RTClib.h"


#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_G5  784
#define NOTE_A5  880
#define NOTE_B5  988

//LCD Pin to Arduino
const int pin_RS = 8;
const int pin_EN = 9;
const int pin_d4 = 4;
const int pin_d5 = 5;
const int pin_d6 = 6;
const int pin_d7 = 7;
const int pin_BL = 10;
//BUZZER Pin to Arduino
const int buzzer = 2;  
                       
LiquidCrystal lcd( pin_RS,  pin_EN,  pin_d4,  pin_d5,  pin_d6,  pin_d7);
RTC_DS1307 rtc;

byte smiley[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
};


String menuItems[] = {"1-Medicin", "2-Wake up", "3-Go out"};

int songspeed = 1.5;

int flag = 0;
int menuPage = 0;
int maxMenuPages = round(((sizeof(menuItems) / sizeof(String)) / 2) + .5);
int cursorPosition = 0;
int btn;
int h = 0, m = 0;

int duration[] = {         //duration of each note (in ms) Quarter Note is set to 250 ms
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 125,

  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 125,

  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 125, 250, 125,

  125, 125, 250, 125, 125,
  250, 125, 250, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 375,

  250, 125,
  //Rpeat of First Part
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 125,

  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 125,

  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 125, 250, 125,

  125, 125, 250, 125, 125,
  250, 125, 250, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 375,
  //End of Repeat

  250, 125, 375, 250, 125, 375,
  125, 125, 125, 125, 125, 125, 125, 125, 375,
  250, 125, 375, 250, 125, 375,
  125, 125, 125, 125, 125, 500,

  250, 125, 375, 250, 125, 375,
  125, 125, 125, 125, 125, 125, 125, 125, 375,
  250, 125, 375, 250, 125, 375,
  125, 125, 125, 125, 125, 500
};


int notes[] = {       //Note of the song, 0 is a rest/pulse
  NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
  NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
  NOTE_A4, NOTE_G4, NOTE_A4, 0,

  NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
  NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
  NOTE_A4, NOTE_G4, NOTE_A4, 0,

  NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
  NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0,
  NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
  NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,

  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
  NOTE_D5, NOTE_E5, NOTE_A4, 0,
  NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
  NOTE_C5, NOTE_A4, NOTE_B4, 0,

  NOTE_A4, NOTE_A4,
  //Repeat of first part
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
  NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
  NOTE_A4, NOTE_G4, NOTE_A4, 0,

  NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
  NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
  NOTE_A4, NOTE_G4, NOTE_A4, 0,

  NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
  NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0,
  NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
  NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,

  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
  NOTE_D5, NOTE_E5, NOTE_A4, 0,
  NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
  NOTE_C5, NOTE_A4, NOTE_B4, 0,
  //End of Repeat

  NOTE_E5, 0, 0, NOTE_F5, 0, 0,
  NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0,
  NOTE_D5, 0, 0, NOTE_C5, 0, 0,
  NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4,

  NOTE_E5, 0, 0, NOTE_F5, 0, 0,
  NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0,
  NOTE_D5, 0, 0, NOTE_C5, 0, 0,
  NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4
};

void show_time()
{
  lcd.clear();
  DateTime now = rtc.now();
  lcd.setCursor(0, 0);
  lcd.print("* Electropeak *");
  lcd.setCursor(5, 0);
  lcd.print(now.hour(), DEC);
  lcd.print(":");
  lcd.print(now.minute(), DEC);
  if (now.hour() == h && now.minute() == m)
  {
    lcd.clear();
    lcd.setCursor(0 , 0);
    switch (flag)
    {
      case 1:
        lcd.print("** ءedicine Time **");
        break;
      case 2:
        lcd.print("You'r late!!");
        lcd.setCursor(0, 1);
        lcd.print("Come onnnnnnn");
        break;
      case 3:
        lcd.print("Befor you go:");
        lcd.setCursor(0, 1);
        lcd.print("Wallet,Keys,...");
        break;
    }
    for (int i = 0; i < 203; i++) {       //203 is the total number of music notes in the song
      int wait = duration[i] * songspeed;
      tone(buzzer, notes[i], wait);        //tone(pin,frequency,duration)
      delay(wait);
    }
  }
  delay(2000);
}

void welcome_menu(int show_delay)
{
  lcd.setCursor(0, 0);
  lcd.print("Arduino reminder");
  lcd.createChar(1, smiley);
  lcd.setCursor(7, 1);
  lcd.write(1);
  delay(show_delay);
  lcd.clear();
}

int detect_button() {

  int readkey = 0;
  int result = 0;
  int activeButton = 0;

  while (activeButton == 0) {
    readkey = analogRead(0);
    if (readkey < 790) {
      delay(100);
      readkey = analogRead(0);
      if (readkey < 60) {
        result = 1; // right
      } else if (readkey < 200) {
        result = 2; // up
      } else if (readkey < 400) {
        result = 3; // down
      } else if (readkey < 600) {
        result = 4; // down
      } else if (readkey < 800) { result = 5; // select } return result; } } activeButton = 1; } int choose_menu() { lcd.clear(); lcd.print("Remmeber what?"); while (btn != 5) { btn = detect_button(); if (btn == 1) { if (menuPage > maxMenuPages) menuPage = 0;
      lcd.clear();
      lcd.print("Remmeber what?");
      lcd.setCursor(0, 1);
      lcd.print(menuItems[menuPage]);
      menuPage = menuPage + 1;
    }
  }

  return menuPage;
}


void set_alarm() {
  int sit = 0;
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("**Set Alarm**");
  lcd.setCursor(5, 1);
  lcd.print("00:00");
  while (sit != 1)
  {
    sit = detect_button();

    if (sit == 2)
    {
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("**Set Alarm**");
      h++;
      if (h > 23)
      {
        h = 0;
      }
      lcd.setCursor(5, 1);
      lcd.print(h);
      lcd.print(":00");

    }
    else if (sit == 3)
    {
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("**Set Alarm**");
      h--;
      if (h < 0) { h = 23; } lcd.setCursor(5, 1); lcd.print(h); lcd.print(":00"); } } while (sit != 5) { sit = detect_button(); if (sit == 2) { lcd.clear(); lcd.setCursor(1, 0); lcd.print("**Set Alarm**"); m++; if (m > 59)
      {
        m = 0;
      }
      lcd.setCursor(5, 1);
      lcd.print(h);
      lcd.print(":");
      lcd.print(m);

    }
    else if (sit == 3)
    {
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("**Set Alarm**");
      m--;
      if (m < 0)
      {
        m = 59;
      }
      lcd.setCursor(5, 1);
      lcd.print(h);
      lcd.print(":");
      lcd.print(m);

    }
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Alarm set");
  lcd.setCursor(0, 1);
  lcd.print("I'll be on time");
  delay(1500);

}


void setup() {

  lcd.begin(16, 2);
  rtc.begin();
  pinMode(buzzer, OUTPUT);
  welcome_menu(1000);
  flag = choose_menu();
  set_alarm();



}
void loop()
{

  show_time();

}