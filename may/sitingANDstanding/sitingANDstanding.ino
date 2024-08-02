#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int initialAngle1 = 160; // Initial position for servo1
int initialAngle2 = 10;  // Initial position for servo2
int initialAngle3 = 10; // Initial position for servo3
int initialAngle4 = 180;  // Initial position for servo4

int movingAngle1 = 120;  // Moving position for servo1
int movingAngle2 = 60;   // Moving position for servo2
int movingAngle3 = 60;   // Moving position for servo3
int movingAngle4 = 120;  // Moving position for servo4

void setup() {
  servo1.attach(6);  // Attach servo1 to pin 9
  servo2.attach(7); // Attach servo2 to pin 10
  servo3.attach(8); // Attach servo3 to pin 11
  servo4.attach(9); // Attach servo4 to pin 12
  
  // Set initial positions for each servo
  servo1.write(initialAngle1);
  servo2.write(initialAngle2);
  servo3.write(initialAngle3);
  servo4.write(initialAngle4);
}

void loop() {
  // Move to moving positions
  servo1.write(movingAngle1);
  servo2.write(movingAngle2);
  servo3.write(movingAngle3);
  servo4.write(movingAngle4);
  
  delay(1000);  // Delay to observe the movement
  
  // Return to initial positions
  servo1.write(initialAngle1);
  servo2.write(initialAngle2);
  servo3.write(initialAngle3);
  servo4.write(initialAngle4);
  
  delay(1000);  // Delay to observe the movement
}
