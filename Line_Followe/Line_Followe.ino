#define IR1 4      //Right sensor
#define IR2 12     //Middle Sensor
#define IR3 13      //Left Sensor
//13 12 5 4 3 2
//Motor one
//Right Motor
#define MotorAip1 5
#define MotorAip2 9
//
//// motor two
//int low = 100;
//int high = 200;

//Left motor
#define MotorBip1 10
#define MotorBip2 11
#define speed1 5
#define speed2 6
void setup()
{
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(MotorAip1, OUTPUT);
  pinMode(MotorAip2, OUTPUT);
  pinMode(MotorBip1, OUTPUT);
  pinMode(MotorBip2, OUTPUT);
  digitalWrite(MotorAip1, LOW);
  digitalWrite(MotorAip2, LOW);
  digitalWrite(MotorBip1, LOW);
  digitalWrite(MotorBip2, LOW);
  Serial.begin(9600);

  analogWrite(speed1, high);
  analogWrite(speed2, high);

}
void loop()
{

  if (digitalRead(IR1)==0 && digitalRead(IR2)==1&& digitalRead(IR3)==0)
  {
    //Move both the Motors
    analogWrite(speed1, high);
    analogWrite(speed2, high);
    digitalWrite(MotorAip1, LOW);
    digitalWrite(MotorAip2, HIGH);
    digitalWrite(MotorBip1, LOW);
    digitalWrite(MotorBip2, HIGH);
    Serial.println("Forward");


  }
  //lRight
  else if (digitalRead(IR1)==1 && digitalRead(IR2)==0 && digitalRead(IR3)==0)
  {
    analogWrite(speed1, low);
    analogWrite(speed2, low);
    digitalWrite(MotorAip1, HIGH);
    digitalWrite(MotorAip2, LOW);
    digitalWrite(MotorBip1, HIGH);
    digitalWrite(MotorBip2, HIGH);
    Serial.println("RIGHT");
  }
  //Left
  else if (digitalRead(IR1)==0 && digitalRead(IR2)==0&& digitalRead(IR3)==1)
  {
    analogWrite(speed1, low);
    analogWrite(speed2, low);
    digitalWrite(MotorAip1, HIGH);
    digitalWrite(MotorAip2, HIGH);
    digitalWrite(MotorBip1, HIGH);
    digitalWrite(MotorBip2, LOW);
    Serial.println("LEFT");
  }

}
