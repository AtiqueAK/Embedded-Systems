#include <LiquidCrystal.h>

// Initialize the library with the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // RS, E, D4, D5, D6, D7

void setup() {
  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2);
  
  // Print a message to the LCD
  lcd.print("Hello, World!");
}

void loop() {
  // Main loop does nothing in this example
}
