#include <Servo.h> 
int bt;
int L1=9;
int L2=8;
int L3=7;
int D=13;
int A=11;
int srv=10;
boolean stA=0;
boolean stD=0;
Servo myservo;
int pos = 90;

void setup() {                
 myservo.attach(10);
  pinMode(L1, OUTPUT);  
  pinMode(L2, OUTPUT);  
  pinMode(L3, OUTPUT);  
  pinMode(srv, OUTPUT);  
  pinMode(A, OUTPUT); 
  pinMode(D, OUTPUT);  
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0){     
      bt = Serial.read();}

  if (bt == '1') {
      digitalWrite(L1, HIGH);}  
    else if (bt == '2') {
      digitalWrite(L1, LOW);}
    else if (bt == '3') {
      digitalWrite(L2, HIGH);}
    else if (bt == '4') {
      digitalWrite(L2, LOW);}
    else if (bt == '5') {
      digitalWrite(L3, HIGH);}
    else if (bt == '6') {
      digitalWrite(L3, LOW);}
 
  else if (bt == 'a') {
      stA=!stA;
      digitalWrite(A, stA); 
      delay(300);   }  
  
   else if (bt == 'b') {
       pos=pos+2;
       myservo.write(pos);
       delay(15); 
       }
     
   else if (bt == 'c') {
       pos=pos-2;
       myservo.write(pos);
       delay(15);   
       }
  
  else if (bt == 'd') {
       stD=!stD;
       digitalWrite(D, stD);  }
  
  delay(200);              
 }
