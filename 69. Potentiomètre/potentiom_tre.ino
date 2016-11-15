int pot_pin=0;
int pwm_pin=0;
unsigned long val_pot = 0; // sensor connected to pin an0
int  val_pot_256 = 0;
void setup() // icii on place es initiaisations, elles ne sont effectués qu'une seule fois
{
  pinMode (pot_pin, INPUT);
  pinMode (pwm_pin, OUTPUT);
}
void loop () // Ici le programme tourne en boucle
{
  val_pot=analogRead(pot_pin); //Read the value from ADC on 10 bits 1024 values
  val_pot_256 = val_pot / 18; //adapt to 256 values
  Serial.println(val_pot_256);
  analogWrite(pwm_pin, val_pot_256); // apply PWM
}

