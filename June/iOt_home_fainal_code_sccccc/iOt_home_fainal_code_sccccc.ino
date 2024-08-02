#define BLYNK_TEMPLATE_ID "TMPL3c9AoK1Qy"
#define BLYNK_TEMPLATE_NAME "IoT Home testing"
#define BLYNK_AUTH_TOKEN "8sxFgsHm8SvhU1BarHHbZDf6S3mtbdZp"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "Gojju";  // type your wifi name
char pass[] = "123456789";  // type your wifi password

BlynkTimer timer;

#define DHTPIN 27 // Connect DHT sensor to pin D2 in NODE MCU
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);

#define LED_PIN 19 // Define the LED pin, you can change it to the pin you are using
#define GAS_SENSOR_PIN 32 // Example ADC pin number on ESP32
#define SOIL_SENSOR_PIN 33 // Analog pin for soil moisture sensor
#define PUMP_PIN 26 // Pin connected to the motor pump
#define FAN_PIN 5 // Pin connected to the fan
#define BUZZER_PIN 23 // Pin connected to the buzzer

int gasValue;
bool gasDetected = false;

void readGasSensor() {
    gasValue = analogRead(GAS_SENSOR_PIN);
    
    // Define your threshold here (adjust as per your sensor's sensitivity)
    int gasThreshold = 1000;  // Example threshold value
    
    // Determine gas detection state
    if (gasValue > gasThreshold) {
        gasDetected = true;
        digitalWrite(BUZZER_PIN, LOW); // Turn on the buzzer
        Serial.println("NO Gas detected! Buzzer OFF");
    } else {
        gasDetected = false;
        digitalWrite(BUZZER_PIN, HIGH); // Turn off the buzzer
        Serial.println("Gas detected. Buzzer ON");
    }
    
    // Send gas detection state to Blynk only if it changes
    static bool lastGasDetected = false;
    if (gasDetected != lastGasDetected) {
        Blynk.virtualWrite(V3, gasDetected ? 0 : 1);
        Serial.print("Gas Sensor Value : ");
        Serial.println(gasDetected ? 0 : 1);
        lastGasDetected = gasDetected;
    }
}

void readSoilSensor() {
    int soilMoisture = analogRead(SOIL_SENSOR_PIN);
    // Scale your soil moisture reading to a meaningful range (0-100, for example)
    int soilMoisturePercent = map(soilMoisture, 0, 4095, 100, 0); // Invert the range from 100 to 0

    // Send soil moisture percentage to Blynk
    Blynk.virtualWrite(V4, soilMoisturePercent);
    Serial.print("Soil Moisture : ");
    Serial.println(soilMoisturePercent);

    // Check if soil moisture is below a threshold (e.g., 0%) to turn on motor pump
    if (soilMoisturePercent <= 0) {
        digitalWrite(PUMP_PIN, HIGH); // Turn on motor pump
        Serial.println("Motor Pump ON");
    } else {
        digitalWrite(PUMP_PIN, LOW); // Turn off motor pump
        Serial.println("Motor Pump OFF");
    }
}

void sendSensor() {
    float h = dht.readHumidity();
    float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

    if (isnan(h) || isnan(t)) {
        Serial.println("Failed to read from DHT sensor!");
        return;
    }
    
    // Send temperature and humidity to Blynk
    Blynk.virtualWrite(V0, t);
    Blynk.virtualWrite(V1, h);
    Serial.print("Temperature : ");
    Serial.print(t);
    Serial.print("    Humidity : ");
    Serial.println(h);

    // Read LED state and send to Blynk
    int ledState = digitalRead(LED_PIN);
    Blynk.virtualWrite(V2, ledState);
    Serial.print("LED State : ");
    Serial.println(ledState);

    // Ensure gas detection state is sent to Blynk
    readGasSensor();
    
    // Read soil moisture sensor and send to Blynk
    readSoilSensor();
    
    // Fan control based on temperature
    int tempThreshold = 32; // Set the temperature threshold for fan
    if (t >= tempThreshold) {
        digitalWrite(FAN_PIN, HIGH); // Turn on the fan
        Serial.println("Fan ON");
    } else {
        digitalWrite(FAN_PIN, LOW); // Turn off the fan
        Serial.println("Fan OFF");
    }
}

void setup() {   
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW); // Start with LED off

    pinMode(PUMP_PIN, OUTPUT);
    digitalWrite(PUMP_PIN, LOW); // Start with motor pump off

    pinMode(FAN_PIN, OUTPUT);
    digitalWrite(FAN_PIN, LOW); // Start with fan off

    pinMode(BUZZER_PIN, OUTPUT);
    digitalWrite(BUZZER_PIN, LOW); // Start with buzzer off

    Blynk.begin(auth, ssid, pass);
    dht.begin();
    timer.setInterval(1000L, sendSensor); // Set the interval to 1 second
}

void loop() {
    Blynk.run();
    timer.run();
}

// Blynk function to control LED from the app
BLYNK_WRITE(V2) {
    int pinValue = param.asInt();
    digitalWrite(LED_PIN, pinValue);
}