#include <Servo.h>

#define trigPin 9
#define echoPin 8
#define ISDPin 10

Servo servo1;
Servo servo2;
int sound = 250;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo1.attach(5);
  servo2.attach(3);
}

void loop() {
  long duration, distance;

  // Send a pulse from the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the pulse from the ultrasonic sensor
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  // Check the distance and control the servos and ISD pin accordingly
  if (distance < 100) {
    Serial.println("The distance is less than 100 cm");
    servo1.write(90);
    servo2.write(0);
    digitalWrite(ISDPin, HIGH);
    delay(1500);
  } else {
    servo1.write(0);
    servo2.write(90);
    digitalWrite(ISDPin, LOW);
  }

  // Additional distance check and printing
  if (distance > 60 || distance <= 0) {
    Serial.println("The distance is more than 60 cm or invalid");
  } else {
    Serial.print(distance);
    Serial.println(" cm");
  }

  delay(500);
}
