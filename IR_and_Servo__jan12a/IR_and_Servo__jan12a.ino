#include<ESP8266WiFi.h>         // Nodemcu Header file
#include<BlynkSimpleEsp8266.h>  // BLYNK Header file

#include<Servo.h> // Servo Header file
#include<DHT.h> // DHT Sensor Header file

char auth[] = "kJSDrbjUdHTI57LMRppiSJeOAZXfwRlT";
char ssid[] = "R.D.AGRO";
char password[] = "pikapika22";

#define BLYNK_PRINT Serial


#define DHTPIN 0        // D3 for DHT Sensor 
#define DHTTYPE DHT11   // DHT sensor type DHT11
#define soilPin A0      // A0 for Soil Sensor 
#define SERVO_PIN 4     // D2 for Servo Motor
#define ir  5           // Variable ir sensor pin... 

int soilValue;          //Variable to read virtual pin for DHT

int motion;             // place to store ir value...
int angle = 0;          // Variable for servo turn angle...

Servo servo;



DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit
  Serial.println(t);
  Serial.println(h);
  if (isnan(h) || isnan(t))
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Blynk.virtualWrite(V5, t);
  Blynk.virtualWrite(V6, h);
  Blynk.virtualWrite(V4, soilValue);
  Blynk.virtualWrite(V3, motion);
  delay(1000);
}

void setup()
{
  Serial.begin(9600);
  delay(10);

  Blynk.begin(auth, ssid, password);

  servo.attach(SERVO_PIN);
  dht.begin();

  pinMode(ir, INPUT);
  servo.write(90);
  // setup to call a function every second
  timer.setInterval(10000L, sendSensor);

}



void loop()
{
  baby_cradel_movement();
  delay(100);
  cloth_value();
  delay(100);
  Blynk.run();
  timer.run();
}

void baby_cradel_movement() {
  motion = digitalRead(ir);
  Serial.print("Motion =");
  Serial.println(motion);
  delay(100);
  if (motion == 0)
  {
    Blynk.notify("Baby is Moving");
    for (angle = 90; angle <= 130;)
    {
      servo.write(angle);
      delay(100);
      angle = angle + 10;
    }
    delay(100);
    for (angle = 130; angle >= 50;)
    {
      servo.write(angle);
      angle = angle - 20;
      delay(100);
    }
    delay(100);
    for (angle = 50; angle <= 130;)
    {
      servo.write(angle);
      angle = angle + 20;
      delay(100);
    }
    delay(100);
    for (angle = 130; angle >= 50;)
    {
      servo.write(angle);
      angle = angle - 20;
      delay(100);
    }
    delay(100);
    for (angle = 50; angle <= 130;)
    {
      servo.write(angle);
      angle = angle + 20;
      delay(100);
    }
    delay(100);
    for (angle = 130; angle >= 50;)
    {
      servo.write(angle);
      angle = angle - 20;
      delay(100);
    }
    for (angle = 50; angle <= 90;)
    {
      servo.write(angle);
      angle = angle + 10;
      delay(100);
    }
  }
}

void cloth_value()        
{
  soilValue = analogRead(soilPin);
  Serial.println(soilValue);
  if (soilValue <650)
  {
    Serial.println("Please Change Diaper");
    Blynk.notify("Please Change Diaper");
    delay(100);
  }
}
