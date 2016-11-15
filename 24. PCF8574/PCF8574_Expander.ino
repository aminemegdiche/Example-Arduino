#include <Wire.h>    
#include "PCF8574.h" 

PCF8574 expander;

void setup() {

  expander.begin(0x20);
  expander.pinMode(3, OUTPUT);
  expander.pinMode(4, OUTPUT);
}

void loop() {

  expander.digitalWrite(4, HIGH); 
  delay(500);
  expander.digitalWrite(3, HIGH); 
  delay(500);
  expander.digitalWrite(4, LOW);  
  delay(500);
  expander.digitalWrite(3, LOW);  
  delay(500);
}
