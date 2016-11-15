#include <VirtualWire.h>
int LED=2;
boolean LEDON=false;
char stan;
void setup()
{
 
  Serial.begin(9600);
  pinMode (LED,OUTPUT);
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
       String stan;
  	for (i = 0; i < buflen; i++)
  { 
  stan +=char(buf[i]);
  }
     if ( stan =="on") {
       LEDON=!LEDON;
  digitalWrite (LED, LEDON);
  delay(100);
   } } }
 
