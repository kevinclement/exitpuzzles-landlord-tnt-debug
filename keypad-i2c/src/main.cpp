#include <Arduino.h>
#include "Keypad_I2C.h"
#include <Keypad.h>
#include "Wire.h"

// NOTE: this is not what is in the device.  At one point I was using
// a keypad with an i2c hooked up to it instead of directly to 8 pins
// it worked but I bent the board trying to fit it and busted it so
// I had to switch back to an 8-pin keypad.  See other keypad example.

// Keypad settings
#define ROWS 4
#define COLS 4

const uint8_t I2CADDR = 0x20;

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'#', '0', '*', 'D'}
};

// Configure the rows and columns based on the wiring
byte rowPins[ROWS] = {3, 2, 1, 0};  //connect to the row pinouts of the keypad
byte colPins[COLS] = {7, 6, 5, 4};  //connect to the column pinouts of the keypad

Keypad_I2C keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS, I2CADDR, PCF8574, &Wire);

void setup() {
  Serial.begin(9600);
  Serial.println("Keypad I2C test...");

  Wire.begin();
  keypad.begin();
}

void loop() {
  char key = keypad.getKey();

  // return if noop
  if (key == NO_KEY) {
    return;
  }

  Serial.println(key);
}