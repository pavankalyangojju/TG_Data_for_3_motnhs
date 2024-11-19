#include <Adafruit_NeoPixel.h>
#define LED_PIN 2 // neopixel led pin
#define LED_COUNT 40 // number of leds connected

#define LMF 8 // left motor forward
#define LMR 9 // left motor reverse
#define RMF 10 // right motor forward
#define RMR 11 // right motor reverse

#define trig 15 // trig pin
#define echo 14 // echo pin

// PID parameters
float last_error = 0;
float integral = 0;

// PID factors
float Kp = 16.25;
float Ki = 0.05;
float Kd = 9;

// Parameters
int SILVER = 170;
int speed = 140;

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int _arrow[] = {
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 1, 1, 0, 0, 0,
  0, 0, 1, 1, 1, 1, 0, 0,
  0, 1, 0, 1, 1, 0, 1, 0,
  0, 0, 0, 1, 1, 0, 0, 0
};

int _smiley[] = {
  0, 1, 1, 0, 0, 1, 1, 0,
  0, 1, 1, 0, 0, 1, 1, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 1, 0, 0, 0, 0, 1, 0,
  0, 0, 1, 1, 1, 1, 0, 0
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  strip.begin();            // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();             // Turn OFF all pixels ASAP
  strip.setBrightness(15);  // Set BRIGHTNESS to about 1/5 (max = 255)

  delay(500);

  analogReadResolution(12);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(LMF, OUTPUT);
  pinMode(LMR, OUTPUT);
  pinMode(RMF, OUTPUT);
  pinMode(RMR, OUTPUT);

  analogWrite(LMF, 0);
  analogWrite(LMR, 0);
  analogWrite(RMF, 0);
  analogWrite(RMR, 0);

  // set button A as input pullup
  pinMode(23, INPUT_PULLUP);

  displayIcon(_smiley, sizeof(_smiley), strip.Color(127, 127, 127));

  // wait for user to press button A
  while (digitalRead(23)) {
    delay(10);
  }
  displayIcon(_arrow, sizeof(_arrow), strip.Color(0, 127, 0));
  delay(500);
}

void loop() {
  int L = analogRead(A2);
  int R = analogRead(A3);
  int err = L - R;

  int errDisplay = err;
  if (errDisplay > 40) errDisplay = 40;
  if (errDisplay < -40) errDisplay = -40;
  int led_pos = map(errDisplay, -40, 40, 0, 7);
  Serial.println(led_pos);
  for (int i=0;i<8;i++){
    if (led_pos == i ){
      strip.setPixelColor(i, strip.Color(255, 0, 0));
    }else{
      strip.setPixelColor(i, strip.Color(0, 0, 0));
    }
  }
  strip.show();

  //PID calculations
  float pFix = err * Kp;
  integral = integral + err;
  if (integral > 400) integral = 400;
  if (integral < -400) integral = -400;
  float iFix = integral * Ki;
  float dFix = err - last_error * Kd;
  last_error = err;
  float drive = pFix + iFix + dFix;

  MoveMotor(speed + drive, speed - drive, true);

  if (L > SILVER and R > SILVER) {
    delay(10);
    if (L > SILVER and R > SILVER) {
      MoveMotor(0, 0, true);
      delay(500);
      MoveMotor(200, -200, true);
      delay(800);
      MoveMotor(0, 0, true);
      delay(200);
    }
  }
}


void MoveMotor(int LM, int RM, bool brake) {
  int stoppedfunction = 0;
  if (LM > 255) LM = 255;
  if (LM < -255) LM = -255;
  if (RM > 255) RM = 255;
  if (RM < -255) RM = -255;
  if (brake) stoppedfunction = 255;

  if (LM > 0) {
    analogWrite(LMF, LM);
    analogWrite(LMR, 0);
  } else if (LM < 0) {
    analogWrite(LMF, 0);
    analogWrite(LMR, -LM);
  } else {
    analogWrite(LMF, stoppedfunction);
    analogWrite(LMR, stoppedfunction);
  }

  if (RM > 0) {
    analogWrite(RMF, RM);
    analogWrite(RMR, 0);
  } else if (RM < 0) {
    analogWrite(RMF, 0);
    analogWrite(RMR, -RM);
  } else {
    analogWrite(RMF, stoppedfunction);
    analogWrite(RMR, stoppedfunction);
  }
}

void displayIcon(int _array[], int len, uint32_t color) {
  strip.clear();
  for (int i = 0; i < len; i++) {
    if (_array[i])
      strip.setPixelColor(i, color);
  }
  strip.show();
}

int getDistance() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  delayMicroseconds(1);
  int duration = pulseIn(echo, HIGH);
  int distance = duration * 0.0343 / 2;
  return distance;
}
