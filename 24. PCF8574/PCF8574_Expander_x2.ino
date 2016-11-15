// http://starter-kit.nettigo.pl/2011/11/pcf8574-czyli-jak-latwo-zwiekszyc-liczbe-pinow-w-arduino/
// https://github.com/skywodd/pcf8574_arduino_library
// http://playground.arduino.cc/Main/PCF8574Class



#include <Wire.h>    
#include "PCF8574.h" 

PCF8574 expander1;
PCF8574 expander2;


void setup() {

    
  expander1.begin(0x20);
  expander2.begin(0x21);
  
  
  expander1.pinMode(4, OUTPUT);
  expander1.pinMode(3, OUTPUT);
  expander2.pinMode(5, OUTPUT);
  expander2.pinMode(2, OUTPUT);
}
 
void loop() {

  
  expander1.blink(4, 5, 200); 
  delay(1000);
  expander1.blink(3, 5, 200); 
  delay(1000);
  expander2.blink(5, 5, 200); 
  delay(1000);
  expander2.blink(2, 5, 200); 
  delay(1000);

 
  expander1.digitalWrite(4, HIGH); 
  delay(300);
  expander1.digitalWrite(3, HIGH); 
  delay(300);
  expander2.digitalWrite(5, HIGH); 
  delay(300);
  expander2.digitalWrite(2, HIGH); 
  delay(900);
  
   expander1.digitalWrite(4, LOW); 
   expander1.digitalWrite(3, LOW); 
   expander2.digitalWrite(5, LOW); 
   expander2.digitalWrite(2, LOW); 
   delay(500);
   expander1.digitalWrite(4, HIGH); 
   expander1.digitalWrite(3, HIGH); 
   expander2.digitalWrite(5, HIGH); 
   expander2.digitalWrite(2, HIGH); 
  delay (2000);
   expander1.digitalWrite(4, LOW); 
   expander1.digitalWrite(3, LOW); 
   expander2.digitalWrite(5, LOW); 
   expander2.digitalWrite(2, LOW);
 delay(700);
}
