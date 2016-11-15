/*
  LiquidCrystal Library - Hello World
 
 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the 
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.
 
 This sketch prints "Hello World!" to the LCD
 and shows the time.
 
  The circuit:
 * LCD RS pin to digital pin 12 (pin4 na LCD)
 * LCD Enable pin to digital pin 11  (pin6 na LCD)
 * LCD D4 pin to digital pin 5  (pin11 na LCD)
 * LCD D5 pin to digital pin 4  (pin12 na LCD)
 * LCD D6 pin to digital pin 3  (pin13 na LCD)
 * LCD D7 pin to digital pin 2  (pin14 na LCD)
 * LCD R/W pin to ground    (pin5 na LCD)
 * 10K resistor:    (potencjometr)
 * ends to +5V and ground  (pin 1 i 16 na LCD)
 * wiper to LCD VO pin (pin 3)  (pin3 na LCD do wyjscia z potencjometra)
 
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {

  
  
  // print out the value you read:
  
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Miernik Swiatla");
  lcd.setCursor(0, 1);
  lcd.print("JASNOSC");
  lcd.setCursor (14, 1);
  lcd.print("%");
}

void loop() {
    
  int sensorValue = analogRead(A0);
float swiatlo = sensorValue * (100.0 / 1023.0);
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(8, 1);
  // print the number of seconds since reset:
  lcd.print(swiatlo);
    // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
delay (500);
  
}

