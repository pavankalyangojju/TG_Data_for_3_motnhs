#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int initialAngle1 = 90; // Initial position for servo1 (increase)
int initialAngle2 = 90; // Initial position for servo2 (decrease)
int initialAngle3 = 90; // Initial position for servo3 (increase)
int initialAngle4 = 90; // Initial position for servo4 (decrease)

int currentAngle1 = initialAngle1; // Current position for servo1
int currentAngle2 = initialAngle2; // Current position for servo2
int currentAngle3 = initialAngle3; // Current position for servo3
int currentAngle4 = initialAngle4; // Current position for servo4

bool moved1 = false; // Flag to check if servo1 has moved
bool moved2 = false; // Flag to check if servo2 has moved
bool moved3 = false; // Flag to check if servo3 has moved
bool moved4 = false; // Flag to check if servo4 has moved

void setup() {
  servo1.attach(2); // Attach servo1 to pin 2
  servo2.attach(3); // Attach servo2 to pin 3
  servo3.attach(4); // Attach servo3 to pin 4
  servo4.attach(5); // Attach servo4 to pin 5
  
  // Set initial positions for each servo
  servo1.write(initialAngle1);
  servo2.write(initialAngle2);
  servo3.write(initialAngle3);
  servo4.write(initialAngle4);
}

void loop() {
  if (!moved1 || !moved2 || !moved3 || !moved4) {
    // Increase servo1 angle by 10 degrees
    if (!moved1) {
      currentAngle1 += 30;
      if (currentAngle1 > 180) {
        currentAngle1 = 180; // Ensure it does not exceed 180 degrees
      }
      servo1.write(currentAngle1);
      moved1 = true; // Set the flag to true to indicate movement
    }

    // Decrease servo2 angle by 10 degrees
    if (!moved2) {
      currentAngle2 -= 30;
      if (currentAngle2 < 0) {
        currentAngle2 = 0; // Ensure it does not go below 0 degrees
      }
      servo2.write(currentAngle2);
      moved2 = true; // Set the flag to true to indicate movement
    }

    // Increase servo3 angle by 10 degrees
    if (!moved3) {
      currentAngle3 += 30;
      if (currentAngle3 > 180) {
        currentAngle3 = 180; // Ensure it does not exceed 180 degrees
      }
      servo3.write(currentAngle3);
      moved3 = true; // Set the flag to true to indicate movement
    }

    // Decrease servo4 angle by 10 degrees
    if (!moved4) {
      currentAngle4 -= 30;
      if (currentAngle4 < 0) {
        currentAngle4 = 0; // Ensure it does not go below 0 degrees
      }
      servo4.write(currentAngle4);
      moved4 = true; // Set the flag to true to indicate movement
    }

    delay(1000); // Wait for 1 second after all servos have moved
  }

  // After the first increment/decrement, no further action is needed
}