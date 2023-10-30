#include <ESP32Servo.h>

Servo myservo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position
void setup() {
	myservo.attach(33); // attaches the servo on pin 18 to the servo object
}

void loop() {

	for (pos = 0; pos <= 100; pos += 10) { // goes from 0 degrees to 180 degrees
		// in steps of 1 degree
		myservo.write(pos);    // tell servo to go to position in variable 'pos'
		delay(10);             // waits 15ms for the servo to reach the position
	}
 delay(800);
	for (pos = 100; pos >= 0; pos -= 10) { // goes from 180 degrees to 0 degrees
		myservo.write(pos);    // tell servo to go to position in variable 'pos'
		delay(10);             // waits 15ms for the servo to reach the position
	}
 delay(800);
}
