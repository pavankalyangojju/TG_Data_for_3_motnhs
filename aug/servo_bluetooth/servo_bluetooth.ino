#include <Servo.h>

Servo myservo;  // create servo object to control a servo
int bluetoothTx = 10;  // TX-O pin of bluetooth mate, Arduino D2
int bluetoothRx = 11;  // RX-I pin of bluetooth mate, Arduino D3
char data; // variable to receive data from the serial port

void setup() {
  Serial.begin(9600);  // set the data rate for the Serial port
  Serial.begin(9600);  // set the data rate for the SoftwareSerial port
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  if (Serial.available()) {
    data = Serial.read();  // read the incoming data from the Bluetooth module
    int angle = map(data, '0', '9', 0, 180);  // map the input range to 0-180 degrees
    myservo.write(angle);  // sets the servo position
  }
}
