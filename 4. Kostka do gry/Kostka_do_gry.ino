//Kostka do gry
/* 7 diod ulozonych jak w kostce do gry polaczonych nastepujaco:
srodkowa (1) do pinu 8
prawa gorna i lewa dolna (2) do pinu 9
prawa dolna i lewa gorna (odbicie 2) do pinu 10
srodkowe prawa i lewa do pinu 11
Tact switch podlaczony z jednej strony do +5V a z drugiej do pinu 2 + pull-down rezystor (10K)
Diody trzeba zaopatrzyc w stosowne resystory
*/

int raz=8;
int dwa=9;
int odwa=10;
int szesc=11;
int wynik;
int guzik=2;
int stanguzika;

void setup()   {
  pinMode(raz, OUTPUT);
  pinMode(dwa, OUTPUT);
  pinMode(odwa, OUTPUT);
  pinMode(szesc, OUTPUT);
  pinMode(guzik, INPUT);
}

void loop()  {
    digitalWrite(raz, LOW);
    digitalWrite(dwa, LOW);
    digitalWrite(odwa, LOW);
    digitalWrite(szesc, LOW);
   stanguzika = digitalRead(guzik);
     if (stanguzika == HIGH){
    wynik=random(5);
    
    //switch(wynik) {
      //case 0:
      if (wynik==0){
      digitalWrite(dwa, HIGH);
      digitalWrite(odwa, HIGH);
      digitalWrite(szesc, HIGH);
      delay(2000);}
      
      // case 1:
      if (wynik==1){
      digitalWrite(raz, HIGH);
      delay(2000);}
      
      //case 2:
      if (wynik==2){
      digitalWrite(dwa, HIGH);
      delay(2000); }
      
      //case 3:
      if (wynik==3){
      digitalWrite(raz, HIGH);
      digitalWrite(dwa, HIGH);
      delay(2000);}
      
      //case 4:
      if (wynik==4){
      digitalWrite(dwa, HIGH);
      digitalWrite(odwa, HIGH);
      delay(2000);}
      
      //case 5:
      if (wynik==5){
      digitalWrite(raz, HIGH);
      digitalWrite(dwa, HIGH);
      digitalWrite(odwa, HIGH);
      delay(2000); }
    } 
 }

