String incomingByte;
void setup() {
  Serial.begin(9600);
  //  Serial1.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {

    String incomingByte = Serial.readString(); // read the incoming byte:

    Serial.print(" I received:");

    Serial.println(incomingByte);

  }
}
