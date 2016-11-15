//partie declarative
float lum=0;
float temp=0;

void setup ()
{
   Serial.begin(9600);
   pinMode(A0,INPUT);
   pinMode(A1,INPUT);
pinMode(7,OUTPUT);
}
void loop()
{
  lum=analogRead(A0);
  Serial.println(lum);
    temp=analogRead(A1);
  temp=temp*0.487;
   Serial.println("La temperature est");
  Serial.println(temp);
 if(lum<1000)
 {
  digitalWrite(7,LOW); 
 }
 else
 {digitalWrite(7,HIGH);}

  
  
  if (temp>19)
  {
    digitalWrite(8,HIGH);
  }
  else
  {
     digitalWrite(8,LOW);
 
}
  delay(2000);
}
