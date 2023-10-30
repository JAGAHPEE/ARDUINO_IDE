#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,5,4,3,2);
char phone_no[] = "9424029335";
char phone_no1[] = "8982505767";

int relay=11;
int t, s, q = 0;
unsigned char  da8[100];
void setup() 
{
  pinMode(relay,OUTPUT);
  digitalWrite(relay,LOW);
  
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("WELCOME TO IIST");
  lcd.setCursor(0,1);
  lcd.print("INDORE");
  delay(2000);
  lcd.clear();
}
void loop() 
{

  if (Serial.available() )
  {
    if (Serial.read() == 'R')
    {
      for (t = 0; t < 45; t++)
      {
        while (!Serial.available() ) ;

        da8[t] = Serial.read();
        // Serial.write(da8[t]);
      }
      lcd.setCursor(0, 0);
      lcd.print("lt=");
      Serial.println("lt=");
      lcd.setCursor(3, 0);
      for (t = 15; t < 28; t++)
      {
        Serial.write(da8[t]);
        lcd.write(da8[t]);
      }
      lcd.setCursor(0, 1);
      lcd.print("lg=");
      Serial.println("lg=");
      lcd.setCursor(3, 1);
      for (t = 28; t < 43; t++)
      {
        Serial.write(da8[t]);
        lcd.write(da8[t]);
      }
    }
  }
  

delay(100);
lcd.clear();
}

void SendMessage()
{
  Serial.println("AT+CMGF=1");
  delay(2000);
  Serial.print("AT+CMGS=");
  Serial.write(0x22);
  Serial.print(phone_no);
  Serial.write(0x22);
  Serial.write(0x0D);  // hex equivalent of Carraige return
  Serial.write(0x0A);  // hex equivalent of newline
  delay(2000);
  //serialSIM800.print("ACCIDENT vehicle is at google.com/maps/place/");
  lcd.setCursor(0, 0);
  lcd.print("lt=");
  Serial.println("unsafe situation help required  at google.com/maps/place/");
  lcd.setCursor(3, 0);
  for (t = 15; t < 28; t++)
  {
    Serial.write(da8[t]);
    lcd.write(da8[t]);
  }
  lcd.setCursor(0, 1);
  lcd.print("lg=");
  Serial.println(",");
  lcd.setCursor(3, 1);
  for (t = 28; t < 43; t++)
  {
    Serial.write(da8[t]);
    lcd.write(da8[t]);
  }
  delay(500);
  Serial.println(char(26));//the ASCII code of the ctrl+z is 26
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("help required");
  delay(2000);
}
void SendMessage1()
{
  Serial.println("AT+CMGF=1");
  delay(2000);
  Serial.print("AT+CMGS=");
  Serial.write(0x22);
  Serial.print(phone_no1);
  Serial.write(0x22);
  Serial.write(0x0D);  // hex equivalent of Carraige return
  Serial.write(0x0A);  // hex equivalent of newline
  delay(2000);
  //serialSIM800.print("ACCIDENT vehicle is at google.com/maps/place/");
  lcd.setCursor(0, 0);
  lcd.print("lt=");
  Serial.println("unsafe situation help required1  at google.com/maps/place/");
  lcd.setCursor(3, 0);
  for (t = 15; t < 28; t++)
  {
    Serial.write(da8[t]);
    lcd.write(da8[t]);
  }
  lcd.setCursor(0, 1);
  lcd.print("lg=");
  Serial.println(",");
  lcd.setCursor(3, 1);
  for (t = 28; t < 43; t++)
  {
    Serial.write(da8[t]);
    lcd.write(da8[t]);
  }
  delay(500);
  Serial.println(char(26));//the ASCII code of the ctrl+z is 26
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("help required1");
  delay(2000);
}
