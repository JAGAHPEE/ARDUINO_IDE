#include <Servo.h>
#include<DHT.h>
const int MOTION_SENSOR_PIN = 7; // Arduino pin connected to motion sensor's pin
const int SERVO_PIN         = 9; // Arduino pin connected to servo motor's pin
const int DHTPIN=2;
const int DHTTYPE = DHT11;
DHT dht(DHTPIN, DHTTYPE);

Servo servo; // create servo object to control a servo

// variables will change:
int angle = 0;          // the current angle of servo motor
int lastMotionState;    // the previous state of motion sensor
int currentMotionState; // the current state of motion sensor

void setup() {
  Serial.begin(9600);
//dht.begin();     
  pinMode(MOTION_SENSOR_PIN, INPUT); // set arduino pin to input mode
  servo.attach(SERVO_PIN);           // attaches the servo on pin 9 to the servo object

  servo.write(angle);
  currentMotionState = digitalRead(MOTION_SENSOR_PIN);
  
}
void loop()
{
  lastMotionState    = currentMotionState;             // save the last state
  currentMotionState = digitalRead(MOTION_SENSOR_PIN); // read new state
  if (currentMotionState == LOW && lastMotionState == HIGH) { // pin state change: LOW -> HIGH
    Serial.println("Motion detected!");
    servo.write(90);
  }
  else if (currentMotionState == HIGH && lastMotionState == LOW) { // pin state change: HIGH -> LOW
    Serial.println("Motion stopped!");
    servo.write(0);
  }
//  PIR();
  delay(1000);
//  DTH11();
}

//void PIR() {
//
//  if (currentMotionState == LOW && lastMotionState == HIGH) { // pin state change: LOW -> HIGH
//    Serial.println("Motion detected!");
//    servo.write(90);
//  }
//  else if (currentMotionState == HIGH && lastMotionState == LOW) { // pin state change: HIGH -> LOW
//    Serial.println("Motion stopped!");
//    servo.write(0);
//  }
//}
//void DTH11()
//{
//  float h = dht.readHumidity();
//  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit
//
//  if (isnan(h) || isnan(t)) {
//    Serial.println("Failed to read from DHT sensor!");
//    return;
//  }
//  else
//  {
//    Serial.print("TEMP");
//    Serial.println(t);
//  }
//
//}
