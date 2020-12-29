#include <Arduino.h>

#define DOORBTN 8
#define DOOR_OPEN LOW
#define DOOR_CLOSED HIGH

bool doorOpen = false;
void setup() {

  Serial.begin(9600);
  Serial.setTimeout(10);
  Serial.println("Door Ajar Button...");

  pinMode(DOORBTN, INPUT_PULLUP);
}

void loop() {
  int doorBtnReading = digitalRead(DOORBTN);
  
  if (doorBtnReading == DOOR_OPEN && !doorOpen) {
    Serial.println("Door OPENED!");
    doorOpen = true;
  } 

  if (doorBtnReading == DOOR_CLOSED && doorOpen) {
    Serial.println("Resetting door to closed state.");
    doorOpen = false;
  }

  delay(100);
}
