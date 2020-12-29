#include <Arduino.h>

#define LOCK_PIN A8
#define RELAY_ON    0
#define RELAY_OFF   1

void setup() {

  Serial.begin(9600);
  Serial.setTimeout(10);
  Serial.println("Lock...");

  digitalWrite(LOCK_PIN, RELAY_OFF);
  pinMode(LOCK_PIN, OUTPUT);
}

bool lockOn = false;

void loop() {

  if (Serial.available()) {
    String str = Serial.readString();

    lockOn = !lockOn;
    // Serial.print("got serial available '");
    // Serial.print(str);
    // Serial.print("'");
    // Serial.println();
    
    Serial.print("Lock: ");
    if (lockOn) {
      Serial.print("ON");
    } else {
      Serial.print("OFF");
    }
    Serial.println();
  }
  
  digitalWrite(LOCK_PIN, lockOn ? RELAY_ON : RELAY_OFF);

  delay(100);
}
