void setup()
{
Serial.begin(9600);
pinMode(A1,INPUT);

}
void loop()
{
int var=analogRead(A1);
Serial.println(var);
if(var==0)
digitalWrite(2,LOW);
else

digitalWrite(2,HIGH);
delay(1000);


}
