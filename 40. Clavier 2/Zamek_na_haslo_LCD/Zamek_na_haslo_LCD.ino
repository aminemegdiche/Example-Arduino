/*
||  Simple Password Entry Using Matrix Keypad
||  4/5/2012 Updates Nathan Sobieck: Nathan@Sobisource.com
||
*/


//* is to validate password   
//# is to reset password attempt

/////////////////////////////////////////////////////////////////

#include <Password.h> //http://www.arduino.cc/playground/uploads/Code/Password.zip
#include <Keypad.h> //http://www.arduino.cc/playground/uploads/Code/Keypad.zip

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define BACKLIGHT_PIN 3
int guzik =0;
int stan;
boolean sw =false;

LiquidCrystal_I2C	lcd(0x27,2,1,0,4,5,6,7);

Password password = Password( "1234" );

const byte ROWS = 4; // Four rows
const byte COLS = 4; //  columns
// Define the Keymap
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = { 11,10,9,8 };// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte colPins[COLS] = { 7,6,5,4, };// Connect keypad COL0, COL1 and COL2 to these Arduino pins.


// Create the Keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){

  pinMode(guzik, INPUT_PULLUP);
  Serial.begin(9600);
  lcd.begin (16,2);
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(LOW);
  lcd.home();
  lcd.print("ENTER CODE:");
  lcd.setCursor(0,1); 
  keypad.addEventListener(keypadEvent); //add an event listener for this keypad
    
}

void cls() {
  lcd.clear();
  lcd.home();
  lcd.print("ENTER CODE:");
  lcd.setCursor(0,1); }

void loop(){
   int jasn = analogRead(A0);
   if (jasn<600) {lcd.setBacklight(HIGH);}
   else {
   stan = digitalRead(guzik);
   delay(100);
   if (stan==0){ sw = !sw ; lcd.setBacklight(sw);} }
   keypad.getKey();
  
}

//take care of some special events
void keypadEvent(KeypadEvent eKey){
  switch (keypad.getState()){
    case PRESSED:
	Serial.print("Pressed: ");
	Serial.println(eKey);
        lcd.print('*');
	switch (eKey){
	  case '*': checkPassword(); break;
	  case '#': password.reset(); cls(); break;
	  default: password.append(eKey);
     }
  }
}

void checkPassword(){
  if (password.evaluate()){
    Serial.println("Success");
    lcd.print("Success");
    delay(2000);
    cls();
    //Add code to run if it works
  }else{
    Serial.println("Wrong");
    lcd.print("Wrong");
    delay(2000);
    cls();
    //add code to run if it did not work
  }

}
