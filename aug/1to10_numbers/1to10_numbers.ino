#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 or 0x3F for a 16x2 or 20x4 LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Initialize the LCD
  lcd.begin();
  // Turn on the backlight
  lcd.backlight();
}

void loop() {
  for (int i = 1; i <= 10; i++) {
    // Clear the LCD screen
    lcd.clear();
    
    // Set the cursor to the first column, first row
    lcd.setCursor(0, 0);
    
    // Print the current number on the LCD
    lcd.print("Number: ");
    lcd.print(i);
    
    // Wait for 1 second
    delay(1000);
  }
}
