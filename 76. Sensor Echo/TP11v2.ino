int trig = 12; //broche du Trigger
int echo = 11; //broche de l'Echo
long lecture_echo;
long cm;
void setup()
{
pinMode(trig, OUTPUT); //On défini le trigger comme étant une sortie
digitalWrite(trig, LOW);
pinMode(echo, INPUT); //L'echo est une entrée
Serial.begin(9600);
}
void loop()
{
digitalWrite(trig, HIGH); //On met le trigger à "1"
delayMicroseconds(10); //pendant 10µs
digitalWrite(trig, LOW); //puis on le remet à "0"
lecture_echo = pulseIn(echo, HIGH); //On lit le nombre de pulsations renvoyé
cm = lecture_echo / 58; //On divise par 58 pour avoir la distance en cm
Serial.print("Distance en cm : "); //On affiche la distance
Serial.println(cm);
delay(100);
}
