#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
Servo servo7;
Servo servo8;

int initialAngle1 = 90; // Initial position for servo1(incress)
int initialAngle2 = 90;   // Initial position for servo2(dec)
int initialAngle3 = 90;   // Initial position for servo3(inc)
int initialAngle4 = 90; // Initial position for servo4(dec)
int initialAngle5 = 90; // Initial position for servo1(incress)
int initialAngle6 = 90;   // Initial position for servo2(dec)           
int initialAngle7 = 90;   // Initial position for servo3(inc)
int initialAngle8 = 90; // Initial position for servo4(dec)
void setup() {
  servo1.attach(2);  // Attach servo1 to pin 9
  servo2.attach(3); // Attach servo2 to pin 10
  servo3.attach(4); // Attach servo3 to pin 11
  servo4.attach(5); // Attach servo4 to pin 12
  servo5.attach(6);  // Attach servo1 to pin 9
  servo6.attach(7); // Attach servo2 to pin 10
  servo7.attach(8); // Attach servo3 to pin 11
  servo8.attach(9); // Attach servo4 to pin 12
  
  // Set initial positions for each servo
  servo1.write(initialAngle1);
  servo2.write(initialAngle2);
  servo3.write(initialAngle3);
  servo4.write(initialAngle4);
  servo5.write(initialAngle5);
  servo6.write(initialAngle6);
  servo7.write(initialAngle7);
  servo8.write(initialAngle8);
}

void loop() {
  // Your loop code here
}
