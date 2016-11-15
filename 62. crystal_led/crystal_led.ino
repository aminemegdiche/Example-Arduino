//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.print("Humidite 56%");
  lcd.setCursor(0,1);
  lcd.print("Temperature 12 C");
}


void loop()
{
    lcd.setCursor(2,0);
  lcd.print("Humidite 56%");
  delay(5000);
  lcd.clear();
  lcd.print("Temperature 12 C");
   delay(5000);
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("Temperature 12 C");
   delay(5000);
  lcd.clear();
}
