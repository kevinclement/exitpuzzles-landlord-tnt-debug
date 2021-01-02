#include <Arduino.h>

void setup() {

  Serial.begin(9600);
  Serial.println("Wires Test...");

  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
}

const char * determineSource(int sig) {
  const char * src;

  if (sig > 0 && sig < 75) {
    src = "C";
  } else if (sig > 100 && sig < 175) {
    src = "B";
  } else if (sig > 200 && sig < 275) {
    src = "A";
  } else if (sig > 700 && sig < 775) {
    src = "1";
  } else if (sig > 800) {
    src = "UPLG";
  } else {
    src = "UKWN";
  }

  return src;
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

  // Source controls the signal strength
  //  1: 700-775
  //  A: 200-275
  //  B: 100-175
  //  C: 0-75

  // ## Example 2 Destination
  // #######################
  // 1->2: 745
  // A->2: 235
  // B->2: 135
  // C->2: 20 * PASSING

  bool printRaw = false;
  if (printRaw) {
    Serial.print("   2: ");
    Serial.print(analogRead(A3));
    Serial.print("   3: ");
    Serial.print(analogRead(A2));
    Serial.print("   4: ");
    Serial.print(analogRead(A0));
    Serial.print("   D: ");
    Serial.print(analogRead(A1));
  } else {
    Serial.print("   2: ");
    Serial.print(determineSource(analogRead(A3)));
    Serial.print("   3: ");
    Serial.print(determineSource(analogRead(A2)));
    Serial.print("   4: ");
    Serial.print(determineSource(analogRead(A0)));
    Serial.print("   D: ");
    Serial.print(determineSource(analogRead(A1)));
  }
  
  Serial.println();
  
  delay(100);
}
