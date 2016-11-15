
#include <Wire.h>
#include <TEA5767Radio.h>
#include <LiquidCrystal_I2C.h>
#define BACKLIGHT_PIN 3
LiquidCrystal_I2C	lcd(0x27,2,1,0,4,5,6,7);
float f;
TEA5767Radio radio = TEA5767Radio();

void setup()
{ 
  Wire.begin();
  lcd.begin(16, 2);
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.print("RADIO FM");
  delay(2000);
  lcd.clear();
  lcd.print("Czestotliwosc:");
}

void loop()
{
   int g =analogRead(A0);
   g = map(g, 0, 1023, 920, 1060);
  
  f=(float)g/10.0;
  radio.setFrequency(f);
    lcd.setCursor (1, 1);
  lcd.print("FM ");
  lcd.print(f);
  lcd.print(" MHz  ");
}
