#define BLYNK_PRINT Serial

// Add your Blynk Template ID and Template Name
#define BLYNK_TEMPLATE_ID "TMPL3pkuIgVRv"
#define BLYNK_TEMPLATE_NAME "wifi car"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>

// Define the motor pins
#define IN1 19
#define IN2 17
#define IN3 15
#define IN4 16

// Define the LED pins
#define LED1 13
#define LED2 4

// Define the ultrasonic sensor pins
#define TRIG_PIN 5
#define ECHO_PIN 18

// Servo motor pin
#define SERVO_PIN 33

Servo myservo;
BlynkTimer timer;

// Variables for the Blynk widget values
bool forward = 0;
bool backward = 0;
bool left = 0;
bool right = 0;
bool ledsState = 0;

char auth[] = "oPXRolrLWiw3ngU222ZfGW3nTFmjnweM";

// Enter your Wi-Fi SSID and password
char ssid[] = "Gojju";
char pass[] = "123456789";

void setup() {
  Serial.begin(9600);

  // Set the motor pins as output pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Set the LED pins as output pins
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  // Set the ultrasonic sensor pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Attach the servo motor to the defined pin
  myservo.attach(SERVO_PIN);
  myservo.write(0); // Initialize servo to 0 degrees

  // Initialize the Blynk library
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);

  // Set a timer to check for obstacles periodically
  timer.setInterval(500L, checkObstacle);
}

// Forward
BLYNK_WRITE(V0) {
  forward = param.asInt();
}

// Backward
BLYNK_WRITE(V1) {
  backward = param.asInt();
}

// Left
BLYNK_WRITE(V2) {
  left = param.asInt();
}

// Right
BLYNK_WRITE(V3) {
  right = param.asInt();
}

// LEDs
BLYNK_WRITE(V4) {
  ledsState = param.asInt();
  digitalWrite(LED1, ledsState);
  digitalWrite(LED2, ledsState);
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
  } else {
    carStop();
    Serial.println("carStop");
  }
}

void loop() {
  Blynk.run(); // Run the Blynk function
  smartcar(); // Call the main function
  timer.run();
}

// Ultrasonic sensor function to check for obstacles
void checkObstacle() {
  long duration, distance;
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration / 2) / 29.1; // Convert to centimeters

  if (distance < 10) { // If an object is closer than 10 cm
    myservo.write(90); // Move servo to 90 degrees
    Serial.println("Object detected! Servo at 90 degrees");
  } else {
    myservo.write(0); // Move servo to 0 degrees
    Serial.println("No object detected. Servo at 0 degrees");
  }
}

/**************Motor movement functions*****************/
void carForward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void carBackward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void carLeft() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void carRight() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void carStop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
