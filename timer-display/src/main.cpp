#include <Arduino.h>

void setup() {

  Serial.begin(9600);
  Serial.println("Timer Display...");

  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
  }

void loop() {
  // ## LIGHT SENSOR ##########
  
  // int average = 0;
  // for (int i=0; i < 10; i++) {
  //   average = average + analogRead(A1);
  // }
  // average = average/10;

  // Serial.print(" A1: ");
  // Serial.print(average);

  Serial.println("");
  
  delay(100);
}
