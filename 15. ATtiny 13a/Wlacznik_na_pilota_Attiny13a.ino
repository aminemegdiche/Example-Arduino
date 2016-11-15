int IRpin=3;
int LED = 4;
boolean stan=0;

void setup() {
  pinMode (IRpin, INPUT);
  pinMode (LED, OUTPUT);
}
void loop() {
   if (digitalRead(IRpin) == LOW)  {
  delay (100);
  stan=!stan;
  digitalWrite(LED, stan) ;
  while (digitalRead(IRpin)==LOW) ;
  delay(600);
  }
}
