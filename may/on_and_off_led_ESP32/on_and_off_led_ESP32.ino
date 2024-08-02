#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Enter your Auth token
char auth[] = "Jw4CB1cMlXDMg4Fb645mm-4YJKPsWYnJ";

// Enter your WiFi SSID and password
char ssid[] = "Gojju";
char pass[] = "123456789";

void setup() {
  // Debug console
  Serial.begin(9600);
  
  // Connect to Blynk
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  Blynk.run();
}
