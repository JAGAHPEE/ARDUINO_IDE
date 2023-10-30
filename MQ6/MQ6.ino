#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,6,5,4,3);
#include <dht.h>
//#define DHTPIN A3

#define dht_apin A3

dht DHT;

const int lm35_pin = A5;
const int ldrPin = A4;
int lpg = A2;
float sensorValue;
float sensorVolts;

int sensitivity = 66;


int adcValue = 0;
int offsetVoltage = 2500;
double adcVoltage = 0;
double currentValue = 0;

float vOUT = 0.0;
float vIN = 0.0;
float R1 = 30000.0;
float R2 = 7500.0;
int value = 0;

void setup()
{ 

  lcd.begin(16, 2);
  pinMode(ldrPin, INPUT);
  lcd.setCursor(0, 0);
  lcd.print("WELCOME TO");
  lcd.setCursor(0, 1);
  lcd.print("SYSITS RATLAM");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("PARAMETER");
  lcd.setCursor(0, 1);
  lcd.print("CONTROLLING SYSTEM");
  delay(3000);
  lcd.clear();
}

void loop()
{
  int temp_adc_val;
  float temp_val;
  for(int i = 0; i < 100; i++){
     sensorValue = sensorValue + analogRead(lpg);       // read analog input pin 0
 }
  sensorValue = sensorValue / 100; // get average reading 
  sensorVolts = sensorValue/1024*5.0; //convert to voltage 
  temp_adc_val = analogRead(lm35_pin);  /* Read Temperature */
  temp_val = (temp_adc_val * 4.88); /* Convert adc value to equivalent voltage */
  temp_val = (temp_val / 10); /* LM35 gives output of 10mv/°C */
  int ldrStatus = analogRead(ldrPin);
  
//  int chk = DHT.read(DHTPIN);
   DHT.read11(dht_apin);
  
  lcd.clear();
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("Temp=");
  lcd.print(temp_val);
  Serial.println(temp_val);
  lcd.setCursor(8, 0);
  lcd.print("Light=");
  lcd.print(ldrStatus);
  Serial.println(ldrStatus);
  lcd.setCursor(0, 1);
  lcd.print("Hum=");
  lcd.print((float)DHT.humidity, 2);
  Serial.println((float)DHT.humidity, 2);
  lcd.println(" % ");
  lcd.setCursor(8, 1);
  lcd.print("LPG=");
  lcd.print(sensorVolts);
  Serial.println(sensorVolts);
  delay(2000);
  
  lcd.clear();
}
