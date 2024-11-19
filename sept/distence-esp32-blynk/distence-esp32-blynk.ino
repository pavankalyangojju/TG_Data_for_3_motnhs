#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// Blynk Auth Token
char auth[] = "YourAuthToken";

// WiFi credentials
char ssid[] = "YourSSID";
char pass[] = "YourPassword";

// Ultrasonic Sensor Pins
#define TRIG_PIN 5
#define ECHO_PIN 18

// Function to calculate distance
long readUltrasonicDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  long distance = (duration * 0.034) / 2;
  
  return distance; // Distance in cm
}

// Send distance to Blynk App
void sendDistance() {
  long distance = readUltrasonicDistance();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Send distance to Blynk Virtual Pin V1
  Blynk.virtualWrite(V1, distance);
}

void setup() {
  // Start serial communication
  Serial.begin(115200);

  // Initialize Ultrasonic Sensor pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Connect to WiFi and Blynk
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
  
  // Send distance every 2 seconds
  sendDistance();
  delay(2000);
}
