#include <Arduino.h>

// NOTE: this is not what is in the device.  I was playing with
// trying to find a solution for flyback on the solenoid and was debating
// on switching to mosfet and so used this to test the circuit on the 
// breadboard.

#define CONTROL_PIN 43
#define RELAY_ON    1
#define RELAY_OFF   0

void setup() {

  Serial.begin(9600);
  Serial.setTimeout(10);
  Serial.println("Mosfet Keyshooter Test...");

  pinMode(CONTROL_PIN, OUTPUT);
}

bool shooterOn = false;
void loop() {

  if (Serial.available()) {
    String str = Serial.readString();

    shooterOn = !shooterOn;
    Serial.print("Shooter: ");
    if (shooterOn) {
      Serial.print("ON");
    } else {
      Serial.print("OFF");
    }
    Serial.println();
  }
  
  digitalWrite(CONTROL_PIN, shooterOn ? RELAY_ON : RELAY_OFF);
  delay(100);
}
