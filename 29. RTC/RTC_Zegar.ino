#include <DS1307RTC.h>
#include <Time.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define BACKLIGHT_PIN 3
LiquidCrystal_I2C	lcd(0x27,2,1,0,4,5,6,7);

const char *monthName[12] = {
  "Jan", "Feb", "Mar", "Apr", "May", "Jun",
  "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

void setup() {

   lcd.begin(16, 2);
   lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
   lcd.setBacklight(HIGH);
}

void loop() {
  tmElements_t tm;

  if (RTC.read(tm)) {
   
    lcd.setCursor (0, 0);
    LCDprint2digits(tm.Hour);
    lcd.print(':');
    LCDprint2digits(tm.Minute);
    lcd.print(':');
    LCDprint2digits(tm.Second);
    lcd.setCursor (0, 1);
    lcd.print(tm.Day);
    lcd.print('/');
    lcd.print(monthName[tm.Month-1]);
    lcd.print('/');
    lcd.print(tmYearToCalendar(tm.Year));
    
    
  } else {
    if (RTC.chipPresent()) {
      lcd.println("DS1307 stoi. Uruchom Zegar");
      } 
       else {
      lcd.println("DS1307 blad oczczytu!");
      lcd.println("sprawdz polaczenie");
    }
    delay(9000);
  }
  delay(1000);
}

//void print2digits(int number) {
//  if (number >= 0 && number < 10) {
//    Serial.write('0');
//  }
//  Serial.print(number);
//}
  
void LCDprint2digits(int number) {
  if (number >= 0 && number < 10) {
    lcd.write('0');
  }
  lcd.print(number);  
}
