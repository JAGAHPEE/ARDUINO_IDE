#include <ESP8266WiFi.h>

WiFiClient client;
WiFiServer server(80);
String request;
int MotorAip1 = D4;
int MotorAip2 = D3;
// motor two

void frw();
void rgt();
void rw();
void stp();
void lft();
//Left motor
int MotorBip1 = D2;
int MotorBip2 = D1;
int led = D0;
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin("LAPTOP", "7879900833");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print("..");
  }
  Serial.println();
  Serial.println("NodeMCU is connected!");
  digitalWrite(led,HIGH);
  Serial.println(WiFi.localIP());
  server.begin();
  pinMode(MotorAip1, OUTPUT);
  pinMode(MotorAip2, OUTPUT);
  pinMode(MotorBip1, OUTPUT);
  pinMode(MotorBip2, OUTPUT);
  pinMode(led, OUTPUT);

  digitalWrite(MotorAip1, LOW);
  digitalWrite(MotorAip2, LOW);
  digitalWrite(MotorBip1, LOW);
  digitalWrite(MotorBip2, LOW);
  digitalWrite(led, LOW);
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
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
  // Match the request
 
 
  if (request.indexOf("/forward") > 0)  {
    frw();
   
  }
  if (request.indexOf("/reverse") >0)  {
    rw();
   
  }

   if (request.indexOf("/left") > 0)  {
    lft();
   
  }
  if (request.indexOf("/right") >0)  {
    rgt();  
  }

  if (request.indexOf("/stop") > 0)  {
    stp();
  }
  
  client.println("HTTP/1.1 200 OK"); //
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<body bgcolor = \"#00FFFF\" color = \"#00FFFF\">");
  client.println("<center>");
  client.println("<h1>Welcome to Pi-Tech</h1>");
  client.println("<br>");
  client.println("<h1>Web Controlling Robotic Car using NodeMCU</h1>");
  client.println("<br>");
  client.println("<a href=\"/stop\" width=\"70px\"><button>STOP</button></a>");
  client.println("<a href=\"/forward\"\"><button>FORWARD</button></a><br/>");
  client.println("<a href=\"/reverse\"\"><button>REVERSE</button></a>");
  client.println("<a href=\"/left\"\"><button>LEFT</button></a><br/>");
  client.println("<a href=\"/right\"\"><button>RIGHT</button></a><br/>");
  client.println("<center>");
    client.println("</body>");
  client.println("</html>");
   delay(1);
}

void frw() {
  Serial.println("Forward");
  digitalWrite(MotorAip1, HIGH);
  digitalWrite(MotorAip2, LOW);
  digitalWrite(MotorBip1, HIGH);
  digitalWrite(MotorBip2, LOW);
}

void rw() {
  Serial.println("Reverse");
  digitalWrite(MotorAip1, LOW);
  digitalWrite(MotorAip2, HIGH);
  digitalWrite(MotorBip1, LOW);
  digitalWrite(MotorBip2, HIGH);
}

void lft() {
  Serial.println("Left");
  digitalWrite(MotorAip1, LOW);
  digitalWrite(MotorAip2, HIGH);
  digitalWrite(MotorBip1, HIGH);
  digitalWrite(MotorBip2, LOW);
}
void rgt()
{
  Serial.println("Right");
  digitalWrite(MotorAip1, HIGH);
  digitalWrite(MotorAip2, LOW);
  digitalWrite(MotorBip1, LOW);
  digitalWrite(MotorBip2, HIGH);
}
void stp()
{
  Serial.println("Stop");
  digitalWrite(MotorAip1, LOW);
  digitalWrite(MotorAip2, LOW);
  digitalWrite(MotorBip1, LOW);
  digitalWrite(MotorBip2, LOW);
}
