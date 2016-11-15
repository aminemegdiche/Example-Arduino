/*
Détecteur de présence - capteur PIR + LED
Arduino IDE 1.0.3
*/

#define PIR 2
#define LED 8
#define LEDB 9
int val = 0;            // état du capteur
int pirState = LOW;     // précédent état du capteur

void setup()
{
  pinMode(PIR, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(LEDB, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.println(digitalRead(PIR));
  val = digitalRead(PIR);
  
  if(val == HIGH)            // si on détecte un mouvement
  {
    if(pirState == LOW)      // on regarde s'il y a eu changement d'état
    {
      //delay(10000);               // on fait clignoter la led
      digitalWrite(LED, HIGH);
      digitalWrite(LEDB, LOW);
      delay(5000);  
      pirState = HIGH;       // on stocke l'état
    }
  }
  else                       // si on ne détecte pas de mouvement
  {
    if(pirState == HIGH)
    {
      digitalWrite(LED, LOW);
      digitalWrite(LEDB, HIGH);
      pirState = LOW;
    }
  }
}
