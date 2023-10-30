//Tech Trends Shameer
//Control LED Using Blynk 2.0/Blynk IOT

#define BLYNK_TEMPLATE_ID "TMPLebsVk5uE"
#define BLYNK_DEVICE_NAME "LED"
#define BLYNK_AUTH_TOKEN "nNI5nM7QZy608wLogUGID5ybKOS2vCxW"


#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <SPI.h>
#include <Ethernet.h>
#include <BlynkSimpleEthernet.h>
 

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "LAPTOP";  // Enter your Wifi Username
char pass[] = "78799008333";  // Enter your Wifi password

int ledpin = 2;
void setup()
{     
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);    
  pinMode(ledpin,OUTPUT);
}

void loop()
{
  Blynk.run(); 
}
