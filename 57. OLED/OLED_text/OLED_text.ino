#include "U8glib.h"

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);	// I2C / TWI 
//U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NO_ACK);	// Display which does not send AC

const uint8_t paski[] PROGMEM = {
  0x00,           
  0xff,          
  0x00,          
  0xff,          
  0x00,           
  0xff,          
  0x00,           
  0xff,          
  0x00,           
  0xff,          
  0x00,          
  0xff,          
  0x00,           
  0xff,          
  0x00,           
  0xff            
};
const uint8_t antypaski[] PROGMEM = {
  0xff,
  0x00,        
  0xff,          
  0x00,          
  0xff,          
  0x00,           
  0xff,          
  0x00,           
  0xff,          
  0x00,           
  0xff,         
  0x00,          
  0xff,         
  0x00,           
  0xff,        
  0x00         
             
};

void draw(void) {
  // graphic commands to redraw the complete screen should be placed here  
  u8g.setFont(u8g_font_unifont);
 // u8g.setFont(u8g_font_osb21);
 u8g.drawStr( 15, 14, "ELEKTROMARAS!");
 u8g.setFont(u8g_font_osb21);
 u8g.drawStr( 18, 42, "*2015*");
 u8g.drawBitmapP( 0, 45, 1, 16, paski);
   for (int i=1; i<10; i++){
  u8g.drawBitmapP( 16*i, 45, 1, 16, paski);}
  for (int i=1; i<10; i++){
  u8g.drawBitmapP( 16*i-8, 45, 1, 16, antypaski);}
 u8g.drawFrame(0,0,128,64);
// u8g.setFont(u8g_font_8x13B);
// u8g.drawStr( 0, 62, "czcionka");
}

void setup(void) {
  
  // flip screen, if required
  // u8g.setRot180();
  
  // set SPI backup if required
  //u8g.setHardwareBackup(u8g_backup_avr_spi);

  // assign default color value
  if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
    u8g.setColorIndex(255);     // white
  }
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) {
    u8g.setColorIndex(3);         // max intensity
  }
  else if ( u8g.getMode() == U8G_MODE_BW ) {
    u8g.setColorIndex(1);         // pixel on
  }
  else if ( u8g.getMode() == U8G_MODE_HICOLOR ) {
    u8g.setHiColorByRGB(255,255,255);
  }
}

void loop(void) {
  // picture loop
  u8g.firstPage();  
  do {
    draw();
  } while( u8g.nextPage() );
  
  // rebuild the picture after some delay
  delay(50);
}
