#include <TVout.h>
#include <fontALL.h>

int odczyt;

TVout TV;


void setup() {
 TV.begin(PAL,120,110); // TV.begin(PAL,120,96);
 TV.select_font(font8x8);
 TV.println(20,10, "SUBSKRYBUJ");
 TV.println(4,95, "ELEKTROMARASA");
 TV.draw_circle(30,50,20,WHITE); // TV.draw_circle(poz,pion,srednica,WHITE);
 TV.draw_circle(90,50,20,WHITE,INVERT); // TV.draw_circle(poz,pion,srednica,WHITE);
 TV.delay(5000);
 TV.clear_screen();
}

void loop() {
  
   

 TV.draw_rect(59,88,59,20,WHITE); //TV.draw_rect(poz,pion,szer,wys):
 TV.draw_rect(0,88,59,20,WHITE);
 TV.draw_rect(0,0,59,20,WHITE);
 TV.draw_rect(59,0,59,20,WHITE);  
 
 TV.draw_line(0,50,120,50,WHITE);  //TV.draw_line(poczpoz,poczpion,konpoz, konpion, WHITE); 
 
 TV.select_font(font6x8);
 TV.println(4,40, "HEJ TU ELEKTROMARAS");
 TV.select_font(font4x6);
 TV.print(15,9, "Opcja 1");
 TV.print(75,9,"Opcja 2");
 TV.print(15,96, "Opcja 3");
 TV.print(75,96, "Opcja 4");
 
 odczyt = analogRead(A0);
 TV.print(10,60,"Odzczyt z pinu A0:");
 TV.println(85,60,odczyt);
 TV.delay(500);
}


