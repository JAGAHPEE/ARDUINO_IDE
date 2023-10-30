
#include <WiFi.h>

const char* ssid     = "LAPTOP";
const char* password = "78799008333";

WiFiServer server(80);
int ir1=26;
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
            client.println("<style> html { font-family: Cairo; text-align: center; } h1 { font-size: 1.8rem; color: rgb(0, 0, 0); } .slot { display: flex; margin-left=10px; background-color: rgb(255, 255, 255); border: 3px solid black; border-radius: 10px; width: 10rem; height: 15rem; } .content { width: 100%; } .nav { width: 300px; margin: 0 30%; } .wrapper { display: flex; flex-wrap: nowrap; } </style></head>");
            client.println("<body>");
            client.println("<h1>SMART CAR PARKING USING IOT</h1>");
            
            client.println("<a href=\"\"><button style=\"width:70px;height:30px;\"\"><i class=\"fa-solid fa-chevron-left icon\"\"></i>Refresh</button></a>");
            client.println("<div class=\"nav\"\"></div> <div class=\"content\"\"> <div class=\"wrapper\"\">");
            
            
            if(digitalRead(ir1)==0)
            {
              client.println("<div class=\"slot\"\" style=\"background-color: black;\"\"></div>");
            }
            else
            {
              client.println("<div class=\"slot\"\"></div>"); 
            }

            
            if(digitalRead(ir1)==0)
            {
              client.println("<div class=\"slot\"\" style=\"background-color: black;\"\"></div>");
            }
            else
            {
              client.println("<div class=\"slot\"\"></div>"); 
            }

            
            if(digitalRead(ir1)==0)
            {
              client.println("<div class=\"slot\"\" style=\"background-color: black;\"\"></div>");
            }
            else
            {
              client.println("<div class=\"slot\"\"></div>"); 
            }
            
            client.println("<br>");
            client.println("<br>");
            client.println("<br>");
            
            if(digitalRead(ir1)==0)
            {
              client.println("<div class=\"slot\"\" style=\"background-color: black;\"\"></div>");
            }
            else
            {
              client.println("<div class=\"slot\"\"></div>"); 
            }

            
            if(digitalRead(ir1)==0)
            {
              client.println("<div class=\"slot\"\" style=\"background-color: black;\"\"></div>");
            }
            else
            {
              client.println("<div class=\"slot\"\"></div>"); 
            }

            
            if(digitalRead(ir1)==0)
            {
              client.println("<div class=\"slot\"\" style=\"background-color: black;margin-right=10px;\"\"></div>");
            }
            else
            {
              client.println("<div class=\"slot\"\"></div>"); 
            }
            
            
            
            
            client.println("</div> </div>");
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
    client.stop();
    Serial.println("Client Disconnected.");
  }
}
