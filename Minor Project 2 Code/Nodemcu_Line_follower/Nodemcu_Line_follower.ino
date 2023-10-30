// Black Line Follower 
#define IR1 11      //Right sensor
#define IR2 12      //Middle Sensor
#define IR3 13      //Left Sensor
#define MotorAip1 5
#define MotorAip2 6
// motor two

//Left motor
#define MotorBip1 3
#define MotorBip2 4
void setup() 
{
  pinMode(IR1,INPUT);
  pinMode(IR2,INPUT);
  pinMode(IR3,INPUT);
  pinMode(MotorAip1,OUTPUT);
  pinMode(MotorAip2,OUTPUT);
  pinMode(MotorBip1,OUTPUT);
  pinMode(MotorBip2,OUTPUT);
  digitalWrite(MotorAip1,LOW);
  digitalWrite(MotorAip2,LOW);
  digitalWrite(MotorBip1,LOW);
  digitalWrite(MotorBip2,LOW);
}
void loop() 
{

   if(digitalRead(IR1)==1 && digitalRead(IR2)==1&& digitalRead(IR3)==1) //IR will not glow on black line
  {
    //Stop both Motors
    digitalWrite(MotorAip1,LOW);
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,LOW);
    lcd.clear();
    lcd.print("Stop");
    Serial.write("Stop");
    delay(500);
  }

   if(digitalRead(IR1)==0 && digitalRead(IR2)==1&& digitalRead(IR3)==0)  //IR not on black line
  {
    //Move both the Motors
    digitalWrite(MotorAip1,HIGH);
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,HIGH);
    digitalWrite(MotorBip2,LOW);

  }

  else if(digitalRead(IR1)==1 && digitalRead(IR2)==0 && digitalRead(IR3)==0)
  {
     digitalWrite(MotorAip1,HIGH);     
     digitalWrite(MotorAip2,HIGH);
     digitalWrite(MotorBip1,HIGH);
     digitalWrite(MotorBip2,LOW);
  }

  else if(digitalRead(IR1)==0 && digitalRead(IR2)==0&& digitalRead(IR3)==1)
  {
    digitalWrite(MotorAip1,HIGH);   
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,HIGH);
    digitalWrite(MotorBip2,HIGH);
  
  }

//  else
//  {
//    //Stop both the motors
//    lcd.clear();
//    lcd.print("Stop");
//    delay(500);
//    digitalWrite(MotorAip1,LOW);
//    digitalWrite(MotorAip2,LOW);
//    digitalWrite(MotorBip1,LOW);
//    digitalWrite(MotorBip2,LOW);
//
//  }

}
