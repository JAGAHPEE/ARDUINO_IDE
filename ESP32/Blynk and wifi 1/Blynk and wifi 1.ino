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

#define SECRET_CH_ID 1848329                    // replace 0000000 with your channel number
#define SECRET_WRITE_APIKEY "UV8UYIV06BNT6K4J"  // replace XYZ with your channel write API Key
// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial

#define IR1 36
#define IR2 39
#define IR3 34
#define IR4 35
#define IR5 32
#define IR6 33
#define IR7 25
#define IR8 26
#define Buzzer 27
#define B_LED 2

int pos = 0;
int Total = 6;
int slot;
int f, g;

int s1 = 0;
int s2 = 0;
int s3 = 0;
int s4 = 0;
int s5 = 0;
int s6 = 0;
int s7 = 0;
int s8 = 0;
int s = 0;

#include "ThingSpeak.h"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcda(0x27, 20, 4);


char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "LAPTOP";
char pass[] = "78799008333";
BlynkTimer timer;
WidgetLCD lcd(V0);
void control_function() {
  s1 = digitalRead(IR1) == 0 ? 1 : 0;
  s2 = digitalRead(IR2) == 0 ? 1 : 0;
  s3 = digitalRead(IR3) == 0 ? 1 : 0;
  s4 = digitalRead(IR4) == 0 ? 1 : 0;
  s5 = digitalRead(IR5) == 0 ? 1 : 0;
  s6 = digitalRead(IR6) == 0 ? 1 : 0;

  Blynk.virtualWrite(V2, s1);
  Blynk.virtualWrite(V3, s2);
  Blynk.virtualWrite(V4, s3);
  Blynk.virtualWrite(V5, s4);
  Blynk.virtualWrite(V6, s5);
  Blynk.virtualWrite(V7, s6);
  unsigned int q = s1 + s2 + s3 + s4 + s5 + s6;
  unsigned int st = s1 + s2 + s3 + s4 + s5 + s6;
  q = 6 - q;
  lcd.clear();
  lcd.print(0, 0, "Smrt Car Parking");
  lcd.print(0, 1, "Space Left :");
  lcd.print(13, 1, q);
  Blynk.virtualWrite(V9, st);
  Blynk.virtualWrite(V1, q);
}
int keyIndex = 0;       

WiFiClient client;

WiFiServer server(80);

unsigned long myChannelNumber = SECRET_CH_ID;
const char* myWriteAPIKey = SECRET_WRITE_APIKEY;

void BL_indication();
void BL_Alert();

int Sensor_data();




void setup() {
  // Debug console
  Serial.begin(115200);

  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR4, INPUT);
  pinMode(IR5, INPUT);
  pinMode(IR6, INPUT);
  pinMode(IR7, INPUT);
  pinMode(IR8, INPUT);

  pinMode(B_LED, OUTPUT);
  pinMode(Buzzer, OUTPUT);

  Blynk.begin(auth, ssid, pass);
  timer.setInterval(3000L, control_function);
  slot = Total;


  //flank bit for door open and close
  f = 0;
  g = 0;

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    digitalWrite(B_LED, HIGH);
    digitalWrite(Buzzer, HIGH);
    delay(250);
    Serial.print(".");
    digitalWrite(B_LED, LOW);
    digitalWrite(Buzzer, LOW);
  }
  Serial.println("");
  Serial.println("WiFi Connected");
  digitalWrite(B_LED, HIGH);
  digitalWrite(Buzzer, HIGH);
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  delay(2000);
  digitalWrite(B_LED, LOW);
  digitalWrite(Buzzer, LOW);
  server.begin();
  ThingSpeak.begin(client);  // Initialize ThingSpeak
  delay(100);
}

