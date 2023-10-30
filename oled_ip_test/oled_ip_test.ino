#include <ESP8266WiFi.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
char ch[12]="";
WiFiClient client;
WiFiServer server(80);
String request;
int MotorAip1 = D6;
int MotorAip2 = D5;
// motor two

void frw();
void rgt();
void rw();
void stp();
void lft();
//Left motor
int MotorBip1 = D4;
int MotorBip2 = D3;
int led = D0;
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin("LAPTOP", "7879900833");
  Serial.begin(115200);
  delay(100);

  // initialize the button pin as a input:

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Address 0x3C for 128x32

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer.
  display.clearDisplay();

  // We start by connecting to a WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print("Connected to ");
  display.setCursor(0,16);
  display.print("IP address: ");
  long int ip=WiFi.localIP();
  display.println(ip);
  display.display();
  delay(2000);
}
void loop()
{

}
