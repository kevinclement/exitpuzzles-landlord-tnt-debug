#include <Arduino.h>

#define SHOOTER_PIN A9
#define RELAY_ON    0
#define RELAY_OFF   1

bool isSerial() {
  bool available = false;

  if (Serial.available()) {
    String str = Serial.readString();
    available = true;
  }

  return available;
}

void setup() {

  Serial.begin(9600);
  Serial.setTimeout(10);
  Serial.println("Key Shooter...");

  digitalWrite(SHOOTER_PIN, RELAY_OFF);
  pinMode(SHOOTER_PIN, OUTPUT);
}

bool shooterOn = false;
void loop() {

  if (isSerial()) {
    shooterOn = !shooterOn;
    Serial.print("Shooter: ");
    if (shooterOn) {
      Serial.print("ON");
    } else {
      Serial.print("OFF");
    }
    Serial.println();
  }
  
  digitalWrite(SHOOTER_PIN, shooterOn ? RELAY_ON : RELAY_OFF);
  delay(100);
}
