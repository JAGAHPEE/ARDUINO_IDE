#define trigPin 7
#define echoPin 2
#define buzzer 9
int duration, distance;
 
void setup(){
 Serial.begin(9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(buzzer, OUTPUT);
}
 
void loop(){
  
  
  int count=0;
  int f=0;
  for(count=0;count<=5;)
  {
    dist();
      if (distance <20 && distance >5)
    {
      f=f+1;
      count++;
    }
    else
    {
      count++;
    }
    delay(1000);
  }
  Serial.println(f);
  if (f>2)
  {
    digitalWrite(buzzer,HIGH);
    delay(2000);
    digitalWrite(buzzer,LOW);
  }
  else if(f<=2)
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
