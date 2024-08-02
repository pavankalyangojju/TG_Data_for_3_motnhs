#define BLYNK_TEMPLATE_ID "TMPL3Hc_Dynjj"
#define BLYNK_TEMPLATE_NAME "IoT Home testing"
#define BLYNK_AUTH_TOKEN "Sea5-xP0XhPldJKGjD6nNP0k-8Q-sr0e"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "Gojju";  // type your wifi name
char pass[] = "123456789";  // type your wifi password

BlynkTimer timer;

#define DHTPIN 27 //Connect Out pin to D2 in NODE MCU
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);

#define LED_PIN 4 // Define the LED pin, you can change it to the pin you are using
#define GAS_SENSOR_PIN 32 // Example ADC pin number on ESP32

int gasValue;
bool gasDetected = false;

void readGasSensor() {
    gasValue = analogRead(GAS_SENSOR_PIN);
    
    // Define your threshold here (adjust as per your sensor's sensitivity)
    int gasThreshold = 1000;  // Example threshold value
    
    // Determine gas detection state
    if (gasValue > gasThreshold) {
        gasDetected = true;
    } else {
        gasDetected = false;
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
}

void setup() {   
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW); // Start with LED off

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
