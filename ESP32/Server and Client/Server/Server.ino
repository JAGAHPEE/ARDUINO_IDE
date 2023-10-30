#include "WiFi.h"
#include "ESPAsyncWebServer.h"
#include <Wire.h>

const char* ssid = "LAPTOP";
const char* password = "78799008333";

AsyncWebServer server(80);

int value=0;
String states() {
  return String(value);
}



#define switch 9;
void setup(){
  Serial.begin(115200);
  Serial.println();
  Serial.println("Setting soft access point mode");
  WiFi.softAP(ssid, password);
  pinMode(switch, INPUT);
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  server.begin();
  server.on("/state", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", states.c_str());
  });
}
 
void loop(){
  value =digitalRead(switch);
  delay(5000);

}