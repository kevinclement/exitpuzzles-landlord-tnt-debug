#include <Arduino.h>

#define BUZZ A10

void beep(unsigned char speakerPin, int frequencyInHertz, long timeInMilliseconds)
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

void uhoh() {
  beep(BUZZ,415,100);
  delay(80);
  beep(BUZZ,279,100);
  delay(80);
}

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
  Serial.println("Speaker PIZO...");

  pinMode(BUZZ, OUTPUT);
  digitalWrite(BUZZ, LOW); //Buzzer Off 
}

void loop() {
  // Serial.println("");  
  if (isSerial()) {
    Serial.println("Playing uhoh...");
    uhoh();
  }
}
