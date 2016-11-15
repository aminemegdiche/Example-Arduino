#include <VirtualWire.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define BACKLIGHT_PIN 3
LiquidCrystal_I2C	lcd(0x27,2,1,0,4,5,6,7);

void setup()
{
        lcd.begin (16,2);
        lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
        lcd.setBacklight(HIGH);

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
       String wiad;
  	for (i = 0; i < buflen; i++)
  { 
  wiad +=char(buf[i]);
 }

  lcd.setCursor(0, 1);
  lcd.scrollDisplayLeft();
  lcd.print(wiad);
        
    }
}
