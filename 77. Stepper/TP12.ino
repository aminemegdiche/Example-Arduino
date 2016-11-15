#include <Stepper.h>

const int stepsPerRevolution = 2048; //2048 pour la 28BYJ-48 = 1 tour
int Nbre_tour ;
// initialiser la bibliotheque stepper sur les broches D8 a D11:
Stepper myStepper(stepsPerRevolution, 8,10,9,11); //Attribution des broches

void setup() {
  // reglage de la vitesse (28BYJ-48):
  myStepper.setSpeed(12); // de 4 a 14 vitesse de rotation
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  
   Nbre_tour = 10; //Faire 10 tours dans un sens:
   Serial.println("clockwise");
  myStepper.step(stepsPerRevolution*Nbre_tour);
  delay(1000);


  Nbre_tour = 5; //Faire 5 tours dans l autre sens:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution*Nbre_tour);
  delay(1000); 
}
