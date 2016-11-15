int sound = 0;
int pinsound=2;

void setup() {
  Serial.begin(9600);
}

void loop() {
  //sound= analogRead(pinsound); //si vous avez brancher sur un pin analogique 
  sound = digitalRead(pinsound);
  if (sound == 1) {	                   // If loud sound
    Serial.println("Sound detected!");
    delay(100);				   // Wait 1/10 second
    
}					   // Repeat
}
