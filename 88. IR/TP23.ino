/* 
  Emission infrarouge 
*/

#include <IRremote.h>

IRsend emission_ir; // crée une instance

void setup() 
{ 
}

void loop() 
{ 
   emission_ir.sendNEC(0xff38c7, 32); // code télécommande CGV on/off 
   delay(10000); 
}
