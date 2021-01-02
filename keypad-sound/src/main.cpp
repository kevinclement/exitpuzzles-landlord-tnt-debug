#include <Arduino.h>
#include <Keypad.h>

// Keypad settings
#define ROWS 4
#define COLS 4

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Configure the rows and columns based on the wiring
// wires by pin: 
//   0: UNUSED
//   1: COL1
//   2: COL2
//   3: COL3
//   4: COL4
//   5: ROW1
//   6: ROW2
//   7: ROW3
//   8: ROW4
//   9: UNUSED
byte rowPins[ROWS] = {30, 32, 34, 36};  //connect to the row pinouts of the keypad
byte colPins[COLS] = {22, 24, 26, 28};  //connect to the column pinouts of the keypad

Keypad keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Speaker pin
#define BUZZ A10

void beep(int frequencyInHertz, long timeInMilliseconds)
{
  int x;   
  long delayAmount = (long)(1000000/frequencyInHertz); 
  long loopTime = (long)((timeInMilliseconds*1000)/(delayAmount*2)); 
  for (x=0;x<loopTime;x++)   
  {   
      digitalWrite(BUZZ,HIGH); 
      delayMicroseconds(delayAmount); 
      digitalWrite(BUZZ,LOW); 
      delayMicroseconds(delayAmount); 
  }
}

// stored values to allow tuning
int freq = 100;
long time = 70;

// A good timing for feedback
#define SET_TIME 30

void setup() {
  Serial.begin(9600);
  Serial.println("Keypad test...");

  pinMode(BUZZ, OUTPUT);
  digitalWrite(BUZZ, LOW); //Buzzer Off 
}

// print out the timing so it can be reused if we find a good one
void printTiming() {
  Serial.print("freq: ");
  Serial.print(freq);
  Serial.print(" time: ");
  Serial.print(time);
  Serial.println();
}

void loop() {
  char key = keypad.getKey();

  // return if noop
  if (key == NO_KEY) {
    return;
  }

  // turning this off since its not really needed for this demo
  // Serial.println(key);

  // 1 - random in a set range
  if (key == '1') {
    beep(350 + random(100, 400), SET_TIME);
  } else if (key == '2') {
    beep(200,SET_TIME);
  } else if (key == '3') {
    beep(300,SET_TIME);
  } else if (key == '4') {
    beep(400,SET_TIME);
  } else if (key == '5') {
    beep(500,SET_TIME);
  } else if (SET_TIME == '6') {
    beep(600,SET_TIME);
  } else if (key == '7') {
    beep(700,SET_TIME);
  } else if (key == '8') {
    beep(800,SET_TIME);
  
  // Adjustable sounds
  // A: + freq
  // B: - freq
  // C: + time
  // D: - time
  } else if (key == '0') {
    beep(freq,time);
  } else if (key == 'A') {
    freq += 100;
  } else if (key == 'B') {
    if (freq > 100) {
      freq -= 100;  
    }
  } else if (key == 'C') {
    time += 10;
  } else if (key == 'D') {
    if (time > 10) {
      time -= 10;  
    }
  }
  
  if (key == 'A' || key == 'B' || key == 'C' || key == 'D') {
    printTiming();
  }
}