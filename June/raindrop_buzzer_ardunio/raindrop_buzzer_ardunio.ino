const int rainSensorPin = 2;  // Pin connected to DO pin of the rain sensor module
const int buzzerPin = 8;      // Pin connected to the buzzer

void setup() {
  pinMode(rainSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = digitalRead(rainSensorPin);
  
  if (sensorValue == LOW) {
    // Rain detected
    digitalWrite(buzzerPin, HIGH);
    Serial.println("Rain detected!");
  } else {
    // No rain
    digitalWrite(buzzerPin, LOW);
    Serial.println("No rain.");
  }
  
  delay(500);
}
