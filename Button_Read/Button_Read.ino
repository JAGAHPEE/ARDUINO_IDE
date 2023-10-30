int start=12;
int a;
void setup() {
 Serial.begin(9600);
  pinMode(start,INPUT);
}

void loop() {
a=digitalRead(start);
Serial.println(a);

}
