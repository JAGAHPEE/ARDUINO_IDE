int RED=11;
int YELLOW=12;
void setup() {
  pinMode(RED,OUTPUT);
  pinMode(YELLOW,OUTPUT);
}

void loop() {
  digitalWrite(RED,HIGH);
  delay(1000);
  digitalWrite(RED,LOW);
  delay(1000);

}
