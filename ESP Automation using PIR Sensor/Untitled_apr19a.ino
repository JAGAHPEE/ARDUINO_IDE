#define relay_1   14
#define relay_2   12
#define relay_3   13
#define motion_sensor 5
/* 
  Sketch generated by the Arduino IoT Cloud Thing "Untitled"
  https://create.arduino.cc/cloud/things/b99ec34d-1e91-475e-89c8-42b6e9185e0e 

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  bool rEALY_1;
  bool rEALY_2;
  bool rELAY_3;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"

void setup() {

  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  pinMode(relay_1, OUTPUT);         // Initialize the relay_1 pin as an output
  pinMode(relay_2, OUTPUT);         // Initialize the relay_1 pin as an output
  pinMode(relay_3, OUTPUT);         // Initialize the relay_3 pin as an output
  pinMode(motion_sensor, INPUT);    // Initialize the motion_sensor pin as an input
  
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Your code here 
  if(digitalRead(motion_sensor)){
     digitalWrite(relay_3, HIGH);   // Turn the LED on (Note that LOW is the voltage level
  }
  else {
     digitalWrite(relay_3, LOW);   // Turn the LED on (Note that LOW is the voltage level
  }
}

/*
  Since REALY1 is READ_WRITE variable, onREALY1Change() is
  executed every time a new value is received from IoT Cloud.
*/
void onREALY1Change()  {
  // Add your code here to act upon REALY1 change
  if(rEALY_1){
    digitalWrite(relay_1, HIGH);   // Turn the LED on (Note that LOW is the voltage level
   }
  else {
    digitalWrite(relay_1, LOW);   // Turn the LED on (Note that LOW is the voltage level
   }
}
/*
  Since REALY2 is READ_WRITE variable, onREALY2Change() is
  executed every time a new value is received from IoT Cloud.
*/
void onREALY2Change()  {
  // Add your code here to act upon REALY2 change
   if(rEALY_2){
    digitalWrite(relay_2, HIGH);   // Turn the LED on (Note that LOW is the voltage level
   }
  else {
    digitalWrite(relay_2, LOW);   // Turn the LED on (Note that LOW is the voltage level
   }
}
/*
  Since RELAY3 is READ_WRITE variable, onRELAY3Change() is
  executed every time a new value is received from IoT Cloud.
*/
void onRELAY3Change()  {
  // Add your code here to act upon RELAY3 change
  if(rELAY_3){
   digitalWrite(LED_BUILTIN, HIGH);   // Turn the LED on (Note that LOW is the voltage level
   }
  else {
    digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level
   }
}
