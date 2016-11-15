#include <IRremote.h>

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;
boolean stan=0;
int moc;

void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  irrecv.enableIRIn(); // Start the receiver
}



void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, DEC);
    irrecv.resume(); // Receive the next value
        
        switch (results.value) {
         case 19613:
            Serial.println("Czerwony");
            stan=!stan;
            digitalWrite(2, stan);
            break;
 
         case 21661:
            Serial.println("photo");
            analogWrite(3, 255);
            break;
             case 11419:
              Serial.println("up");
              if (moc<231)
              moc=moc+25;
              analogWrite(3, moc);
              break;
             case 27803:
              Serial.println("down");
              if (moc>24)
              moc=moc-25;
              analogWrite(3, moc);
              break;
 
 
         case 1468:
            Serial.println("display");
            analogWrite(4, 255);
            break;
          case 3644:
            Serial.println("zero");
            analogWrite(4, 0);
            break;   
        }
    
   delay(350);
  }
}
