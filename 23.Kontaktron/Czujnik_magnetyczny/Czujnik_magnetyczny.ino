int drzwi = 2;  
int alarm = 5; 
int stan;

void setup() {
pinMode (drzwi, INPUT);
pinMode (alarm, OUTPUT);
}

void loop() {

  stan = digitalRead(drzwi);            
 
 if (stan ==HIGH)  {
   tone (alarm, 2500, 150);
    delay(500);
 }}
 
