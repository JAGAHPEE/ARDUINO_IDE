
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

void setup() 
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  
}
void loop() 
{
  display.setTextSize(2.5);
  display.setTextColor(WHITE);
  display.setCursor(25,10);
  display.println("Pi-Tech");
  display.display();
}
