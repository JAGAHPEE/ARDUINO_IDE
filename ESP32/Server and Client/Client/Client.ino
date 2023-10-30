#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const char* ssid = "ESP32-Soft-accessPoint";
const char* password = "microcontrollerslab";

const char* temperature_server = "http://192.168.4.1/temperature";
const char* humidity_server = "http://192.168.4.1/humidity";
const char* pressure_server = "http://192.168.4.1/pressure";

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire,-1);

String temperature;
String humidity;
String pressure;

unsigned long last_time = 0;
const long Delay = 10000; 

void setup() {
  Serial.begin(115200);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  
  display.clearDisplay();
  display.setTextColor(WHITE);
  
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  unsigned long current_time = millis();
  if(current_time - last_time >= Delay) {
    if(WiFi.status()== WL_CONNECTED ){ 
      temperature = HTTP_Request(temperature_server);
      humidity = HTTP_Request(humidity_server);
      pressure = HTTP_Request(pressure_server);
      Serial.println("Temperature: " + temperature + " *C - Humidity: " + humidity + " % - Pressure: " + pressure + " hPa");
      
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0,0);
      display.print("Temperature: ");
      display.print(temperature);
      display.print(" ");
      display.setTextSize(1);
      display.cp437(true);
      display.write(248);
      display.setTextSize(1);
      display.print("C");
      
      display.setTextSize(1);
      display.setCursor(0, 25);
      display.print("Humidity: ");
      display.print(humidity);
      display.print(" %"); 
      
      display.setTextSize(1);
      display.setCursor(0, 50);
      display.print("Pressure: ");
      display.print(pressure);
      display.print(" hPa"); 
         
      display.display();
      
      last_time = current_time;
    }
    else {
      Serial.println("WiFi got disconnected!");
    }
  }
}

String HTTP_Request(const char* server_name) {
  WiFiClient client;
  HTTPClient http;
  http.begin(client, server_name);
  int httpResponseCode = http.GET();
  
  String payload = "--"; 
  
  if (httpResponseCode>0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  http.end();

  return payload;
}
