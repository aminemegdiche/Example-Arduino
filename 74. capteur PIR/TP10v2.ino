int PIR;

void setup() {
    // Configuration de la broche 5 en tant qu'entrée numérique
    pinMode(5,INPUT); 
    pinMode(4,OUTPUT);
    Serial.begin(9600);
}

void loop() {
   // lire l'état du PIR
    PIR = digitalRead(5);
    digitalWrite(4,PIR);
    Serial.println(PIR);
    
}
