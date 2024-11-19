#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Define the motor pins
 
#define IN1 19
#define IN2 17
#define IN3 15
#define IN4 16
 
BlynkTimer timer;
// Variables for the Blynk widget values
bool forward = 0;
bool backward = 0;
bool left = 0;
bool right = 0;
 

char auth[] = "NhYzWxESHdlRmWq2Y_8xSyyGFuAnuupe";

//Enter your WIFI SSID and password
char ssid[] = "Jishan’s iPhone";
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

 //forward
BLYNK_WRITE(V0) {
  forward = param[0].asInt();
}
 //back
BLYNK_WRITE(V1) {
 backward = param[0].asInt();
}
 //left
BLYNK_WRITE(V2) {
 left = param.asInt();
}
 //right
BLYNK_WRITE(V3) {
 right = param.asInt();
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
    Serial.println("carstop");
  }
}
void loop() {
  Blynk.run();// Run the blynk function
  smartcar();// Call the main function
  timer.run();
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
