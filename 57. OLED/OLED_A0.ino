#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
int a;


void setup()   { 
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
   display.clearDisplay();
   
}

void loop() {
a=analogRead(A0);
display.clearDisplay();
display.setTextSize(2);
display.setTextColor(WHITE);
display.setCursor(0,0);
display.println("Odczyt A0:");
display.setTextSize(4);
display.setTextColor(WHITE);
display.setCursor(20,30);
display.println(a);
delay (500);
display.display();
}
