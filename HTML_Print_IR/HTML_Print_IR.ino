
// Load Wi-Fi library
#include <WiFi.h>

// Replace with your network credentials
const char* ssid = "LAPTOP";
const char* password = "78799008333";

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current output state
String output26State = "off";
String output27State = "off";

// Assign output variables to GPIO pins
const int sensor26 = 26;
void setup()
{
  Serial.begin(9600);
  WiFi.begin("LAPTOP", "78799008333");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print("..");
  }
  Serial.println();
  Serial.println("ESP32 is connected!");
  Serial.println(WiFi.localIP());
  server.begin();

}

void loop()
{
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Wait until the client sends some data
  Serial.println("new client");
  while (!client.available()) {
    delay(1);
  }

  // Read the first line of the request

  client.println("HTTP/1.1 200 OK"); //
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");

  client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");

  client.println("<link rel=\"shortcut icon\" href=\"https://media-exp1.licdn.com/dms/image/C4E0BAQEzb_74r1fLLg/company-logo_200_200/0/1614056149968?e=2147483647&v=beta&t=gDqZIWfV0Zr7yj4F0_nEFJdsbwQ4atwKBmbFMDUbcIg\" type=\"image/x-icon\">");

  client.println("<script src=\"https://kit.fontawesome.com/afd317a279.js\" crossorigin=\"anonymous\"></script>");

  client.println("<title>Minor Project : COVID PROTECTIVE ROBOT:- PHASE II</title>");

  client.println("<link href=\"https://fonts.googleapis.com/icon?family=Material+Icons\" rel=\"stylesheet\">");

  client.println("<style>html { font-family: Cairo; display: inline; margin: 0px auto; text-align: center; background-color: black; color:white;}");

  client.println(".button2 {background-color: #555555;}.slot { background-color: rgb(255, 255, 255); border: 3px solid black; border-radius: 10px; width: 10rem; height: 15rem; } .content { padding: 5% 30%; width: 100%; } .nav { width: 300px; margin: 0 30%; } .wrapper { display: flex; flex-wrap: nowrap; } .s2 { margin-left: 10px; }</style></head>");
  client.println("<body>");
  client.println("<center>");
  client.println("<br>");

  client.println("<h1>SMART CAR PAKRING USING IOT</h1>");
  if (digitalRead(sensor26) == 0)
  {
    client.println("<h1>HIGH</h1>");
  }
  else
  {
    client.println("<h1>LOW</h1>");
  }
  client.println("<div class=\"content\"\"><div class=\"wrapper\"\">");
  client.println("<div class=\"slot s1\"\"></div>");

  client.println("<div class=\"slot s2\"\"></div>");
  client.println("</div> </div>");
  client.println("<br>");
  client.println("<br>");
  client.println("<center>");
  client.println("</body>");
  client.println("</html>");
  delay(1);
}
