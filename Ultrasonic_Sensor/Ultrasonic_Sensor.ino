#include <Servo.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,5,4,3,2);
int inputPin=16;  // connect digital I/O d4 to the ECHO/Rx Pin
int outputPin=17; // connect digital I/O d5 to the TRIG/TX Pin
int inputPin1=0;  // connect digital I/O d4 to the ECHO/Rx Pin
int outputPin1=1; // connect digital I/O d5 to the TRIG/TX Pin
int servoPin = 6;
int bz =7;
int vali[6];
int valj[6];
int i,j;
Servo servo;
int angle = 0;  // servo position in degrees
void setup() 
{
  pinMode(inputPin, INPUT);
  pinMode(outputPin, OUTPUT);
  pinMode(inputPin1, INPUT);
  pinMode(outputPin1, OUTPUT);
  pinMode(bz, OUTPUT);
  digitalWrite(bz, LOW);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("WELCOME TO IIST");
  lcd.setCursor(0,1);
  lcd.print("INDORE");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Covid Protective");
  lcd.setCursor(0,1);
  lcd.print("Robot ");
  delay(2000);
  lcd.clear();
  servo.attach(servoPin);
}
void loop() 
{
   digitalWrite(outputPin, LOW);  // send low pulse for 2μs
   delayMicroseconds(2);
   digitalWrite(outputPin, HIGH); // send high pulse for 10μs
   delayMicroseconds(10);
   digitalWrite(outputPin, LOW);  // back to low pulse
   int distance = pulseIn(inputPin, HIGH);  // read echo value
   int distance1= distance/29/2;  // in cm

   digitalWrite(outputPin1, LOW);  // send low pulse for 2μs
   delayMicroseconds(2);
   digitalWrite(outputPin1, HIGH); // send high pulse for 10μs
   delayMicroseconds(10);
   digitalWrite(outputPin1, LOW);  // back to low pulse
   int distance2 = pulseIn(inputPin1, HIGH);  // read echo value
   int distance3= distance2/29/2;  // in cm
   
   lcd.setCursor(0, 0);
   lcd.print("S1=");
   lcd.print(distance1);
   lcd.print("cm ");
   lcd.setCursor(0,1);
   lcd.print("S2=");
   lcd.print(distance3);
   lcd.print("cm ");
   delay(500);
   lcd.clear();
   // scan from 0 to 180 degrees
    for(angle =0,i=0,j=0; angle <=90,i<5,j<5; i++,j++,angle+=40)
    {   
        dist1();
        dist2();
        vali[i]=distance ;
        valj[j]=distance1;
        servo.write(angle);
        delay(15);
    } 
    
    // now scan back from 180 to 0 degrees
    for(angle = 90; angle >=0; angle--)
    {
       servo.write(angle);
       delay(15);
    }
    if (vali[0] <30 || valj[0]<30)
    {
      if (vali[1]<30 || valj[1]<30)
      {
        digitalWrite(bz,HIGH);
        delay(1500);
        digitalWrite(bz,HIGH);
      }
    }
delay(100);
lcd.clear();
}

void dist1()
{
   int distance = pulseIn(inputPin, HIGH);  // read echo value
   int distance1= distance/29/2;  // in cm
}
void dist2()
{
   int distance2 = pulseIn(inputPin1, HIGH);  // read echo value
   int distance3= distance2/29/2;  // in cm
}
