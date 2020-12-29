#include <Arduino.h>

#define LS_PIN A11
#define LS_THRESHOLD 750

bool sawLight = false;
bool showLightValues = false;  // switch to turn on dump of light values

void setup() {

  Serial.begin(9600);
  Serial.setTimeout(10);
  Serial.println("Light Sensor...");

  pinMode(LS_PIN, INPUT_PULLUP);
}

void loop() { 

  bool light = analogRead(LS_PIN) < LS_THRESHOLD;
  if (light && !sawLight) {
    sawLight = true;
    Serial.println("I SAW LIGHT!!!!");
  }

  if (Serial.available()) {
    String str = Serial.readString();
    showLightValues = !showLightValues;
    
    Serial.print("Show Light: ");
    if (showLightValues) {
      Serial.print("ON");
    } else {
      Serial.print("OFF");
    }
    Serial.println();
  }

  if (showLightValues) {
    Serial.print("light: ");
    Serial.println(analogRead(LS_PIN));
  }
  
  delay(100);
}
