 const int guzik = 12;      
 const int buzz = 11;
 int stang = 0;         
 int czas = 0;
 int stank, stanon ;
 
void setup() {
  
  pinMode(1, OUTPUT);    
  pinMode(2, OUTPUT); 
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);    
  pinMode(5, OUTPUT); 
  pinMode(6, OUTPUT); 
  pinMode(7, OUTPUT);    
  pinMode(8, OUTPUT); 
  pinMode(9, OUTPUT); 
  pinMode(10, OUTPUT);
  pinMode(guzik, INPUT);
  pinMode(A5, INPUT); 
  pinMode(A4, INPUT);  
  pinMode(buzz, OUTPUT);

on() ; 
}
  
 
 void loop (){
 
  
 stang = digitalRead (guzik);
 
 if (stang == HIGH && czas<=10) {
  czas =czas +1 ;
  digitalWrite(czas, HIGH);
 delay(250);  }

 if (stang == LOW && czas>0) {
  tone(buzz, 2000, 50);
  delay(3000);
  digitalWrite(czas, LOW);
   czas =czas -1 ;}
   else
 stank = analogRead (A5);
if (stank < 1000) {tone(buzz, 2000, 150); delay(200);}
 
}


void on() {
  do
{     stanon = analogRead(A4);
   for(int i = 0; i <=10; i++) { 
  digitalWrite(i, HIGH);
  delay(70);
  digitalWrite(i, LOW);  }    }
  
   while (stanon < 700); 
 }
 


