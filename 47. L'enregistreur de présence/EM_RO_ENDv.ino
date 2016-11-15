#include <DS1307RTC.h>
#include <Time.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SD.h>
#define BACKLIGHT_PIN 3
LiquidCrystal_I2C	lcd(0x27,2,1,0,4,5,6,7);

int kod=0;
int accessLed = 9;
int noaccessLed = 8;
#define SS_PIN           10
#define PAUSE         3000
#define USERS_NUM        5 // liczba uzytkownikow



// tworzymy nowy typ dla uzytkownika
typedef struct {
  int user_id;     // identyfikator
  char* user_name; // nazwa
} 
User;

// definicja uzytkownikow
User users[USERS_NUM] = {
  { 647, "H. Sienkiewicz" },
  { 677, "W. Reymont  "   },
  { 678, "S. Wyspianski"  },
  { 621, "S. Zeromski "   },
  { 666, "J. Zulczyk  "   }  };


const char *monthName[12] = {
  "Jan", "Feb", "Mar", "Apr", "May", "Jun",
  "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };




void setup()
{
  lcd.begin (16,2);
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);

  Serial1.begin(9600);
  Serial.begin(9600);  
  pinMode(10, OUTPUT);
  // pinMode(SS, OUTPUT);
  pinMode(accessLed, OUTPUT);
  pinMode(noaccessLed, OUTPUT);
  if (!SD.begin(10)) {
    Serial.println("Brak lub uszkodzenie karty SD");
    return;
  }
  Serial.println("Karta SD zainicjalizowana.");
}



void loop()
{

  lcd.setCursor(0, 0);
  lcd.print(clock());
  lcd.setCursor(0, 1);
  lcd.print("Zbliz karte");


  if (Serial1.available() > 0) 
  { 
    for (int z = 0 ; z < 14 ; z++) // odzytaj dane z key foba (14 sekcji)
    {   
      kod = kod+ Serial1.read();   //i je zsumuj
    } 

    Serial.println(kod);
    for (int i = 0; i < USERS_NUM; i++) {
      // jezeli kod RFID zostal znaleziony wowczas daj dostep
      if (kod == (users[i].user_id)) {
        lcd.setCursor(0, 0);
        lcd.print("  DOSTEP DLA    ");
        lcd.setCursor(0, 1);
        lcd.print(users[i].user_name);

        saveToFile(users[i].user_name); // zapisz do pliku na karcie SD

        digitalWrite(accessLed, LOW);
        digitalWrite(noaccessLed, HIGH);

        delay(PAUSE); // odczekaj - czas dostepu

        digitalWrite(accessLed, HIGH);
        digitalWrite(noaccessLed, LOW);
        lcd.clear();

      }
    }
    delay(500);
    kod=0;
  }
}
// funkcja zapisujaca do pliku czas + uzytkownik
void saveToFile(String data) {
  File plik = SD.open("wejscia.txt", FILE_WRITE);


  data = clock() + data;  // dodaj czas
  if (plik) {             // jezeli plik jest dostepny, zapisz dane
    plik.println(data);
    plik.close();
    // debug
    Serial.print("SD zapis: ");
    Serial.println(data);
  }
  else {
    Serial.println("Blad otwierania wejscia.txt");
  }
}

// funkcja odczytujaca czas
String clock(){
  tmElements_t dt;
  String dateTime = "";

  if (RTC.read(dt)) {
    dateTime += dt.Day;
    dateTime += ("/");
    dateTime += (monthName[dt.Month-1]);
    dateTime += ("/");
    dateTime += (tmYearToCalendar(dt.Year)-2000);
    dateTime += (" ");
    dateTime += dt.Hour;
    dateTime += (":");
    if (dt.Minute >= 0 && dt.Minute < 10) {  //dodaj zero  
      dateTime +=('0');
    }
    dateTime += dt.Minute;
    dateTime += (" - ");
    // Serial.println(dateTime);
  } 
  else {
    if (RTC.chipPresent()) {
      Serial.println("DS1307 uruchom zegar.");
    } 
    else {
      Serial.println("DS1307 blad odczytu! Sprawdz polaczenie.");
    }
  }
  return dateTime;
}

