int kb1 = A1;
int kb2 = A2;
int kb3 = A3;
int kb4 = A4;

int v1, v2, v3, v4;

void setup() {
  Serial.begin(9600); 
  }

void loop() {
  
  v1 = analogRead(kb1);
  v2 = analogRead(kb2);
  v3 = analogRead(kb3);
  v4 = analogRead(kb4);
 
  Serial.println(v1); 
  Serial.println(v2); 
  Serial.println(v3); 
  Serial.println(v4); 
   
   Serial.print("WCISNIETY KLAWISZ: ");       
  
   
  if (v4>100 && v4<300){
  Serial.println("1");}
  if (v4>300 && v4<550){
  Serial.println("2");}
  if (v4>550 && v4<800){
  Serial.println("3");}
  if (v4>960){
  Serial.println("4");}
  
   if (v3>100 && v3<300){
  Serial.println("5");}
  if (v3>300 && v3<550){
  Serial.println("6");}
  if (v3>550 && v3<800){
  Serial.println("7");}
  if (v3>960){
  Serial.println("8");}
  
  if (v2>100 && v2<300){
  Serial.println("9");}
  if (v2>300 && v2<550){
  Serial.println("10");}
  if (v2>550 && v2<800){
  Serial.println("11");}
  if (v2>960){
  Serial.println("12");}
  
if (v1>100 && v1<300){
  Serial.println("13");}
  if (v1>300 && v1<550){
  Serial.println("14");}
  if (v1>550 && v1<800){
  Serial.println("15");}
  if (v1>960){
  Serial.println("16");}
delay(500);
Serial.println(" ");
 Serial.println("----------------------");
}
