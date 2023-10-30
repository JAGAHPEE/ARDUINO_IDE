//-----------------------------------------------------------
//ESP-NOW: Receiver
//Ref: Random Nerd Tutorials https://randomnerdtutorials.com
//-----------------------------------------------------------
#include <esp_now.h>
#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
//-------------------------------------------------------------------------------------
Adafruit_SSD1306 display(128, 64, &Wire, -1);
//-------------------------------------------------------------------------------------
typedef struct RxStruct
{
  int potVal;
}RxStruct;
RxStruct receivedData;
//-------------------------------------------------------------------------------------
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len)
{
  memcpy(&receivedData, incomingData, sizeof(receivedData));
}
//======================================================================================
void setup()
{
  Serial.begin(9600);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) 
  {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  display.clearDisplay();
  //-------------------------------------------------------------------------------------
  WiFi.mode(WIFI_STA);
  if (esp_now_init() != ESP_OK)
  {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  esp_now_register_recv_cb(OnDataRecv);
}
//======================================================================================
void loop()
{
  display.setTextColor(WHITE); display.clearDisplay();
  display.setTextSize(2); display.setCursor(20,0); display.print("ESP-NOW");
  display.setCursor(10,18); display.print("POT Value");
  display.setTextSize(3); display.setCursor(25,42); display.print(receivedData.potVal);
  Serial.println(receivedData.potVal);
  display.display();
}