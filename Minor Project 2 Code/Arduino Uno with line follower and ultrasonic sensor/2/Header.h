#define MotorAip1 7
#define MotorAip2 6
//Left motor
#define MotorBip1 8
#define MotorBip2 9
void forward()
{
  digitalWrite(MotorAip1, HIGH);
  digitalWrite(MotorAip2, LOW);
  digitalWrite(MotorBip1, HIGH);
  digitalWrite(MotorBip2, LOW);
}
