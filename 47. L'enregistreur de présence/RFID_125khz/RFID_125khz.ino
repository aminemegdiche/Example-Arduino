//#include <SoftwareSerial.h>
//SoftwareSerial RFID(2, 3); // RX and TX
 
int i;
 
void setup()
{
  //RFID.begin(9600);    // start serial to RFID reader
  Serial.begin(9600);  // start serial to PC 
  Serial1.begin(9600);
}
 
void loop()
{
//  if (RFID.available() > 0) 
//  {
//     i = RFID.read();
   if (Serial1.available() > 0) 
  {
     i = Serial1.read();
     Serial.print(i, DEC);
     Serial.print(" ");
     
  }
  
  //else {Serial.print("DUPA");
  //delay(2000);}
}
