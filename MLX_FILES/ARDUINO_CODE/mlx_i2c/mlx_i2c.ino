#include <Wire.h>
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();



double temp_amb;
double temp_obj;

void setup()
{
  Serial.begin(9600);
  Serial.println("Temperature Sensor MLX90614");

  pinMode(D4,OUTPUT);// Connect buzzer at D8
  //Initialize LCD I2C
  
  //Initialize MLX90614
  mlx.begin();
  digitalWrite(8,LOW);
}

void loop()
{
  //Reading room temperature and object temp
  //for reading Fahrenheit values, use
  //mlx.readAmbientTempF() , mlx.readObjectTempF() )
  temp_amb = mlx.readAmbientTempC();
  temp_obj = mlx.readObjectTempC();
  if(temp_obj > 37) {
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

  delay(1000);
}
