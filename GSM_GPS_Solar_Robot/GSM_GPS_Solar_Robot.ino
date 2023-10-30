#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,5,4,3,2);
char phone_no[] = "9424029335";
char phone_no1[] = "8982505767";
int inputPin=16;  // connect digital I/O d4 to the ECHO/Rx Pin
int outputPin=17; // connect digital I/O d5 to the TRIG/TX Pin
// Black Line Follower 
int MotorAip1=11;
int MotorAip2=10;

// motor two
//Left motor
int MotorBip1=9;
int MotorBip2=8;
int t, s, q = 0;
unsigned char  da8[100];
void setup() 
{
  pinMode(inputPin, INPUT);
  pinMode(outputPin, OUTPUT);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("WELCOME TO IIST");
  lcd.setCursor(0,1);
  lcd.print("INDORE");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Object Avoiding");
  lcd.setCursor(0,1);
  lcd.print("Solar Robot ");
  delay(2000);
  lcd.clear();
  pinMode(MotorAip1,OUTPUT);
  pinMode(MotorAip2,OUTPUT);
  pinMode(MotorBip1,OUTPUT);
  pinMode(MotorBip2,OUTPUT);
  digitalWrite(MotorAip1,LOW);
  digitalWrite(MotorAip2,LOW);
  digitalWrite(MotorBip1,LOW);
  digitalWrite(MotorBip2,LOW);
}
void loop() 
{
   digitalWrite(outputPin, LOW);  // send low pulse for 2μs
   delayMicroseconds(2);
   digitalWrite(outputPin, HIGH); // send high pulse for 10μs
   delayMicroseconds(10);
   digitalWrite(outputPin, LOW);  // back to low pulse
   int distance = pulseIn(inputPin, HIGH);  // read echo value
   int distance1= distance/29/2;  // in cm
   
   lcd.setCursor(0, 0);
   lcd.print("S1=");
   lcd.print(distance1);
   lcd.print("cm ");
   delay(500);
   lcd.clear();
     int byte = 0;
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


   if(distance1<40)  //IR not on black line
  {
    //Move both the Motors
    lcd.print("Object Detected");
        //Stop both Motors
    digitalWrite(MotorAip1,LOW);
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,LOW);
    delay(2000);
    digitalWrite(MotorAip1,HIGH);
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,HIGH);
    SendMessage();
    SendMessage1();

  }

  else 
  {
     lcd.print("Forward");
     digitalWrite(MotorAip1,HIGH);     
     digitalWrite(MotorAip2,LOW);
     digitalWrite(MotorBip1,HIGH);
     digitalWrite(MotorBip2,LOW);
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
