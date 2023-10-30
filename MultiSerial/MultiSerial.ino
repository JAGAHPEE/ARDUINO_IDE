int a;
void setup() {
  // initialize both serial ports:
  Serial.begin(9600);
}

void loop() {

  // read from port 0, send to port 1:
  while (Serial.available()) {
    a = Serial.read();
    Serial.print(a);
  }
}
