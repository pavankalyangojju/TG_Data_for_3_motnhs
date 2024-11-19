#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 or 0x3F for a 16x2 or 20x4 LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Initialize the LCD
  lcd.begin();
  // Turn on the backlight
  lcd.backlight();
  
  // Print "Hello," on the first line
  lcd.setCursor(0, 0);
  lcd.print("Hello,");
  
  // Print "World!" on the second line
  lcd.setCursor(0, 1);  // Move cursor to the first column of the second line
  lcd.print("World!");
}

void loop() {
  // Nothing to do here
}
