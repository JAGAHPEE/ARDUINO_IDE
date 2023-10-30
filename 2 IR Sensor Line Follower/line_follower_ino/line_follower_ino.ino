#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,5,4,3,2);
// Black Line Follower 
int IR1=14;      //Right sensor
int IR2=15;    //left Sensor
int MotorAip1=11;
int MotorAip2=10;
// motor two

//Left motor
int MotorBip1=9;
int MotorBip2=8;
void setup() 
{

  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("WELCOME TO IIST");
  lcd.setCursor(0,1);
  lcd.print("INDORE");
  delay(2000);
  lcd.clear();
  pinMode(IR1,INPUT);
  pinMode(IR2,INPUT);
  pinMode(MotorAip1,OUTPUT);
  pinMode(MotorAip2,OUTPUT);
  pinMode(MotorBip1,OUTPUT);
  pinMode(MotorBip2,OUTPUT);
}
void loop() 
{

   if(digitalRead(IR1)==1 && digitalRead(IR2)==1) //IR will not glow on black line
  {
    //Stop both Motors
    digitalWrite(MotorAip1,LOW);
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,LOW);
    lcd.clear();
    lcd.print("Stop");
    delay(500);
  }

  else if(digitalRead(IR1)==0 && digitalRead(IR2)==0)  //IR not on black line
  {
    //Move both the Motors
    lcd.clear();
    lcd.print("Forward");
    delay(500);
    digitalWrite(MotorAip1,HIGH);
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,HIGH);
    digitalWrite(MotorBip2,LOW);

  }

  else if(digitalRead(IR1)==1 && digitalRead(IR2)==0)
  {
     lcd.clear();
     lcd.print("RIGHT");
     delay(500);
     Serial.print("RIGHT");
    digitalWrite(MotorAip1,HIGH);     
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,HIGH);
    delay(100);
  }

  else if(digitalRead(IR1)==0 && digitalRead(IR2)==1)
  {
    lcd.clear();
    lcd.print("Left");
    delay(500);
    digitalWrite(MotorAip1,LOW);   
    digitalWrite(MotorAip2,HIGH);
    digitalWrite(MotorBip1,HIGH);
    digitalWrite(MotorBip2,LOW);
    delay(100);
  }

  else
  {
    //Stop both the motors
    lcd.clear();
    lcd.print("Stop");
    delay(500);
    digitalWrite(MotorAip1,LOW);
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,LOW);

  }
}
