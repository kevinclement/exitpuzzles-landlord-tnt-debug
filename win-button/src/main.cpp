#include <Arduino.h>

#define WINBTN 9

bool won = false;
void setup() {

  Serial.begin(9600);
  Serial.setTimeout(10);
  Serial.println("Win Button...");

  pinMode(WINBTN, INPUT_PULLUP); 
}

void loop() {
  int winBtnReading = digitalRead(WINBTN);
  
  if (winBtnReading == HIGH && !won) {
    Serial.println("Win button pressed!!! you won!");
    won = true;
  }

  // reset for the debug system so I can test multiple times without a reset
  if (winBtnReading == LOW && won) {
    Serial.println("Reset win button.");
    won = false;
  }

  delay(100);
}
