#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int initialAngle1 = 0;   // Initial position for servo1
int initialAngle2 = 180; // Initial position for servo2
int initialAngle3 = 0;   // Initial position for servo3
int initialAngle4 = 180; // Initial position for servo4

void setup() {
  servo1.attach(2);  // Attach servo1 to pin 2
  servo2.attach(3);  // Attach servo2 to pin 3
  servo3.attach(4);  // Attach servo3 to pin 4
  servo4.attach(5);  // Attach servo4 to pin 5
  
  // Set initial positions for each servo
  servo1.write(initialAngle1);
  servo2.write(initialAngle2);
  servo3.write(initialAngle3);
  servo4.write(initialAngle4);
}

void loop() {
  // Move the servos forward and backward continuously
  for (int i = 0; i <= 180; i++) {
    servo1.write(i);          // Increasing angle for servo1
    servo2.write(180 - i);    // Decreasing angle for servo2
    servo3.write(i);          // Increasing angle for servo3
    servo4.write(180 - i);    // Decreasing angle for servo4
    delay(10);  // Adjust delay to control the speed of movement
  }
  
  // Return the servos to their initial positions
  for (int i = 180; i >= 0; i--) {
    servo1.write(i);          // Decreasing angle for servo1
    servo2.write(180 - i);    // Increasing angle for servo2
    servo3.write(i);          // Decreasing angle for servo3
    servo4.write(180 - i);    // Increasing angle for servo4
    delay(10);  // Adjust delay to control the speed of movement
  }
}
