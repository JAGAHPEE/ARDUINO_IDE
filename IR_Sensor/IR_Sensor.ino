int ir = 26;
int motion;
void setup() {
  Serial.begin(9600);
  pinMode(ir, INPUT);
}

void loop()
{
  motion = digitalRead(ir);
  Serial.println(motion);
  delay(1000);
}
