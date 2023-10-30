#include <LiquidCrystal_I2C.h>
#include<WiFi.h>

#include<stdio.h>

WiFiClient client;
WiFiServer server(80);
String request;
void frwl();
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
  Serial.println("WiFi Connected");
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
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  // Match the request


  if (request.indexOf("/frwl") > 0)  {
    frwl();

  }
  client.println("HTTP/1.1 200 OK"); //
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
  client.println("<link rel=\"shortcut icon\" href=\"https://media-exp1.licdn.com/dms/image/C4E0BAQEzb_74r1fLLg/company-logo_200_200/0/1614056149968?e=2147483647&v=beta&t=gDqZIWfV0Zr7yj4F0_nEFJdsbwQ4atwKBmbFMDUbcIg\" type=\"image/x-icon\">");
  client.println("<script src=\"https://kit.fontawesome.com/afd317a279.js\" crossorigin=\"anonymous\"></script>");
  client.println("<title>SMART CAR PARKING USING IOT</title>");
  client.println("<link href=\"https://fonts.googleapis.com/icon?family=Material+Icons\" rel=\"stylesheet\">");
  client.println("<style> html { font-family: Cairo; text-align: center; } h1 { font-size: 1.8rem; color: rgb(0, 0, 0); } .slot { display: flex; background-color: rgb(255, 255, 255); border: 3px solid black; border-radius: 10px; width: 10rem; height: 15rem; } .content { padding: 5% 30%; width: 100%; } .nav { width: 300px; margin: 0 30%; } .wrapper { display: flex; flex-wrap: nowrap; } .s2 { margin-left: 10px; } </style></head>");
  client.println("<body>");
  client.println("<a href=\"/frwl\"><button><i class=\"fa-solid fa-chevron-left icon\"\"></i></button></a>");
  client.println("<div class=\"nav\"\"> <h1 class=\"bdr\"\">Car Parking</h1> </div> <div class=\"content\"\"> <div class=\"wrapper\"\"> <div class=\"slot s1\"\"></div> <div class=\"slot s2\"\"></div> </div> </div>");
  client.println("</body>");
  client.println("</html>");
  delay(1);
}
void frwl()
{
}
