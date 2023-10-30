#include <SoftwareSerial.h>

SoftwareSerial NodeMcu_SoftSerial (D1,D2); //RX, TX

//Declare Global Variable
char c;
String dataIn;

void setup() {
  // put your setup code here, to run once:
    //Open Serial Communication (Arduino-PC)
    Serial.begin(57600);

    //Open Serial communication (Arduino-NodeMcu
    NodeMcu_SoftSerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

    while(NodeMcu_SoftSerial.available()>0)
      {
         c = NodeMcu_SoftSerial.read();
         if(c=='\n')  {break;}
         else         {dataIn+=c;}
      }

    if(c=='\n')
      {
          //Show data in to Serial Monitor
          Serial.println(dataIn);

          //Send Data Back to Arduino
          NodeMcu_SoftSerial.print("Yeah I'am Good Bro :) \n");
          
          //Reset the variable
          c=0;
          dataIn="";
      }
}
