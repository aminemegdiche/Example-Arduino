#include "DHT.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

#define DHTPIN 2
#define DHTTYPE DHT11 //(pour un capteur DHT11)
 
DHT dht(DHTPIN, DHTTYPE);
 
float h = 0;
float t = 0;
 
void setup(){
        Serial.begin(9600);
        dht.begin();
        lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.print("Humidite");
  lcd.setCursor(0,1);
  lcd.print("Tempera");
}
 
void loop(){
        h = dht.readHumidity();
        t = dht.readTemperature();
        if (isnan(t) || isnan(h)){
                Serial.println( "Lecture impossible !");
        }else{
           lcd.setCursor(0,0);
  lcd.print("Humidite :");  
  lcd.setCursor(9,0);
  lcd.print(h);
  lcd.setCursor(14,0);
  lcd.print(" %");

  lcd.setCursor(0,1);
  lcd.print("Tempera ");
    lcd.setCursor(9,1);
  lcd.print(t);
     lcd.setCursor(14,1);
  lcd.print("*C");

          
              
        }
        delay(1000);
      //   lcd.clear();
}
