
#include <WiFi.h>

const char* ssid     = "LAPTOP";
const char* password = "78799008333";

WiFiServer server(80);
int ir1 = 26;
int s=0;
int prev=0;
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
  s = digitalRead(ir1);
  if (client) {                             // if you get a client,
    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";
  
    // make a String to hold incoming data from the client         
    // loop while the client's connected
                 // print it out the serial monitor
          client.println("HTTP/1.1 200 OK");
          client.println("Content-type:text/html");
          client.println();
          client.println("<html>");
          client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
          client.println("<style> html { font-family: Cairo; text-align: center; } h1 { font-size: 1.8rem; color: rgb(0, 0, 0); } .slot { display: flex; background-color: rgb(255, 255, 255); border: 3px solid black; border-radius: 10px; width: 10rem; height: 15rem; } .content { width: 100%; } .nav { width: 300px; margin: 0 30%; } .wrapper { display: flex; flex-wrap: nowrap; } </style></head>");
          client.println("<body>");
          // the content of the HTTP response follows the header:
          client.print("Click <a href=\"/H\">here</a> to turn the LED on pin 5 on.<br>");
          client.print("Click <a href=\"/L\">here</a> to turn the LED on pin 5 off.<br>");
          client.println("<h1>SMART CAR PARKING USING IOT</h1>");

          client.println("<a href=\"/frwl\"><button><i class=\"fa-solid fa-chevron-left icon\"\"></i></button></a>");
          client.println("<div class=\"nav\"\"> <h1 class=\"bdr\"\">Car Parking</h1> </div> <div class=\"content\"\"> <div class=\"wrapper\"\">");
          if (s == 0)
          {
            client.println("<div class=\"slot\"\" style=\"background-color: black;\"\"></div>");
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
            delay(5000);
    }
    Serial.println("Client Disconnected.");
  }
