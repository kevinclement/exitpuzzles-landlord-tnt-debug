#include <Arduino.h>
#include "LedControl.h"

// Display Settings
#define DSP_BRIGHTNESS 1  // brightness level (0 is min, 15 is max) 
#define DSP_DIN        51  // pin 4 to DIN
#define DSP_CLK        52  // pin 3 to Clock
#define DSP_LOAD       53  // pin 2 to Load

LedControl lc = LedControl(DSP_DIN, DSP_CLK, DSP_LOAD, 1);

void setDisplay(int hours, int minutes, int seconds, int milliseconds);

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(10);
  Serial.println("Timer Display...");  

  lc.shutdown(0, false);               // Enable display
  lc.setIntensity(0, DSP_BRIGHTNESS);  // Set brightness level (0 is min, 15 is max)
  lc.clearDisplay(0);                  // Clear display register
}

void loop() {
  setDisplay(12,34,56,78);
}

void setDisplay(int hours, int minutes, int seconds, int milliseconds) {
  int returnVal = 0;
  int decimal[8] = {0};

  // pull out the individual numbers for the display
  decimal[7] = hours / 10;
  decimal[6] = hours % 10;
  decimal[5] = minutes / 10;
  decimal[4] = minutes % 10;
  decimal[3] = seconds / 10;
  decimal[2] = seconds % 10;
  decimal[1] = milliseconds / 10;
  decimal[0] = milliseconds % 10;  
  
  byte highestNonZero = 0;
  
  // now set all the digits using library
  for (int i=8; i>0; i--) {
    int pos = i - 1;
    bool showDot = (milliseconds != -1 && pos == 2) || (milliseconds == -1 && pos == 4);
    int digit = decimal[pos];

    // if current column is higher than highest, it becomes new highest
    if (digit != 0 && pos > highestNonZero) {
      highestNonZero = pos; 
    }

    // non-zero we can just display, no problem
    if (digit != 0) {
      lc.setDigit(0, pos, digit, showDot);
    }
    else {
      // special case winning condition, ms will be -1, we want to clear out last two digits
      if (milliseconds == -1 && (pos == 1 || pos == 0)) {
        lc.setChar(0, pos, ' ', false);
      }
      else {
        // if number is 0 and column is less than highest then we can display it
        if (pos < highestNonZero) {
          lc.setDigit(0, pos, digit, showDot);
        }
        else {
          // Otherwise, clear it out.
          // NOTE: set false to showDot if you want to keep dot whole time
          lc.setChar(0, pos, ' ', false);
        }
      }
    }
  }
}
