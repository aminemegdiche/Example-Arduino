
int a = 1;
int b = 2;
int c = 3;
int d = 4;
int e = 5;
int f = 6;
int g = 7;


void setup() {                
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
}


  
  void loop() {
  
  zero();  
  jeden();
  dwa();
  trzy();
  cztery();
  piec();
  szesc();
  siedem();
  osiem();
  dziewiec();
 }
 
 void jeden () {
  digitalWrite (b, HIGH);
  digitalWrite (c, HIGH);
  delay(1000);
  digitalWrite (b, LOW);
  digitalWrite (c, LOW);
}

void dwa () {
  digitalWrite (a, HIGH);
  digitalWrite (b, HIGH);
  digitalWrite (g, HIGH);
  digitalWrite (e, HIGH);
  digitalWrite (d, HIGH);
  delay(1000);
  digitalWrite (a, LOW);
  digitalWrite (b, LOW);
  digitalWrite (g, LOW);
  digitalWrite (e, LOW);
  digitalWrite (d, LOW);
  }

void trzy () {
  digitalWrite (a, HIGH);
  digitalWrite (b, HIGH);
  digitalWrite (g, HIGH);
  digitalWrite (c, HIGH);
  digitalWrite (d, HIGH);
  delay(1000);
  digitalWrite (a, LOW);
  digitalWrite (b, LOW);
  digitalWrite (g, LOW);
  digitalWrite (c, LOW);
  digitalWrite (d, LOW);
  }

void cztery () {
  digitalWrite (f, HIGH);
  digitalWrite (b, HIGH);
  digitalWrite (g, HIGH);
  digitalWrite (c, HIGH);
  delay(1000);
  digitalWrite (f, LOW);
  digitalWrite (b, LOW);
  digitalWrite (g, LOW);
  digitalWrite (c, LOW);
  }

void piec () {
  digitalWrite (a, HIGH);
  digitalWrite (f, HIGH);
  digitalWrite (g, HIGH);
  digitalWrite (c, HIGH);
  digitalWrite (d, HIGH);
  delay(1000);
  digitalWrite (a, LOW);
  digitalWrite (f, LOW);
  digitalWrite (g, LOW);
  digitalWrite (c, LOW);
  digitalWrite (d, LOW);
  }

void szesc () {
  digitalWrite (a, HIGH);
  digitalWrite (f, HIGH);
  digitalWrite (g, HIGH);
  digitalWrite (c, HIGH);
  digitalWrite (d, HIGH);
  digitalWrite (e, HIGH);
  delay(1000);
  digitalWrite (a, LOW);
  digitalWrite (f, LOW);
  digitalWrite (g, LOW);
  digitalWrite (c, LOW);
  digitalWrite (d, LOW);
  digitalWrite (e, LOW);
  }

void siedem () {
  digitalWrite (a, HIGH);
  digitalWrite (b, HIGH);
  digitalWrite (c, HIGH);
  delay(1000);
  digitalWrite (a, LOW);
  digitalWrite (b, LOW);
  digitalWrite (c, LOW);
  }

void osiem () {
  digitalWrite (a, HIGH);
  digitalWrite (b, HIGH);
  digitalWrite (c, HIGH);
  digitalWrite (d, HIGH);
  digitalWrite (e, HIGH);
  digitalWrite (f, HIGH);
  digitalWrite (g, HIGH);
  delay(1000);
  digitalWrite (a, LOW);
  digitalWrite (b, LOW);
  digitalWrite (c, LOW);
  digitalWrite (d, LOW);
  digitalWrite (e, LOW);
  digitalWrite (f, LOW);
  digitalWrite (g, LOW);
  }

void dziewiec () {
  digitalWrite (a, HIGH);
  digitalWrite (b, HIGH);
  digitalWrite (c, HIGH);
  digitalWrite (d, HIGH);
  digitalWrite (f, HIGH);
  digitalWrite (g, HIGH);
  delay(1000);
  digitalWrite (a, LOW);
  digitalWrite (b, LOW);
  digitalWrite (c, LOW);
  digitalWrite (d, LOW);
  digitalWrite (f, LOW);
  digitalWrite (g, LOW);
  }

void zero () {
  digitalWrite (a, HIGH);
  digitalWrite (b, HIGH);
  digitalWrite (c, HIGH);
  digitalWrite (d, HIGH);
  digitalWrite (e, HIGH);
  digitalWrite (f, HIGH);
  delay(1000);
  digitalWrite (a, LOW);
  digitalWrite (b, LOW);
  digitalWrite (c, LOW);
  digitalWrite (d, LOW);
  digitalWrite (e, LOW);
  digitalWrite (f, LOW);
  }
