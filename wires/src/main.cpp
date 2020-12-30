#include <Arduino.h>

void setup() {

  Serial.begin(9600);
  Serial.println("Wires Test...");

  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
}

void loop() {
  // ## WIRES ##########
  // left side (start) of wire always be the one that is ground
  // right side (end) of wire is one being monitored
  // 
  // 1->4 : A0 (100k resistor - 742 avg reading)
  // A->3 : A2 (10k resistor - 228 avg reading)
  // B->D : A1 (4.7k resistor - 125 avg reading)
  // C->2 : A3 (no resistor - 15 avg reading)

  Serial.print("A3: ");
  Serial.println(analogRead(A3));
  
  delay(100);
}
