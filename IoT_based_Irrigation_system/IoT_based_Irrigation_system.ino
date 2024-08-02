#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#define sensor 33
#define relay 5

BlynkTimer timer;

// Enter your Auth token
char auth[] = "vgU_BoGijrWuQzIQwhp3hj43eYLqGm6k";

//Enter your WIFI SSID and password
char ssid[] = "Gojju";
char pass[] = "123456789";

void setup() {
  // Debug console
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
    pinMode(sensor, INPUT);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);

 
}

//Get the ultrasonic sensor values
void soilMoisture() {
  int value = analogRead(sensor);
  value = map(value, 0, 4095, 0, 100);
  value = (value - 100) * -1;
  Blynk.virtualWrite(V1, value);
  Serial.println(value);
 
}

//Get the button value
BLYNK_WRITE(V0) {
  bool Relay = param.asInt();
  if (Relay == 1) {
    digitalWrite(relay, LOW);
    
  } else {
    digitalWrite(relay, HIGH);
    
  }
}

void loop() {
  soilMoisture();
  Blynk.run();//Run the Blynk library

  delay(200);

}




// #define BLYNK_TEMPLATE_ID "TMPL3PhrusW1a"
// #define BLYNK_TEMPLATE_NAME "soil"
// #define BLYNK_AUTH_TOKEN "vgU_BoGijrWuQzIQwhp3hj43eYLqGm6k"
