//COPYRIGHT © Amin Magdich
//ingénieur en informatique multimédia web
//Tunisie Logiciels informatiques

int sensorPin = A0;    // select the input pin for the LDR
int led_red = 6;      // select the pin for the red LED
int led_green = 7;   // select the pin for the green LED
int buzzer = 5;   // select the pin for the buzzer
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  // declare the Pins as an OUTPUT:
  Serial.begin(9600);
  pinMode(led_red, OUTPUT);  
  pinMode(led_green, OUTPUT);  
  pinMode(buzzer, OUTPUT); 
  digitalWrite(buzzer, HIGH);  // buzzer is OFF  , NOTE THAT LOW TERMINAL OF BUZZER IS CONNECTED TO ARDUINO
 
  delay(1000);
  sensorValue = analogRead(sensorPin);  // make the first value of the sensor default
  delay(1000);
   digitalWrite(led_green, HIGH);  // green led is ON
   digitalWrite(led_red, LOW);  // green led is ON
Serial.println(sensorValue);
}
void loop() {
Serial.println(analogRead(sensorPin));
  if  ( analogRead(sensorPin) > sensorValue+5)
  {
        digitalWrite(led_green, LOW); //green led is OFF
        digitalWrite(led_red, HIGH) ;  // red led is ON
        digitalWrite(buzzer, LOW); // buzzer is ON
        delay(10000);
   
  }
  else 
  {
   digitalWrite(led_green, HIGH); //green led is OFF
        digitalWrite(led_red, LOW) ;  // red led is ON
        digitalWrite(buzzer, HIGH); // buzzer is ON
  
  }
}
