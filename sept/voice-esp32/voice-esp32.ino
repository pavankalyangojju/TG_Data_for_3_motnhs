#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// Auth Token from Blynk
char auth[] = "**************";

// Your WiFi credentials
char ssid[] = "***************";
char pass[] = "*************";

// Motor pins
int motorA_IN1 = 14;
int motorA_IN2 = 27;
int motorB_IN3 = 26;
int motorB_IN4 = 25;

// Forward Command
void moveForward() {
  digitalWrite(motorA_IN1, HIGH);
  digitalWrite(motorA_IN2, LOW);
  digitalWrite(motorB_IN3, HIGH);
  digitalWrite(motorB_IN4, LOW);
}

// Backward Command
void moveBackward() {
  digitalWrite(motorA_IN1, LOW);
  digitalWrite(motorA_IN2, HIGH);
  digitalWrite(motorB_IN3, LOW);
  digitalWrite(motorB_IN4, HIGH);
}

// Left Turn Command
void turnLeft() {
  digitalWrite(motorA_IN1, LOW);
  digitalWrite(motorA_IN2, HIGH);
  digitalWrite(motorB_IN3, HIGH);
  digitalWrite(motorB_IN4, LOW);
}

// Right Turn Command
void turnRight() {
  digitalWrite(motorA_IN1, HIGH);
  digitalWrite(motorA_IN2, LOW);
  digitalWrite(motorB_IN3, LOW);
  digitalWrite(motorB_IN4, HIGH);
}

// Stop Command
void stopMoving() {
  digitalWrite(motorA_IN1, LOW);
  digitalWrite(motorA_IN2, LOW);
  digitalWrite(motorB_IN3, LOW);
  digitalWrite(motorB_IN4, LOW);
}

// Function to handle Blynk voice commands
BLYNK_WRITE(V1) {
  String command = param.asStr();

  if (command == "forward") {
    moveForward();
  } else if (command == "backward") {
    moveBackward();
  } else if (command == "left") {
    turnLeft();
  } else if (command == "right") {
    turnRight();
  } else if (command == "stop")
