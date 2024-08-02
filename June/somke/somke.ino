const int smokeSensorPin = 2;  // Pin connected to DO pin of the smoke sensor module
const int ledPin = 8;          // Pin connected to the LED

void setup() {
  pinMode(smokeSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = digitalRead(smokeSensorPin);
  
  if (sensorValue == LOW) {  // Change to LOW for MQ-2 sensor
    // Smoke detected
    digitalWrite(ledPin, HIGH);
    Serial.println("Smoke detected!");
  } else {
    // No smoke
    digitalWrite(ledPin, LOW);
    Serial.println("No smoke.");
  }
  
  delay(500);
}
