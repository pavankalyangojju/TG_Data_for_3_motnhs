#include <NewPing.h>

// Define motor driver pins
#define IN1 15
#define IN2 16
#define IN3 17
#define IN4 19

// Define ultrasonic sensor pins
#define TRIG_PIN 5
#define ECHO_PIN 18
#define MAX_DISTANCE 200  // Maximum distance to ping (in centimeters)

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

// Function to move the robot forward
void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// Function to move the robot backward
void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// Function to stop the robot
void stopRobot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// Function to turn the robot to the right
void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// Function to turn the robot to the left
void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void setup() {
  // Set motor control pins as outputs
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // Get distance from ultrasonic sensor
  unsigned int distance = sonar.ping_cm();
  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance > 0 && distance < 20) {
    // Obstacle detected, stop and turn right
    stopRobot();
    delay(300); // Small delay before turning
    turnRight();
    delay(500); // Adjust the duration of the turn
    stopRobot();
  } else {
    // Move forward
    moveForward();
  }

  delay(100);
}