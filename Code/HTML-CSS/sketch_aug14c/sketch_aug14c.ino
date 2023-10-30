  /* made by Kusnh13
  For refrence watch YouTube video:-https://youtu.be/Hgq2KX5w-_o   */
  
  #include <WiFi.h>
  
  const char* ssid = "LAPTOP"; 
  const char* password = "78799008333"; 
  
  WiFiServer server(80);
  
  String header;
  String output26State = "off";
  String output27State = "off";
  
  const int output26 = 26;
  const int output27 = 27;
  
  void setup() {
  Serial.begin(115200);
  pinMode(output26, OUTPUT);
  digitalWrite(output26, LOW);
  digitalWrite(output27, LOW);
  
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
  
  void loop(){
  WiFiClient client = server.available(); 
  if (client) {      
  Serial.println("New Client.");
  String currentLine = "";       
  while (client.connected()) {    
  if (client.available()) {   
  char c = client.read();  
  Serial.write(c);          
  header += c;
  if (c == '\n') {     
  if (currentLine.length() == 0) {
  client.println("HTTP/1.1 200 OK");
  client.println("Content-type:text/html");
  client.println("Connection: close");
  client.println();
  
  // turns the GPIOs on and off
  if (header.indexOf("GET /26/on") >= 0) {
  Serial.println("GPIO 26 on");
  output26State = "on";
  digitalWrite(output26, HIGH);
  } else if (header.indexOf("GET /26/off") >= 0) {
  Serial.println("GPIO 26 off");
  output26State = "off";
  digitalWrite(output26, LOW);
  } else if (header.indexOf("GET /27/on") >= 0) {
  Serial.println("GPIO 27 on");
  output27State = "on";
  digitalWrite(output27, HIGH);
  } else if (header.indexOf("GET /27/off") >= 0) {
  Serial.println("GPIO 27 off");
  output27State = "off";
  digitalWrite(output27, LOW);
  }
  client.println("<!DOCTYPE HTML><html>");
  client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
  client.println("<link rel=\"shortcut icon\" href=\"https://media-exp1.licdn.com/dms/image/C4E0BAQEzb_74r1fLLg/company-logo_200_200/0/1614056149968?e=2147483647&v=beta&t=gDqZIWfV0Zr7yj4F0_nEFJdsbwQ4atwKBmbFMDUbcIg\" type=\"image/x-icon\">");
  client.println("<script src=\"https://kit.fontawesome.com/afd317a279.js\" crossorigin=\"anonymous\"></script>");

  client.println("<title>SMART CAR PARKING USING IOT</title>");

  client.println("<link href=\"https://fonts.googleapis.com/icon?family=Material+Icons\" rel=\"stylesheet\">");

  client.println("<style> html { font-family: Arial, Helvetica, sans-serif; text-align: center; } h1 { font-size: 1.8rem; color: rgb(0, 0, 0); } .slot { display: dis; background-color: rgb(255, 255, 255); border: 3px solid black; border-radius: 10px; width: 10rem; height: 15rem; } .content { padding: 5% 30%; width: 100%; } .nav { width: 300px; margin: 0 30%; } .wrapper { display: flex; flex-wrap: nowrap; }");
  client.println(".s2 { margin-left: 10px; } </style></head>");

  client.println("<body>");
  client.println("<h1 class=\"bdr\"\">Car Parking</h1>");
  break;
  } else {   currentLine = "";  }
  } else if (c != '\r') {   currentLine += c;   }
  }
  
  }
  header = "";
  client.stop();
  Serial.println("Client disconnected.");
  Serial.println("");
  }
  }
