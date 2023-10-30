#include <Servo.h>
Servo myservo;

#define trigPin 7
#define echoPin 2
#define buzzer 9
int duration, distance;
int pos = 0;

void setup(){
 Serial.begin(9600);
 myservo.attach(6);  // attaches the servo on pin 9 to the servo object
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(buzzer, OUTPUT);
}
 
void loop(){

  
  
  int count=0;
  int f=0;

    for (pos = 20; pos <= 155;) 
    { 
          myservo.write(pos);              
          dist();
          if (distance <150 && distance >5)
           {
              f=f+1;
              pos+=10;
           }
          else
           {
                pos+=10;
           }
            
        delay(200);                       // waits 15ms for the servo to reach the position
    }
    delay(200);
  for (pos = 155; pos >= 20; pos -= 1) 
  {
    myservo.write(pos);             
    delay(15);                       
  }
  

  Serial.println(f);
  if (f>9)
  {
    digitalWrite(buzzer,HIGH);
    delay(2000);
    digitalWrite(buzzer,LOW);
  }
  else if(f<=9)
  {
    digitalWrite(buzzer,LOW);
  }
  delay(1000);
  
}
void dist()
{
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance = (duration/2) /29.1; 
  
  Serial.print (distance);
  Serial.println (" cm");
}
