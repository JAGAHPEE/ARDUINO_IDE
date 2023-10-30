
#include <WiFi.h>

const char* ssid     = "LAPTOP";
const char* password = "78799008333";

WiFiServer server(80);

void setup()
{
  Serial.begin(115200);
  pinMode(2, OUTPUT);      // set the LED pin mode

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
            client.println("<style> html { font-family: Cairo; text-align: center; } h1 { font-size: 1.8rem; color: rgb(0, 0, 0); } .slot { display: flex; background-color: rgb(255, 255, 255); border: 3px solid black; border-radius: 10px; width: 10rem; height: 15rem; } .content { padding: 5% 30%; width: 100%; } .nav { width: 300px; margin: 0 30%; } .wrapper { display: flex; flex-wrap: nowrap; } .s2 { margin-left: 10px; } </style></head>");
            client.println("<body>");
            // the content of the HTTP response follows the header:
            client.print("Click <a href=\"/H\">here</a> to turn the LED on pin 5 on.<br>");
            client.print("Click <a href=\"/L\">here</a> to turn the LED on pin 5 off.<br>");
            client.println("<h1>SMART CAR PARKING USING IOT</h1>");
            
            client.println("<a href=\"/frwl\"><button><i class=\"fa-solid fa-chevron-left icon\"\"></i></button></a>");
            client.println("<div class=\"nav\"\"> <h1 class=\"bdr\"\">Car Parking</h1> </div> <div class=\"content\"\"> <div class=\"wrapper\"\"> <div class=\"slot s1\"\"></div> <div class=\"slot s2\"\"></div> </div> </div>");
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

        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /H")) {
          digitalWrite(2, HIGH);               // GET /H turns the LED on
        }
        if (currentLine.endsWith("GET /L")) {
          digitalWrite(2, LOW);                // GET /L turns the LED off
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
  }
}
