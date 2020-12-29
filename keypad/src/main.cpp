#include <Arduino.h>
#include <Keypad.h>

// Keypad settings
#define ROWS 4
#define COLS 4

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Configure the rows and columns based on the wiring
// wires by pin: 
//   0: UNUSED
//   1: COL1
//   2: COL2
//   3: COL3
//   4: COL4
//   5: ROW1
//   6: ROW2
//   7: ROW3
//   8: ROW4
//   9: UNUSED
byte rowPins[ROWS] = {30, 32, 34, 36};  //connect to the row pinouts of the keypad
byte colPins[COLS] = {22, 24, 26, 28};  //connect to the column pinouts of the keypad

Keypad keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  Serial.println("Keypad test...");
}

void loop() {
  char key = keypad.getKey();

  // return if noop
  if (key == NO_KEY) {
    return;
  }

  Serial.println(key);
}