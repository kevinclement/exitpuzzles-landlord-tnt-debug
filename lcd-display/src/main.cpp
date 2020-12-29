#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C _lcd(0x27, 16, 2);

bool backlightOn = true;
void setup() {

  Serial.begin(9600);
  Serial.setTimeout(10);
  Serial.println("LCD Display...");

  _lcd.init();
  _lcd.backlight();
  _lcd.print("TEST Display!!!");
  _lcd.setCursor(0, 1);
  _lcd.cursor_on();
}

void loop() {
  if (Serial.available()) {
    String str = Serial.readString();
    backlightOn = !backlightOn;
    _lcd.setCursor(0, 1);
    if (backlightOn) {
      Serial.println("Backlight is ON");
      _lcd.print("Backlight is ON ");
      _lcd.backlight();
    } else {
      Serial.println("Backlight is OFF");
      _lcd.print("Backlight is OFF");
      _lcd.noBacklight();
    }
  }
}
