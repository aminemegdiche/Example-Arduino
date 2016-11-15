
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define BACKLIGHT_PIN 3
LiquidCrystal_I2C	lcd(0x27,2,1,0,4,5,6,7);

void setup()
{
  Serial.begin(9600);
     lcd.begin(16, 2);
   lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
   lcd.setBacklight(HIGH);
  lcd.print("ZAWILGOCENIE");
  lcd.setCursor (15, 0);
  lcd.print("%");
}

void loop()
{
  int sensorA = analogRead(A0);
  int sensorD = digitalRead(8);
  
  Serial.print("  ODCZYT A:");
  Serial.println(sensorA);
  Serial.print("  ODCZYT D:");
  Serial.println(sensorD);
  delay(100);  
  
  int opady =map (sensorA,1023,0,0,100);
  lcd.setCursor(13, 0);
  lcd.print(opady);
  if (opady >=30) {
  tone(12, 1600,700);}
  lcd.setCursor(5, 1);
  if (sensorD==1) {
     lcd.print("POGODA");}
  else
  lcd.print(" LEJE ");
  delay(2000);
}

