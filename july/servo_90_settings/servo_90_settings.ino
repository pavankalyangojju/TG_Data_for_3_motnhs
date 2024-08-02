#include <Servo.h>

Servo myservo;  // create servo object to control a servo

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  myservo.write(0);  // sets the servo position to 90 degrees
  delay(1000);        // waits for the servo to reach the position
}
