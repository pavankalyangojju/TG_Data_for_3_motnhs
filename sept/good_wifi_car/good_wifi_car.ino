#define BLYNK_TEMPLATE_ID "TMPL3N42Rzk65"
#define BLYNK_TEMPLATE_NAME "wifi car"
// #define BLYNK_AUTH_TOKEN "M5Ya4yFMd3hgxlhQahAkHjWk0fu6E-bT"
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Define the motor pins
#define IN1 12
#define IN2 14
#define IN3 27
#define IN4 26

BlynkTimer timer;
// Variables for the Blynk widget values
bool forward = 0;
bool backward = 0;
bool left = 0;
bool right = 0;

// Define motor speed (0-255)
int motorSpeed = 178; // Adjust this value to change speed

char auth[] = "M5Ya4yFMd3hgxlhQahAkHjWk0fu6E-bT";

//Enter your WIFI SSID and password
char ssid[] = "Gojju";
char pass[] = "123456789";

void setup() {
  Serial.begin(9600);
  //Set the motor pins as output pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  // Initialize the Blynk library
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

// forward
BLYNK_WRITE(V0) {
  forward = param[0].asInt();
}

// back
BLYNK_WRITE(V1) {
  backward = param[0].asInt();
}

// left
BLYNK_WRITE(V2) {
  left = param[0].asInt();
}

// right
BLYNK_WRITE(V3) {
  right = param[0].asInt();
}

// Check these values using the IF condition
void smartcar() {
  if (forward == 1) {
    carForward();
    Serial.println("carForward");
  } else if (backward == 1) {
    carBackward();
    Serial.println("carBackward");
  } else if (left == 1) {
    carLeft();
    Serial.println("carLeft");
  } else if (right == 1) {
    carRight();
    Serial.println("carRight");
  } else if (forward == 0 && backward == 0 && left == 0 && right == 0) {
    carStop();
    Serial.println("carStop");
  }
}

void loop() {
  Blynk.run();  // Run the Blynk function
  smartcar();   // Call the main function
  timer.run();
}

/**************Motor movement functions with speed control*****************/
void carForward() {
  analogWrite(IN1, 0);
  analogWrite(IN2, motorSpeed);
  analogWrite(IN3, motorSpeed);
  analogWrite(IN4, 0);
}

void carBackward() {
  analogWrite(IN1, motorSpeed);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  analogWrite(IN4, motorSpeed);
}

void carLeft() {
  analogWrite(IN1, motorSpeed);
  analogWrite(IN2, 0);
  analogWrite(IN3, motorSpeed);
  analogWrite(IN4, 0);
}

void carRight() {
  analogWrite(IN1, 0);
  analogWrite(IN2, motorSpeed);
  analogWrite(IN3, 0);
  analogWrite(IN4, motorSpeed);
}

void carStop() {
  analogWrite(IN1, 0);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  analogWrite(IN4, 0);
}
