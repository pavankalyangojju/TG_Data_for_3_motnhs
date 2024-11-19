#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h> // Include the Servo library

// Set the LCD address to 0x27 for a 16x2 display
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Create a Servo object
Servo myServo;

int speakerPin = 8; // Buzzer is connected to Pin 8 of the board.
int length = 149; // the number of notes 
char notes[] = "cdeeeeeeeeedef eeedddbdc ccgggggggggaf fffffeddf eedeedeggaff eeeeeddbdc cdeeeedf efgggfedfe feeeddbdc ccggggeggggga fffffedfe egc bab aga ccddeedef "; // a space represents a rest
//char notes[] = "ccddeeeeeeedef eeedddb-dc cggggggggf#ag fffeeedfe eeeeedgggff eeedddb-dc cdeeeedef efgggfedfe eedddb-dc ggggggggggf#ag fffeeedfe egc+ bab aga ccddeedef "; // a space represents a rest
int beats[] = { 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1,
                2, 1, 1, 2, 1, 1, 1, 1, 1, 1,
                2, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1,
                2, 1, 1, 2, 1, 1, 1, 1, 1, 1,
                2, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1,
                2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1,
                1, 1, 1, 1, 2, 2, 2, 1, 1,
                1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1,
                2, 2, 1, 1, 1, 1, 1, 1, 1, 1,
                1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1,
                2, 1, 1, 2, 1, 1, 1, 1, 1, 1,
                1, 1, 4, 1, 1, 1, 4, 1, 1, 1, 4, 1,
                1, 1, 1, 1, 1, 1, 1, 1, 4, 1 };

int tempo = 200; //set tempo

// Flag to check if actions have been performed
bool performed = false;

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 956, 851, 758, 716, 638, 568, 1014, 478 };

  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

void setup() {
  // Initialize the speaker pin
  pinMode(speakerPin, OUTPUT);

  // Initialize the LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Happy");
  lcd.setCursor(0, 1);
  lcd.print("Independence Day");

  // Initialize the servo
  myServo.attach(9); // Attach the servo to pin 9
}

void loop() {
  if (!performed) {
    // Move servo to 90 degrees
    myServo.write(90);
    delay(500); // Brief delay to ensure servo reaches 90 degrees

    // Play the melody
    for (int i = 0; i < length; i++) { // For the length of the tune array
      if (notes[i] == ' ') { // Take space as rest
        delay(beats[i] * tempo); // Rest
      } else {
        playNote(notes[i], beats[i] * tempo); // Play the corresponding note for the corresponding beat
      }

      // Pause between notes
      delay(tempo / 2);
    }

    // Move servo to 0 degrees
    myServo.write(0);
    delay(500); // Brief delay to ensure servo reaches 0 degrees

    // Turn off the buzzer (if needed, you could disable the speaker pin)
    digitalWrite(speakerPin, LOW);

    // Set the flag to true to stop further actions
    performed = true;

    // Optional: Infinite loop to halt further code execution
    while (true) {
      // Do nothing, or add any additional actions here if needed
    }
  }
}
