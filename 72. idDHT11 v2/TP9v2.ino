#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11 //(pour un capteur DHT11)
 
DHT dht(DHTPIN, DHTTYPE);
 
float h = 0;
float t = 0;
 
void setup(){
        Serial.begin(9600);
        dht.begin();
}
 
void loop(){
        h = dht.readHumidity();
        t = dht.readTemperature();
        if (isnan(t) || isnan(h)){
                Serial.println( "Lecture impossible !");
        }else{
          Serial.print("Humidute");
          Serial.println(h);
          Serial.print("Temperature");
          Serial.println(t);
          
        }
      }
