#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>
#include <Servo.h> 
#define LED_PIN 2 // neopixel led pin
#define LED_COUNT 40 // number of leds connected
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800); 
 Servo motor_2;
SoftwareSerial BTSerial(1, 0);  // RX, TX (Pico pins)
int motor1A = 9;  // Motor 1 control pins
int motor1B = 8;
int motor2A = 11;  // Motor 2 control pins
int motor2B = 10;
int servo2 = 130;
int command;

int _arrow[] = {
  0, 1, 0, 1, 0, 1, 1, 1,
  0, 1, 0, 1, 0, 0, 1, 0,
  0, 1, 1, 1, 0, 0, 1, 0,
  0, 1, 0, 1, 0, 0, 1, 0,
  0, 1, 0, 1, 0, 1, 1, 1
};
 int _arrow1[] = {
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 1, 1, 0, 0, 0,
  0, 0, 1, 1, 1, 1, 0, 0,
  0, 1, 0, 1, 1, 0, 1, 0,
  0, 0, 0, 1, 1, 0, 0, 0
};
 int _arrow2[] = {
  0, 0, 0, 1, 1, 0, 0, 0,
  0, 1, 0, 1, 1, 0, 1, 0,
  0, 0, 1, 1, 1, 1, 0, 0,
  0, 0, 0, 1, 1, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0
};
 int _arrow3[] = {
  0, 0, 0, 0, 1, 0, 0, 0,
  0, 0, 0, 0, 0, 1, 0, 0,
  0, 1, 1, 1, 1, 1, 1, 0,
  0, 0, 0, 0, 0, 1, 0, 0,
  0, 0, 0, 0, 1, 0, 0, 0
};
int _arrow4[] = {
  0, 0, 0, 1, 0, 0, 0, 0,
  0, 0, 1, 0, 0, 0, 0, 0,
  0, 1, 1, 1, 1, 1, 1, 0,
  0, 0, 1, 0, 0, 0, 0, 0,
  0, 0, 0, 1, 0, 0, 0, 0
};
int _arrow5[] = {
  0, 1, 1, 1, 0, 1, 1, 1,
  0, 1, 0, 0, 0, 0, 1, 0,
  0, 1, 1, 1, 0, 0, 1, 0,
  0, 0, 0, 1, 0, 0, 1, 0,
  0, 1, 1, 1, 0, 0, 1, 0
};
void setup() {
  BTSerial.begin(9600);
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
   motor_2.attach(4);
   motor_2.write(servo2); 
   strip.begin();            // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();             // Turn OFF all pixels ASAP
  strip.setBrightness(15);  // Set BRIGHTNESS to about 1/5 (max = 255)

  delay(500);

displayIcon(_arrow, sizeof(_arrow), strip.Color(127, 19, 127));
  delay(2000);
}
void loop() {
  if (BTSerial.available()) {
    command = BTSerial.read();
    Serial.println(command);
 
  
    if (command == 1) {
      // Forward
      digitalWrite(motor1A, HIGH);
      digitalWrite(motor2A, HIGH);
        displayIcon(_arrow1, sizeof(_arrow1), strip.Color(0, 0, 150));
  
    } 
    if (command == 2) {
      // Backward
      digitalWrite(motor1B, HIGH);
      digitalWrite(motor2B, HIGH);
        displayIcon(_arrow2, sizeof(_arrow2), strip.Color(0, 150,  0));
 
    }  
    if (command == 3) {
      // Left
      digitalWrite(motor1B, HIGH);
      digitalWrite(motor2A, HIGH);
        displayIcon(_arrow4, sizeof(_arrow4), strip.Color(150, 0, 0));
  
    } 
    if (command == 4) {
      // Right
      digitalWrite(motor1A, HIGH);
      digitalWrite(motor2B, HIGH);
        displayIcon(_arrow3, sizeof(_arrow3), strip.Color(45, 150, 150));
 
    }

    if (command == 5) {
      // Forward
      digitalWrite(motor1A, LOW);
       digitalWrite(motor1B, LOW);
      digitalWrite(motor2A, LOW);
      digitalWrite(motor2B, LOW);
      displayIcon(_arrow5, sizeof(_arrow5), strip.Color(150, 150, 50));
  
    }
    
}
     if (command ==23) {
if(servo2<140){servo2 = servo2+1;}
motor_2.write(servo2);
     
    }
     if (command == 24) {
 if(servo2>60){servo2 = servo2-1;}
motor_2.write(servo2); 
     
    }
}
void displayIcon(int _array[], int len, uint32_t color) {
  strip.clear();
  for (int i = 0; i < len; i++) {
    if (_array[i])
      strip.setPixelColor(i, color);
  }
  strip.show();
}

 
