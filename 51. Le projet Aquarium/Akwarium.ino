#include <Servo.h> 
// czas pomiedzy pomiarami 5min - 300.000ms
#define ODSTEP 1000

#include <OneWire.h>
#include <DallasTemperature.h>
// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 2
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);
Servo myservo;


int czujka = 7;  
int pompa = 8; 
int grzalka = 6;

int stan = 0; 
int licznik = 0;

unsigned long czas_poprzedni = 0;

void setup() {
        Serial.begin(9600);
        delay(2000);	
        pinMode(czujka, INPUT);
	pinMode(pompa, OUTPUT);
        pinMode(grzalka, OUTPUT);
        digitalWrite(grzalka,LOW);
        sensors.begin();
        myservo.attach(9);
        myservo.write(1); 
        Serial.println("Setup poszedl");
}

void loop() 
{
	// czas liczony od momentu wlaczenia urzadzenia 
	unsigned long czas_aktualny = millis(); 
	// sprawdza czy uplynal juz okreslony czas miedzy pomiarami
	if(czas_aktualny - czas_poprzedni > ODSTEP) 

      {
	czas_poprzedni = czas_aktualny; 
        licznik = licznik + 1;
        Serial.println("woda start");
        woda();
        Serial.println("woda stop");
        Serial.println("temperatura start");
        temperatura();
        Serial.println("temperatura stop");
        Serial.println("karmnik start");
        karmnik();
        Serial.println("karmnik stop");

	}
}


 void woda()
 {
   stan = digitalRead(czujka);
   Serial.println(stan);
   if (stan==1)
   {
   digitalWrite (pompa, HIGH);
   delay(2000); 
   digitalWrite(pompa,LOW);
    }
 else
   {
   digitalWrite(pompa,LOW);
   }
 }
 

 void temperatura()
 {
   sensors.requestTemperatures();
   Serial.println(sensors.getTempCByIndex(0));
   float tempC = (sensors.getTempCByIndex(0));
   
      if (tempC < 23.00)
      {
    digitalWrite(grzalka,HIGH);
    delay (100); 
    Serial.print("Grzeje");
    digitalWrite(grzalka,LOW);
   }
 }


void karmnik()
{
  if (licznik==50)
  {
    myservo.write(90);              
    delay(550); 
    myservo.write(1);
    delay(550);
    licznik=0;
}
}
