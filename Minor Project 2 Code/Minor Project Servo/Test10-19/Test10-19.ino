#include <Servo.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 5, 4, 3, 2);
int inputPin = 16; // connect digital I/O d4 to the ECHO/Rx Pin
int outputPin = 17; // connect digital I/O d5 to the TRIG/TX Pin
int inputPin1 = 14; // connect digital I/O d4 to the ECHO/Rx Pin
int outputPin1 = 15; // connect digital I/O d5 to the TRIG/TX Pin
int servoPin = 6;
int bz = 7;
int a, b, c, d, e, f;
int distance, distance1, distance2, distance3;
Servo servo;
int angle = 0;  // servo position in degrees
String incomingByte ; // for incoming serial data
void setup()
{
  pinMode(inputPin, INPUT);
  pinMode(outputPin, OUTPUT);
  pinMode(inputPin1, INPUT);
  pinMode(outputPin1, OUTPUT);
  pinMode(bz, OUTPUT);
  servo.attach(servoPin);
  servo.write(0);
  digitalWrite(bz, LOW);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
//  lcd.print("WELCOME TO IIST");
//  lcd.setCursor(0, 1);
//  lcd.print("INDORE");
//  delay(2000);
//  lcd.clear();
//  lcd.setCursor(0, 0);
//  lcd.print("Covid Protective");
//  lcd.setCursor(0, 1);
//  lcd.print("Robot ");
//  delay(2000);
  lcd.clear();
}

void loop()
{
  if (Serial.available() > 0) {
    // read the incoming byte:
    String incomingByte = Serial.readString(); // read the incoming byte:
    if (incomingByte == "Stop")
    {
      // Scan from 0 to 180 degrees...
      // Scaning from 0 to 45 and taking reading on 45...
      delay(800);
      for (angle = 0; angle <= 45; angle++)
      {
        servo.write(angle);
        delay(30);
      }

      //Assigning value of Sensor_1 and Sensor_2 to a & b
      delay(800);
      Sensor1();
      a = distance1;
      Sensor2();
      b = distance3;

      //Printing Distance on LCD..
      print_distance();


      // Scaning from 45 to 90 and taking reading on 90 ...
      for (angle = 45; angle <= 90; angle++)
      {
        servo.write(angle);
        delay(30);
      }

      //Assigning value of Sensor_1 and Sensor_2 to c & d
      delay(800);
      Sensor1();
      c = distance1;
      Sensor2();
      d = distance3;

      //Printing Distance on LCD..
      print_distance();


      // Scaning from 90 to 135 and taking reading on 135...
      for (angle = 90; angle <= 135; angle++)
      {
        servo.write(angle);
        delay(30);
      }

      //Assigning value of Sensor_1 and Sensor_2 to e & f
      delay(800);
      Sensor1();
      e = distance1;
      Sensor2();
      f = distance3;

      //Printing Distance on LCD..
      print_distance();

      delay(500);

      // Condition to check servo from 45 to 135
      // Assume a , b , c , d , e , f is 6 Ultrasonic sensor's reading....

      // If No Reading from All Sensor

      if ((a > 20 && b > 20) && (c > 20 && d > 20) && (e > 20 && f > 20))
      {
        lcd.print("Nothing Detected...");
        delay(1000);
        lcd.clear();
      }


      // If Reading  from any one sensor
      else if ((a > 20 && b > 20) && (c > 20 && d > 20) && ((e < 20 && f < 20) || (e > 20 && f < 20) || (e < 20 && f > 20)))
      {
        lcd.print("Only One Object..");
        delay(1000);
        lcd.clear();
      }

      else if (((a < 20 && b < 20) || (a > 20 && b < 20) || (a < 20 && b > 20)) && (c > 20 && d > 20) && (e > 20 && f > 20))
      {
        lcd.print("Only One Object..");
        delay(1000);
        lcd.clear();
      }

      else if ((a > 20 && b > 20)  && ((c < 20 && d < 20) || (c > 20 && d < 20) || (c < 20 && d > 20)) && (e > 20 && f > 20))
      {
        lcd.print("Only One Object..");
        delay(1000);
        lcd.clear();
      }


      // If Two Simultaneous Sensor got reading  c d and e f
      else if ((a > 20 && b > 20) && ((c > 20 && d < 20) || (c < 20 && d > 20) || (c < 20 && d < 20)) && ((e < 20 && f < 20) || (e > 20 && f < 20) || (e < 20 && f > 20)))
      {
        digitalWrite(bz, HIGH);
        delay(2000);
        digitalWrite(bz, LOW);
        No_SocialDistancing();
        delay(800);
        lcd.clear();
      }

      else if (((a < 20 && b < 20) || (a > 20 && b < 20) || (a < 20 && b > 20)) && ((c > 20 && d < 20) || (c < 20 && d > 20) || (c < 20 && d < 20)) && (e > 20 && f > 20))
      {
        digitalWrite(bz, HIGH);
        delay(2000);
        digitalWrite(bz, LOW);
        No_SocialDistancing();
        delay(800);
        lcd.clear();
      }


      // If all Sensor got reading together
      else if (((a < 20 && b < 20) || (a > 20 && b < 20) || (a < 20 && b > 20)) && ((c > 20 && d < 20) || (c < 20 && d > 20) || (c < 20 && d < 20)) && ((e < 20 && f < 20) || (e > 20 && f < 20) || (e < 20 && f > 20)))
      {
        digitalWrite(bz, HIGH);
        delay(2000);
        digitalWrite(bz, LOW);
        No_SocialDistancing();
        delay(800);
        lcd.clear();
      }
      else
      {
        SocialDistancing();
        delay(800);
        lcd.clear();
      }
      delay(500);

      // Shift Servo from 135 - 180 to getvalue on 135 again
      //  for (angle = 135; angle <= 180 ; angle++)
      //  {
      //    servo.write(angle);
      //    delay(30);
      //  }
      //  delay(30);
      for (angle = 135; angle >= 0 ; angle--)
      {
        servo.write(angle);
        delay(30);
      }
      delay(500);
    }
  }
}



void Sensor1()
{
  digitalWrite(outputPin, LOW);  // send low pulse for 2μs
  delayMicroseconds(2);
  digitalWrite(outputPin, HIGH); // send high pulse for 10μs
  delayMicroseconds(10);
  digitalWrite(outputPin, LOW);  // back to low pulse
  distance = pulseIn(inputPin, HIGH);  // read echo value
  distance1 = distance / 29 / 2; // in cm
}
void Sensor2()
{
  digitalWrite(outputPin1, LOW);  // send low pulse for 2μs
  delayMicroseconds(2);
  digitalWrite(outputPin1, HIGH); // send high pulse for 10μs
  delayMicroseconds(10);
  digitalWrite(outputPin1, LOW);  // back to low pulse
  distance2 = pulseIn(inputPin1, HIGH);  // read echo value
  distance3 = distance2 / 29 / 2; // in cm
}

void print_distance()
{
  lcd.setCursor(0, 0);
  lcd.print("Sensor_1= ");
  lcd.print(distance1);
  lcd.print("cm");
  lcd.setCursor(0, 1);
  lcd.print("Sensor_2= ");
  lcd.print(distance3);
  lcd.print("cm");
  delay(500);
  lcd.clear();
}

void SocialDistancing()
{
  lcd.setCursor(0, 0);
  lcd.print("Social ");
  lcd.setCursor(0, 1);
  lcd.print("   Distancing....");
}

void No_SocialDistancing()
{
  lcd.setCursor(0, 0);
  lcd.print("No Social ");
  lcd.setCursor(0, 1);
  lcd.print("   Distancing....");
}
