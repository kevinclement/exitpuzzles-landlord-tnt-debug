#include <Arduino.h>

#define T1_PIN 6
#define T2_PIN 2
#define T3_PIN 5
#define T4_PIN 4
#define T5_PIN 3

void setup() {

  Serial.begin(9600);
  Serial.println("Toggles...");

  pinMode(T1_PIN, INPUT_PULLUP);
  pinMode(T2_PIN, INPUT_PULLUP);
  pinMode(T3_PIN, INPUT_PULLUP);
  pinMode(T4_PIN, INPUT_PULLUP);
  pinMode(T5_PIN, INPUT_PULLUP);
  
  }

void loop() {
  // ## TOGGLES ##########
  bool t1 = !digitalRead(T1_PIN);
  bool t2 = !digitalRead(T2_PIN);
  bool t3 = !digitalRead(T3_PIN);
  bool t4 = !digitalRead(T4_PIN);
  bool t5 = !digitalRead(T5_PIN);

  Serial.print("1: ");
  Serial.print(t1);

  Serial.print(" 2: ");
  Serial.print(t2);

  Serial.print(" 3: ");
  Serial.print(t3);

  Serial.print(" 4: ");
  Serial.print(t4);

  Serial.print(" 5: ");
  Serial.print(t5);  

  Serial.println("");
  
  delay(100);
}
