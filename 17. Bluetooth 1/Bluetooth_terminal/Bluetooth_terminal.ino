int data;

void setup() {
  Serial.begin(9600);
}

void loop() {
  data =Serial1.read();
  Serial.println(data);
  delay(200);
}
