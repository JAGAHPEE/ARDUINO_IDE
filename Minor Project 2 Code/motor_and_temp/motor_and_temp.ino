#include <ESP8266WiFi.h>
#include <Wire.h>
#include<stdio.h>
#include <Adafruit_MLX90614.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

double temp_amb;
double temp_obj;

WiFiClient client;
WiFiServer server(80);
String request;
int MotorAip1 = D8;
int MotorAip2 = D7;
// motor two

void frw();
void rgt();
void rw();
void stp();
void lft();
void temp();
//Left motor
int MotorBip1 = D6;
int MotorBip2 = D5;
int led = D0;
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Initialize MLX90614
  mlx.begin();
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
   if (request.indexOf("/temperature") > 0)  {
    temp();
  }
  
  client.println("HTTP/1.1 200 OK"); //
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
  client.println("<link rel=\"icon\" href=\"data:,\">");
  client.println("<style>html { font-family: Cairo; display: inline; margin: 0px auto; text-align: center; background-color: black; color:white;}");
  client.println("button { background-color: #006699; border: solid white 1px; color: white; border-radius: 0 20px;padding: 10px 20px; width:100px;font-size:15px; text-decoration: none;margin: 2px; font-weight: bold; cursor: pointer;}");
  client.println("");
//  client.println(".image{height: auto; position: relative;align-items:center;}");
  client.println(".image {height: 300px; width :100%; align-items: center;background-image: url(https://indoreinstitute.com/wp-content/uploads/2021/05/f1.png);background-position: center;background-repeat: no-repeat;background-size:cover;}");
  client.println(".small-underline{width: 9rem;height:.1rem;background-color: #deaa86;margin: 0 auto 1rem auto;}");
  client.println(".big-underline{width: 20rem;height:5px;background-color: #deaa86;}");
  client.println(".line{width:300px;height:1px;border:solid 1px white;}");
  client.println("p{font-size:16px;}");
  client.println(".te{font-size:20px;color:#ff0000;background-color:#000000;}");
  client.println(".button2 {background-color: #555555;}</style></head>");
  client.println("<body>");
  client.println("<center>");
  client.println("<p>Department of Electronics & Communication Engineering</p>");
  client.println("<br>");
  client.println("<table class=\"tablea\"><tr><td></td><td><a href=\"/forward\"\"><button>FRWD</button></a></td><td></td></tr>");
  client.println("<tr><td><a href=\"/left\"\"><button>LEFT</button></a></td><td><a href=\"/stop\" style=\"width:70px\"\"><button>STOP</button></a></td><td><a href=\"/right\"\"><button>RIGHT</button></a></td></tr>");
  client.println("<tr><td></td><td><a href=\"/reverse\"\"><button>REVERSE</button></a><td><td></td></tr></table>");
  client.println("<a href=\"/temperature\"\"><button style=\"background-color: #000000; width: 300px; text-decoration: none; color: #e65715; padding: 5px; border: solid white 3px; border-radius: 0 20px ; font-family: monospace; transition: all 0.5s; font-weight:1000;\"\" class=\"te\">TEMPERATURE</button></a>");
  client.println("<br>");
  client.println("<div class=\"image\"\"></div>");
  client.println("<h3 class=\"title\">Minor Project : COVID PROTECTIVE ROBOT:- PHASE II</h3>");
  client.println("<div class=\"underline\"><div class=\"small-underline\" style=\"width: 9rem;height:.1rem;background-color: #deaa86;margin: 0 auto 1rem auto;\"\"></div><div class=\"big-underline\" style=\"width: 20rem;height:5px;background-color: #deaa86;\"\"></div></div>");
  client.println("<br>");
  client.println("<br>");
  
  if (request.indexOf("/temperature") > 0)  {
    temp();
    client.println("<div class=\"Temperature\">");
    client.print("<h2>Room Temp = </h2>");
    client.println("<h1>");
    client.print(temp_amb );
    client.print(" deg. C</h1>");
    client.print("<div class=\"line\"\"></div>");
    client.print("<h2>Object temp = </h2>");
    client.println("<h1>");
    client.print(temp_obj);
    client.print(" deg. C</h1></div>"); 
    client.println("<br>");
  }
  else{
    
  }
  client.println("<center>");
//  client.println("<script>let btn = document.querySelector('button');document.body.addEventListener('keydown', (e) =>{if(e.key=='a'||e.key=='4'){window.location.href=\"/left\";}if(e.key=='d'||e.key=='6'){window.location.href=\"/right\";}if(e.key=='x'||e.key=='2'){window.location.href=\"/reverse\";}if(e.key=='w'||e.key=='8'){window.location.href=\"/forward\";}if(e.key=='q'||e.key=='7'){window.location.href=\"/frwl\";}if(e.key=='e'||e.key=='9'){window.location.href=\"/frwr\";}if(e.key=='z'||e.key=='1'){window.location.href=\"/rwl\";}if(e.key=='3'||e.key=='c'){window.location.href=\"/rwr\";}if(e.key=='5'||e.key=='s'){window.location.href=\"/stp\";}if(e.key=='t'||e.key=='0'){window.location.href=\"/temperature\";}})</script>");
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
  digitalWrite(MotorAip1, HIGH);
  digitalWrite(MotorAip2, LOW);
  digitalWrite(MotorBip1, LOW);
  digitalWrite(MotorBip2, HIGH);
}
void rgt()
{
  Serial.println("Right");
   digitalWrite(MotorAip1, LOW);
  digitalWrite(MotorAip2, HIGH);
  digitalWrite(MotorBip1, HIGH);
  digitalWrite(MotorBip2, LOW);
}
 
void stp()
{
  Serial.println("Stop");
  digitalWrite(MotorAip1, LOW);
  digitalWrite(MotorAip2, LOW);
  digitalWrite(MotorBip1, LOW);
  digitalWrite(MotorBip2, LOW);
}
void temp()
{
  temp_amb = mlx.readAmbientTempC();
  temp_obj = mlx.readObjectTempC();
  if(temp_obj > 40) {
   digitalWrite(D4,HIGH);
   Serial.print("Warning...HIGH TEMP...");
   delay(50);}
  else{
    digitalWrite(D4,LOW);
  }
  
  Serial.print("Room Temp = ");
  Serial.println(temp_amb);
  Serial.print("Object temp = ");
  Serial.println(temp_obj); 

}
