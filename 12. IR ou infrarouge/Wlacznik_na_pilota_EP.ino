int IRpin=7;
int LED = 10;
boolean stan=0;

void setup() {
  Serial.begin(9600);
  pinMode (IRpin, INPUT);
  pinMode (LED, OUTPUT);
}
void loop() {
   if (digitalRead(IRpin) == LOW)  {
  delay (20);
  stan=!stan;
  digitalWrite(LED, stan) ;
  while (digitalRead(IRpin)==LOW) ;
  delay(20);
  }
}
