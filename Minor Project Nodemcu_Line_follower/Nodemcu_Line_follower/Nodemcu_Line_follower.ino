#include <BearSSLHelpers.h>
#include <CertStoreBearSSL.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiClientSecureAxTLS.h>
#include <WiFiClientSecureBearSSL.h>
#include <WiFiServer.h>
#include <WiFiServerSecure.h>
#include <WiFiServerSecureAxTLS.h>
#include <WiFiServerSecureBearSSL.h>
#include <WiFiUdp.h>
// Black Line Follower 
#define IR1 D0      //Right sensor
#define IR2 D1      //Middle Sensor
#define IR3 D2      //Left Sensor
#define MotorAip1 D3
#define MotorAip2 D4
// motor two

//Left motor
#define MotorBip1 D5
#define MotorBip2 D6
void setup() 
{
  pinMode(IR1,INPUT);
  pinMode(IR2,INPUT);
  pinMode(IR3,INPUT);
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

//   if(digitalRead(IR1)==1 && digitalRead(IR2)==1&& digitalRead(IR3)==1) //IR will not glow on black line
//  {
//    //Stop both Motors
//    digitalWrite(MotorAip1,LOW);
//    digitalWrite(MotorAip2,LOW);
//    digitalWrite(MotorBip1,LOW);
//    digitalWrite(MotorBip2,LOW);
//    lcd.clear();
//    lcd.print("Stop");
//    delay(500);
//  }

   if(digitalRead(IR1)==0 && digitalRead(IR2)==1&& digitalRead(IR3)==0)  //IR not on black line
  {
    //Move both the Motors
    digitalWrite(MotorAip1,HIGH);
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,HIGH);
    digitalWrite(MotorBip2,LOW);

  }

  else if(digitalRead(IR1)==1 && digitalRead(IR2)==0 && digitalRead(IR3)==0)
  {
     digitalWrite(MotorAip1,HIGH);     
     digitalWrite(MotorAip2,HIGH);
     digitalWrite(MotorBip1,HIGH);
     digitalWrite(MotorBip2,LOW);
  }

  else if(digitalRead(IR1)==0 && digitalRead(IR2)==0&& digitalRead(IR3)==1)
  {
    digitalWrite(MotorAip1,HIGH);   
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,HIGH);
    digitalWrite(MotorBip2,HIGH);
  
  }

//  else
//  {
//    //Stop both the motors
//    lcd.clear();
//    lcd.print("Stop");
//    delay(500);
//    digitalWrite(MotorAip1,LOW);
//    digitalWrite(MotorAip2,LOW);
//    digitalWrite(MotorBip1,LOW);
//    digitalWrite(MotorBip2,LOW);
//
//  }

}
