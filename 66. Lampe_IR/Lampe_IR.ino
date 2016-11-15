#include <IRremote.h>
const int RELAY_1 =2;
const int RELAY_OFF=0;
const int RELAY_ON=1;
const int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;
void setup()
{
 // Set pin as output.
  pinMode(RELAY_1, OUTPUT);
 
  // Initialize relay one as off so that on reset it would be off by default
  digitalWrite(RELAY_1, RELAY_OFF);
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  
 
}

void loop ()
 {
   if (irrecv.decode(&results)) {
  //   digitalWrite(RELAY_1, RELAY_ON);
     translateIR(); 
    irrecv.resume();
}
}


void translateIR()
{
 
  Serial.println(results.value,DEC);
 

    switch (results.value) {   // results.value:  it’s the IR receiver reading. 
         case 3810010651:         //  case 1:
       {  digitalWrite(RELAY_1,RELAY_ON);
          Serial.println("ON");
          break;
       }
          // case 12209C7B :      //  FFA25D : it’s the code of button 1
     case 5316027:
     {
      digitalWrite(RELAY_1, RELAY_OFF);
       Serial.println("OFF");
        break;
     }
        
           //  case 305D6FC :      //  FFA25D : it’s the code of button 1
       case 4105841032:
    {   digitalWrite(RELAY_1, RELAY_ON);
        break;
    }    
           case 403429887:
    {  digitalWrite(RELAY_1, RELAY_OFF);
       Serial.println("OFF");
        break;
    }
}

}

