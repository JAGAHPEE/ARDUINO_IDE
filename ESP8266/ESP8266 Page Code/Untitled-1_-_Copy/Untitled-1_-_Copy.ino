/*
   ESP8266 NodeMCU LED Control over WiFi Demo

   https://circuits4you.com
*/
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

//ESP Web Server Library to host a web page
#include <ESP8266WebServer.h>
#include "robot.h"
//---------------------------------------------------------------
void frw();
void rw();
void stp();
void lft();
void rgt();

//---------------------------------------------------------------
//On board LED Connected to GPIO2
#define LED 2

//SSID and Password of your WiFi router
const char* ssid = "LAPTOP";
const char* password = "7879900833";

//Declare a global object variable from the ESP8266WebServer class.
ESP8266WebServer server(80); //Server on port 80
int MotorAip1 = D3;
int MotorAip2 = D2;
// motor two

//Left motor
int MotorBip1 = D1;
int MotorBip2 = D0;
//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================


//==============================================================
//                  SETUP
//==============================================================
void setup() {
  Serial.begin(115200);

  pinMode(MotorAip1, OUTPUT);
  pinMode(MotorAip2, OUTPUT);
  pinMode(MotorBip1, OUTPUT);
  pinMode(MotorBip2, OUTPUT);

  WiFi.begin(ssid, password);     //Connect to your WiFi router
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP

  
  server.begin();                  //Start server
  server.on("/", handleRoot);      //Which routine to handle at root location. This is display page
  server.on("/forward", frd); //as Per  <a href="forward">, Subroutine to be called
  server.on("/reverse", rw);
  server.on("/stop", stp);
  server.on("/left", lft);
  server.on("/right", rgt);
  
  Serial.println("HTTP server started");
}
//==============================================================
//                     LOOP
//==============================================================
void loop() {
  server.handleClient();          //Handle client requests
}
void handleRoot() {
  Serial.println("You called root page");
  String s = MAIN_page; //Read HTML contents
  server.send(200, "text/html", s); //Send web page
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

void rgt() {
    Serial.println("Right");
    digitalWrite(MotorAip1,HIGH);     
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,HIGH);
void lft() {
     Serial.println("Left");
    digitalWrite(MotorAip1,LOW);   
    digitalWrite(MotorAip2,HIGH);
    digitalWrite(MotorBip1,HIGH);
    digitalWrite(MotorBip2,LOW);
}
