
#include <WiFi.h>

const char* ssid     = "LAPTOP";
const char* password = "78799008333";

WiFiServer server(80);
int ir1 = 26;
void setup()
{
  Serial.begin(115200);
  pinMode(2, OUTPUT);      // set the LED pin mode
  pinMode(26, INPUT);
  delay(10);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();

}

int value = 0;

void loop() {
  WiFiClient client = server.available();   // listen for incoming clients
  if (client) {                             // if you get a client,
    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character

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
            client.println("<body>");
            client.println("<center>");
            client.println("<h1 class=\"animate__fadeInDown\"\">SMART CAR PARKING SYSTEM USING IOT</h1>");
            client.println("<div class=\"area\"\"><div class=\"wrapper animate__fadeInLeft\"\">");

            if (digitalRead(ir1) == 0)
            {
              client.println("<div class=\"s1\"\"><div class=\"slot\"\" style=\"background-color: #ffcccc;\"\"><img src=\"https://github.com/JAGAHPEE/SMART-CAR-PARKING-SYSTEM-USING-IOT/blob/main/car-top-view.png?raw=true\"\" class=\"car-image\"\" alt=""></div><p><b>Parked</b></p></div>");
            }
            else
            {
              client.println("<div class=\"s1\"\"><div class=\"slot\"\"><img src=\"https://github.com/JAGAHPEE/SMART-CAR-PARKING-SYSTEM-USING-IOT/blob/main/car-top-view.png?raw=true\"\" class=\"car-image\"\" alt="" style=\"filter: opacity(0.6) drop-shadow(0 0 rgb(255, 0, 0));\"\"></div><p><b> Slot 1</b></p></div>");
            }
            if (digitalRead(ir1) == 0)
            {
              client.println("<div class=\"s1\"\"><div class=\"slot\"\" style=\"background-color: #ffcccc;\"\"><img src=\"https://github.com/JAGAHPEE/SMART-CAR-PARKING-SYSTEM-USING-IOT/blob/main/car-top-view.png?raw=true\"\" class=\"car-image\"\" alt=""></div><p><b>Parked</b></p></div>");
            }
            else
            {
              client.println("<div class=\"s1\"\"><div class=\"slot\"\"><img src=\"https://github.com/JAGAHPEE/SMART-CAR-PARKING-SYSTEM-USING-IOT/blob/main/car-top-view.png?raw=true\"\" class=\"car-image\"\" alt="" style=\"filter: opacity(0.6) drop-shadow(0 0 rgb(255, 0, 0));\"\"></div><p><b> Slot 2</b></p></div>");
            }
            if (digitalRead(ir1) == 0)
            {
              client.println("<div class=\"s1\"\"><div class=\"slot\"\" style=\"background-color: #ffcccc;\"\"><img src=\"https://github.com/JAGAHPEE/SMART-CAR-PARKING-SYSTEM-USING-IOT/blob/main/car-top-view.png?raw=true\"\" class=\"car-image\"\" alt=""></div><p><b>Parked</b></p></div>");
            }
            else
            {
              client.println("<div class=\"s1\"\"><div class=\"slot\"\"><img src=\"https://github.com/JAGAHPEE/SMART-CAR-PARKING-SYSTEM-USING-IOT/blob/main/car-top-view.png?raw=true\"\" class=\"car-image\"\" alt="" style=\"filter: opacity(0.6) drop-shadow(0 0 rgb(255, 0, 0));\"\"></div><p><b> Slot 3</b></p></div>");
            }

            client.println("</div></div>");

            client.println("<div class=\"line2\"\"></div>");
            client.println("<div class=\"line1 animate__bounceInUp\"\"></div>");
            client.println("<div class=\"line2\"\"></div>");
            
            client.println("<div class=\"area\"\"><div class=\"wrapper animate__fadeInRight\"\">");
            if (digitalRead(ir1) == 0)
            {
              client.println("<div class=\"s1\"\"><div class=\"slot\"\" style=\"background-color: #ffcccc;\"\"><img src=\"https://github.com/JAGAHPEE/SMART-CAR-PARKING-SYSTEM-USING-IOT/blob/main/car-top-view.png?raw=true\"\" class=\"car-image\"\" alt=""></div><p><b>Parked</b></p></div>");
            }
            else
            {
              client.println("<div class=\"s1\"\"><div class=\"slot\"\"><img src=\"https://github.com/JAGAHPEE/SMART-CAR-PARKING-SYSTEM-USING-IOT/blob/main/car-top-view.png?raw=true\"\" class=\"car-image\"\" alt="" style=\"filter: opacity(0.6) drop-shadow(0 0 rgb(255, 0, 0));\"\"></div><p><b> Slot 4</b></p></div>");
            }
            if (digitalRead(ir1) == 0)
            {
              client.println("<div class=\"s1\"\"><div class=\"slot\"\" style=\"background-color: #ffcccc;\"\"><img src=\"https://github.com/JAGAHPEE/SMART-CAR-PARKING-SYSTEM-USING-IOT/blob/main/car-top-view.png?raw=true\"\" class=\"car-image\"\" alt=""></div><p><b>Parked</b></p></div>");
            }
            else
            {
              client.println("<div class=\"s1\"\"><div class=\"slot\"\"><img src=\"https://github.com/JAGAHPEE/SMART-CAR-PARKING-SYSTEM-USING-IOT/blob/main/car-top-view.png?raw=true\"\" class=\"car-image\"\" alt="" style=\"filter: opacity(0.6) drop-shadow(0 0 rgb(255, 0, 0));\"\"></div><p><b> Slot 5</b></p></div>");
            }
            if (digitalRead(ir1) == 0)
            {
              client.println("<div class=\"s1\"\"><div class=\"slot\"\" style=\"background-color: #ffcccc;\"\"><img src=\"https://github.com/JAGAHPEE/SMART-CAR-PARKING-SYSTEM-USING-IOT/blob/main/car-top-view.png?raw=true\"\" class=\"car-image\"\" alt=""></div><p><b>Parked</b></p></div>");
            }
            else
            {
              client.println("<div class=\"s1\"\"><div class=\"slot\"\"><img src=\"https://github.com/JAGAHPEE/SMART-CAR-PARKING-SYSTEM-USING-IOT/blob/main/car-top-view.png?raw=true\"\" class=\"car-image\"\" alt="" style=\"filter: opacity(0.6) drop-shadow(0 0 rgb(255, 0, 0));\"\"></div><p><b> Slot 6</b></p></div>");
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
            // break out of the while loop:
            break;
          } else {    // if you got a newline, then clear currentLine:
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