void loop() {
  Blynk.run();
  timer.run();
  int x = digitalRead(IR1);
  int y = digitalRead(IR2);
  int z = digitalRead(IR3);
  int a = digitalRead(IR4);
  int b = digitalRead(IR5);
  int c = digitalRead(IR6);
  delay(10);
  // Write to ThingSpeak. There are up to 8 fields in a channel, allowing you to store up to 8 different
  // pieces of information in a channel.  Here, we write to field 1.

  ThingSpeak.setField(1, x);
  ThingSpeak.setField(2, y);
  ThingSpeak.setField(3, z);
  ThingSpeak.setField(4, a);
  ThingSpeak.setField(5, b);
  ThingSpeak.setField(6, c);
  delay(10);
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  delay(10);

  WiFiClient client = server.available();  // listen for incoming clients
  if (client) {                            // if you get a client,
    Serial.println("New Client.");         // print a message out the serial port
    String currentLine = "";               // make a String to hold incoming data from the client
    while (client.connected()) {           // loop while the client's connected
      if (client.available()) {            // if there's bytes to read from the client,
        char c = client.read();            // read a byte, then
        Serial.write(c);                   // print it out the serial monitor
        if (c == '\n') {                   // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");

            client.println();
            client.println("<html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link href=\"https://cdnjs.cloudflare.com/ajax/libs/animate.css/4.1.1/animate.min.css\" rel=\"stylesheet\">");
            client.println("<style>html {font-family: Arial, Helvetica, sans-serif;text-align: center;}h1 {font-size: 1.8rem;color: rgb(0, 0, 0);text-shadow: 2px 2px 7px grey;box-shadow: 2px 2px 7px grey;padding: 10px;font-family:Verdana;width: fit-content;margin: 3rem 0;}.animate__fadeInDown{animation-duration: 800ms;} .animate__fadeInRight,.animate__fadeInLeft,.animate__bounceInUp {animation-duration: 1500ms;}.wrapper {width: fit-content;align-items: center;justify-content: center;display: flex;flex-wrap: wrap;}.slot {background-color: rgb(204, 250, 250);width: 9rem;height: 11rem;overflow: hidden;}.area {width: fit-content;}.s1 {margin: 6px;box-shadow: 5px 5px 10px grey;}.car-image {width: 7rem;height: 7rem;padding-top: 2rem;filter: opacity(0.1) drop-shadow(0 0 0 rgba(0, 0, 0));transition: all .5s;}.car-image:hover{transform: scale(1.25);} .btn {margin-top: 30px;background-color: aqua;border: 0.5px solid rgb(208, 196, 196);border-radius: 5px;height: 3rem;text-decoration: none;transition: all 0.5s; padding: 0.8rem ;font-size: 1.2rem; cursor: pointer;}.btn:hover{box-shadow:5px 5px 10px grey;transform: translate(15px,15px) scale(1.15);}.line1,.line2{width: 29rem;height: 5px; }.line1{background-color: rgb(0, 0, 0);}@media(max-width:500px) {.slot {max-width: 6rem;height: 8rem;}.car-image {width: 5rem;height: 5rem;}.line1,.line2{width: 20rem;height: 3px; }h1{font-size: 1.3rem;}}</style></head>");
            client.println("<body onload = \"JavaScript:AutoRefresh(5000);\">");
            client.println("<center>");
            client.println("<h1 class=\"animate__fadeInDown\"\">SMART CAR PARKING SYSTEM USING IOT</h1>");
            client.println("<div class=\"area\"\"><div class=\"wrapper animate__fadeInLeft\"\">");

            if (digitalRead(IR1) == 0) {
              client.println("<div class=\"s1\"\"><div class=\"slot\"\" style=\"background-color: #ffcccc;\"\"><img src=\"https://github.com/JAGAHPEE/SMART-CAR-PARKING-SYSTEM-USING-IOT/blob/main/car-top-view.png?raw=true\"\" class=\"car-image\"\" alt="
                             "></div><p><b>Parked</b></p></div>");

            } else {
              client.println("<div class=\"s1\"\"><div class=\"slot\"\"><img src=\"https://github.com/JAGAHPEE/SMART-CAR-PARKING-SYSTEM-USING-IOT/blob/main/car-top-view.png?raw=true\"\" class=\"car-image\"\" alt="
                             " style=\"filter: opacity(0.6) drop-shadow(0 0 rgb(255, 0, 0));\"\"></div><p><b> Slot 1</b></p></div>");
            }
            if (digitalRead(IR2) == 0) {
              client.println("<div class=\"s1\"\"><div class=\"slot\"\" style=\"background-color: #ffcccc;\"\"><img src=\"https://github.com/JAGAHPEE/SMART-CAR-PARKING-SYSTEM-USING-IOT/blob/main/car-top-view.png?raw=true\"\" class=\"car-image\"\" alt="
                             "></div><p><b>Parked</b></p></div>");

            } else {
              client.println("<div class=\"s1\"\"><div class=\"slot\"\"><img src=\"https://github.com/JAGAHPEE/SMART-CAR-PARKING-SYSTEM-USING-IOT/blob/main/car-top-view.png?raw=true\"\" class=\"car-image\"\" alt="
                             " style=\"filter: opacity(0.6) drop-shadow(0 0 rgb(255, 0, 0));\"\"></div><p><b> Slot 2</b></p></div>");
            }
            if (digitalRead(IR3) == 0) {
              client.println("<div class=\"s1\"\"><div class=\"slot\"\" style=\"background-color: #ffcccc;\"\"><img src=\"https://github.com/JAGAHPEE/SMART-CAR-PARKING-SYSTEM-USING-IOT/blob/main/car-top-view.png?raw=true\"\" class=\"car-image\"\" alt="
                             "></div><p><b>Parked</b></p></div>");
            } else {
              client.println("<div class=\"s1\"\"><div class=\"slot\"\"><img src=\"https://github.com/JAGAHPEE/SMART-CAR-PARKING-SYSTEM-USING-IOT/blob/main/car-top-view.png?raw=true\"\" class=\"car-image\"\" alt="
                             " style=\"filter: opacity(0.6) drop-shadow(0 0 rgb(255, 0, 0));\"\"></div><p><b> Slot 3</b></p></div>");
            }

            client.println("</div></div>");

            client.println("<div class=\"line2\"\"></div>");
            client.println("<div class=\"line1 animate__bounceInUp\"\"></div>");
            client.println("<div class=\"line2\"\"></div>");

            client.println("<div class=\"area\"\"><div class=\"wrapper animate__fadeInRight\"\">");
            if (digitalRead(IR4) == 0) {
              client.println("<div class=\"s1\"\"><div class=\"slot\"\" style=\"background-color: #ffcccc;\"\"><img src=\"https://github.com/JAGAHPEE/SMART-CAR-PARKING-SYSTEM-USING-IOT/blob/main/car-top-view.png?raw=true\"\" class=\"car-image\"\" alt="
                             "></div><p><b>Parked</b></p></div>");

            } else {
              client.println("<div class=\"s1\"\"><div class=\"slot\"\"><img src=\"https://github.com/JAGAHPEE/SMART-CAR-PARKING-SYSTEM-USING-IOT/blob/main/car-top-view.png?raw=true\"\" class=\"car-image\"\" alt="
                             " style=\"filter: opacity(0.6) drop-shadow(0 0 rgb(255, 0, 0));\"\"></div><p><b> Slot 4</b></p></div>");
            }
            if (digitalRead(IR5) == 0) {
              client.println("<div class=\"s1\"\"><div class=\"slot\"\" style=\"background-color: #ffcccc;\"\"><img src=\"https://github.com/JAGAHPEE/SMART-CAR-PARKING-SYSTEM-USING-IOT/blob/main/car-top-view.png?raw=true\"\" class=\"car-image\"\" alt="
                             "></div><p><b>Parked</b></p></div>");
              s5 = 0;
            } else {
              client.println("<div class=\"s1\"\"><div class=\"slot\"\"><img src=\"https://github.com/JAGAHPEE/SMART-CAR-PARKING-SYSTEM-USING-IOT/blob/main/car-top-view.png?raw=true\"\" class=\"car-image\"\" alt="
                             " style=\"filter: opacity(0.6) drop-shadow(0 0 rgb(255, 0, 0));\"\"></div><p><b> Slot 5</b></p></div>");
            }
            if (digitalRead(IR6) == 0) {
              client.println("<div class=\"s1\"\"><div class=\"slot\"\" style=\"background-color: #ffcccc;\"\"><img src=\"https://github.com/JAGAHPEE/SMART-CAR-PARKING-SYSTEM-USING-IOT/blob/main/car-top-view.png?raw=true\"\" class=\"car-image\"\" alt="
                             "></div><p><b>Parked</b></p></div>");

            } else {
              client.println("<div class=\"s1\"\"><div class=\"slot\"\"><img src=\"https://github.com/JAGAHPEE/SMART-CAR-PARKING-SYSTEM-USING-IOT/blob/main/car-top-view.png?raw=true\"\" class=\"car-image\"\" alt="
                             " style=\"filter: opacity(0.6) drop-shadow(0 0 rgb(255, 0, 0));\"\"></div><p><b> Slot 6</b></p></div>");
            }
            client.println("</div></div>");
            client.println("<button onClick=\"window.location.href=window.location.href\"\" class=\"btn\"\"><b><i>Refresh</i></b></button>");
            client.println();
            client.println("<br>");
            client.println("<br>");
            client.println("<br>");


            client.println("</center>");
            client.println("</body>");
            client.println("</html>");
            client.println();
            client.println();
            // The HTTP response ends with another blank line:
            client.println();
            delay(10);
            // break out of the while loop:
            break;
          } else {  // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // close the connection:
    //    client.stop();
    Serial.println("Client Disconnected.");
  }
}
int Sensor_data() {
  s1 = digitalRead(IR1) == 0 ? 1 : 0;
  s2 = digitalRead(IR2) == 0 ? 1 : 0;
  s3 = digitalRead(IR3) == 0 ? 1 : 0;
  s4 = digitalRead(IR4) == 0 ? 1 : 0;
  s5 = digitalRead(IR5) == 0 ? 1 : 0;
  s6 = digitalRead(IR6) == 0 ? 1 : 0;
  s7 = digitalRead(IR7) == 0 ? 1 : 0;
  s8 = digitalRead(IR8) == 0 ? 1 : 0;
  unsigned int q = s1 + s2 + s3 + s4 + s5 + s6;
  return q;
}
void BL_indication() {
  digitalWrite(B_LED, HIGH);
  digitalWrite(Buzzer, HIGH);
  delay(250);
  digitalWrite(B_LED, LOW);
  digitalWrite(Buzzer, LOW);
  delay(250);
}
void BL_Alert() {
  digitalWrite(B_LED, HIGH);
  digitalWrite(Buzzer, HIGH);
  delay(150);
  digitalWrite(B_LED, LOW);
  digitalWrite(Buzzer, LOW);
  delay(150);
}