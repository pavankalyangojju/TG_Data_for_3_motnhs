#include "BluetoothSerial.h"

// Motor A connections
int enA = 25;
int in1 = 15;
int in2 = 16;

// Motor B connections
int enB = 33;
int in3 = 19;
int in4 = 17;

BluetoothSerial SerialBT;

void setup() {
  // Motor setup
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  // Start Bluetooth
  SerialBT.begin("ESP32_RC_Car"); // Bluetooth name
  Serial.println("Bluetooth device is ready to pair");
}

void loop() {
  if (SerialBT.available()) {
    char command = SerialBT.read();
    
    switch(command) {
      case 'F': // Forward
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        analogWrite(enA, 255); // Full speed
        analogWrite(enB, 255); // Full speed
        break;
      
      case 'B': // Backward
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        analogWrite(enA, 255);
        analogWrite(enB, 255);
        break;
        
      case 'L': // Left
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        analogWrite(enA, 255);
        analogWrite(enB, 255);
        break;
        
      case 'R': // Right
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        analogWrite(enA, 255);
        analogWrite(enB, 255);
        break;
        
      case 'S': // Stop
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        break;
    }
  }
}
