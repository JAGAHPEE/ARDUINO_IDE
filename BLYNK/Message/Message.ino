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


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "LAPTOP";
char pass[] = "78799008333";

WidgetLED led1(V1);

BlynkTimer timer;

// V1 LED Widget is blinking
void blinkLedWidget()
{
  if (led1.getValue()) {
    led1.off();
    Serial.println("LED on V1: off");
   
  } else {
    led1.on();
    Serial.println("LED on V1: on");
  }
   Blynk.logEvent("LED is off");
}

void setup()
{
  // Debug console
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);

  timer.setInterval(1000L, blinkLedWidget);
}

void loop()
{
  Blynk.run();
  timer.run();
}
