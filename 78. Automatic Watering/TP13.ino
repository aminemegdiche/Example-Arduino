const int L1 = 2; // broche 2 du micro-contrôleur se nomme maintenant : L1
const int plante = 3; // broche 3 du micro-contrôleur se nomme maintenant : plante
void setup() // fonction d'initialisation de la carte
{ // contenu de l'initialisation
pinMode(L1, OUTPUT); // L1 est une broche de sortie
pinMode(plante, INPUT); // plante est une broche d entree 
Serial.begin(9600);
}
void loop() // fonction principale, elle se repete (s execute) a l'infini 
{ // contenu du programme 
int humide = digitalRead(plante); // Lecture de l etat du capteur 
Serial.println(humide);
if(humide == HIGH) // Si le capteur est a l etat haut
{
digitalWrite(L1, HIGH); // Allumer L1 
}
else // Sinon
{
digitalWrite(L1, LOW); // Eteindre L1 
} 
delay(1000); // Attendre 1 seconde 
}
