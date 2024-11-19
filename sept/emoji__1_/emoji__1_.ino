#include <Adafruit_NeoPixel.h>
#define LED_PIN 2 // neopixel led pin
#define LED_COUNT 40 // number of leds connected
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int _arrow[] = {
  0, 1, 0, 1, 0, 1, 1, 1,
  0, 1, 0, 1, 0, 0, 1, 0,
  0, 1, 1, 1, 0, 0, 1, 0,
  0, 1, 0, 1, 0, 0, 1, 0,
  0, 1, 0, 1, 0, 1, 1, 1
};

int _arrow1[] = {
  0, 0, 0, 1, 1, 1, 0, 0,
  0, 0, 0, 0, 1, 0, 0, 0,
  0, 0, 0, 0, 1, 0, 0, 0,
  0, 0, 0, 0, 1, 0, 0, 0,
  0, 0, 0, 1, 1, 1, 0, 0
};
int _arrow2[] = {
  0, 0, 1, 0, 0, 1, 0, 1,
  0, 1, 0, 1, 0, 1, 1, 1,
  0, 1, 1, 1, 0, 1, 0, 1,
  0, 1, 0, 1, 0, 1, 0, 1,
  0, 1, 0, 1, 0, 1, 0, 1
};
int _arrow3[] = {
  1, 1, 1, 1, 1, 1, 0, 1,
  0, 1, 0, 1, 0, 0, 0, 0,
  0, 1, 0, 1, 1, 0, 0, 0,
  0, 1, 0, 1, 0, 0, 0, 0,
  0, 1, 0, 1, 1, 1, 0, 1
};
int _arrow4[] = {
  1, 1, 1, 1, 1, 1, 1, 1,
  1, 0, 1, 1, 1, 0, 1, 0,
  1, 1, 1, 1, 1, 0, 1, 0,
  1, 0, 1, 1, 1, 0, 1, 0,
  1, 1, 1, 1, 1, 0, 1, 0
};

int _arrow5[] = {
  0, 0, 1, 1, 1, 1, 0, 0,
  0, 1, 0, 1, 1, 0, 1, 0,
  0, 1, 1, 0, 0, 1, 1, 0,
  0, 1, 0, 1, 1, 0, 1, 0,
  0, 0, 1, 1, 1, 1, 0, 0
};

int _arrow6[] = {
  0, 0, 1, 1, 1, 1, 0, 0,
  0, 1, 0, 1, 1, 0, 1, 0,
  0, 1, 0, 1, 1, 0, 1, 0,
  0, 1, 1, 0, 0, 1, 1, 0,
  0, 0, 1, 1, 1, 1, 0, 0
};

int _arrow7[] = {
  0, 0, 1, 1, 1, 1, 0, 0,
  0, 1, 0, 1, 1, 0, 1, 0,
  0, 1, 1, 1, 1, 1, 1, 0,
  0, 1, 0, 0, 0, 0, 1, 0,
  0, 0, 1, 1, 1, 1, 0, 0
};

int _arrow8[] = {
  0, 0, 1, 1, 1, 1, 0, 0,
  0, 1, 0, 1, 0, 0, 1, 0,
  0, 1, 1, 0, 0, 1, 1, 0,
  0, 1, 0, 1, 1, 0, 1, 0,
  0, 0, 1, 1, 1, 1, 0, 0
};

int _arrow9[] = {
  0, 0, 1, 1, 1, 1, 0, 0,
  0, 1, 0, 1, 1, 0, 1, 0,
  0, 1, 0, 0, 0, 0, 1, 0,
  0, 1, 0, 0, 0, 0, 1, 0,
  0, 0, 1, 1, 1, 1, 0, 0
};

int _arrow10[] = {
  0, 0, 1, 1, 1, 1, 0, 0,
  0, 1, 1, 0, 0, 1, 1, 0,
  0, 1, 1, 1, 1, 1, 1, 0,
  0, 1, 0, 1, 1, 0, 1, 0,
  0, 0, 1, 1, 1, 1, 0, 0
};
int _arrow11[] = {
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

 

  // set button A as input pullup
  pinMode(23, INPUT_PULLUP);

  displayIcon(_arrow, sizeof(_arrow), strip.Color(0, 0, 150));
  delay(2000);
  displayIcon(_arrow1, sizeof(_arrow1), strip.Color(150, 0, 0));
   delay(2000);
   displayIcon(_arrow2, sizeof(_arrow2), strip.Color(0, 150, 0));
  delay(2000);
   displayIcon(_arrow3, sizeof(_arrow3), strip.Color(0, 150, 150));
  delay(2000);
   displayIcon(_arrow4, sizeof(_arrow4), strip.Color(150, 150, 150));
  delay(2000);
  // wait for user to press button A
  while (digitalRead(23)) {
    delay(10);
  }
   
}

void loop() {
  displayIcon(_arrow5, sizeof(_arrow5), strip.Color(10, 150, 10));
  delay(2000);
displayIcon(_arrow6, sizeof(_arrow6), strip.Color(150, 10, 0));
  delay(2000);
displayIcon(_arrow7, sizeof(_arrow7), strip.Color(10, 50, 150));
  delay(2000);
  displayIcon(_arrow8, sizeof(_arrow8), strip.Color(120, 150, 0));
  delay(2000);
  displayIcon(_arrow9, sizeof(_arrow9), strip.Color(0, 150, 150));
  delay(2000);
  displayIcon(_arrow10, sizeof(_arrow10), strip.Color(50, 50, 10));
  delay(2000);
  displayIcon(_arrow11, sizeof(_arrow11), strip.Color(10, 10, 150));
  delay(2000);
}
void displayIcon(int _array[], int len, uint32_t color) {
  strip.clear();
  for (int i = 0; i < len; i++) {
    if (_array[i])
      strip.setPixelColor(i, color);
  }
  strip.show();
}

 
