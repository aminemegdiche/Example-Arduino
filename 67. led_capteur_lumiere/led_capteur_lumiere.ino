/* Photocell simple testing sketch.
Connect one end of the photocell to 5V, the other end to Analog 0.
 Then connect one end of a 10K resistor from Analog 0 to ground
For more information see http://learn.adafruit.com/photocells */
int led=6;
int photocellPin = 0; // the cell and 10K pulldown are connected to a0
int photocellReading; // the analog reading from the analog resistor divider

void setup(void) {
  // We'll send debugging information via the Serial monitor
  Serial.begin(9600);
   pinMode(led, OUTPUT); 
}

void loop(void) {
   
  photocellReading = analogRead(photocellPin);
  Serial.print("Analog reading = ");
  Serial.print(photocellReading); // the raw analog reading
  // We'll have a few threshholds, qualitatively determined
  if (photocellReading < 10) {
    Serial.println(" - Noir");
  } else if (photocellReading < 200) {
    Serial.println(" - Sombre");
   digitalWrite(led,HIGH);
  } else if (photocellReading < 500) {
    Serial.println(" - Lumiere");
      digitalWrite(led,LOW);
  } else if (photocellReading < 800) {
   digitalWrite(led,LOW);
    Serial.println(" - Lumineux");
  } else {
    Serial.println(" - Tres lumineux");
    digitalWrite(led,LOW);
  }
  delay(1000);
}
