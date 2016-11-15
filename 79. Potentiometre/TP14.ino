
unsigned long previousMillis;
unsigned long interval = 20;



void setup() {



        // Demarrer la communication serie a  57600 baud.
        Serial.begin(9600);

}

void loop() {

        // Verfier si au moins 20 millisecondes se sont ecoulees
        // depuis le dernier envoi.
        if ( millis() - previousMillis >= 20 ) {
                previousMillis = millis();

                // Lire la valeur du potentiometre.
                int valeur = analogRead(0);

                // Envoyer la valeur du potentiometre.
                Serial.print("A0 "); // en-tete (A0) suivi d'un espace
                Serial.print(valeur); // la valeur
                Serial.println(); // indicateur de fin de ligne

                /* //Le bloc precedent peut aussi etre ecrit ainsi:
                Serial.print("A0 "); // en-tete (A0) suivi d'un espace
                Serial.println(valeur); // la valeur suivi de l'indicateur de fin de ligne
                */

        }
}
