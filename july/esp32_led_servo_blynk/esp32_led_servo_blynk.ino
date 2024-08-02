#define BLYNK_TEMPLATE_ID "TMPL3EA5vFuw3"
#define BLYNK_TEMPLATE_NAME "temperature and humidity"
#define BLYNK_AUTH_TOKEN "dWMY5LBFQ3jmW2HpZ6Qx6sLFFitaiXGC"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>

// Your WiFi credentials.
char ssid[] = "Gojju";
char pass[] = "123456789";

// Blynk Auth Token.
char auth[] = BLYNK_AUTH_TOKEN;

// Define the LED pin.
const int ledPin = 4;

// Create a Servo object.
Servo myServo;

// Define the Servo pin.
const int servoPin = 32;

void setup()
{
  // Debug console
  Serial.begin(115200);

  // Initialize Blynk
  Blynk.begin(auth, ssid, pass);

  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);

  // Attach the servo to the servo pin
  myServo.attach(servoPin);
}

// This function will be called every time the Blynk button is pressed.
BLYNK_WRITE(V0)
{
  int pinValue = param.asInt(); // Get the state of the button.

  // Set the LED state
  digitalWrite(ledPin, pinValue);
}

// This function will be called every time the Blynk slider value changes.
BLYNK_WRITE(V1)
{
  int sliderValue = param.asInt(); // Get the slider value (0-180).

  // Set the servo position
  myServo.write(sliderValue);
}

void loop()
{
  Blynk.run();
}