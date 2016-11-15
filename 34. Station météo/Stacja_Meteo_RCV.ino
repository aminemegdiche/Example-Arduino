#include <VirtualWire.h>
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#define BACKLIGHT_PIN 3

LiquidCrystal_I2C	lcd(0x27,2,1,0,4,5,6,7);

void setup()
{
Serial.begin(9600);
delay(4000); 
lcd.begin (16,2);
lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
lcd.setBacklight(HIGH);
lcd.home ();

Serial.println("Stacja Meteo - ODBIORNIK");
    vw_setup(2000);
    vw_set_rx_pin(4);	 
    vw_rx_start();       
}

void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen)) 
       {
	int i;
       String wil, tem, cis;
  	for (i = 0; i < 6; i++)
  {   wil +=char(buf[i]);  }
  for (i > 6; i < 14; i++)
  {   tem +=char(buf[i]);  }
for (i = 15; i < buflen; i++)
  {   cis +=char(buf[i]);  }  
 
 Serial.println (wil);
 Serial.println (tem);
 Serial.println (cis);
 lcd.clear ();
 lcd.setCursor(0, 0);
 lcd.print (tem);
 lcd.setCursor(10, 0);
 lcd.print (wil);
 lcd.setCursor(0, 1);
 lcd.print (cis);
   } 
    }

