int a = 3;
int b = 4;
int c = 5;
int d = 6;
int przerwa=1;

void setup() {                
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  }


  
  void loop() {
  
  jeden();
  dwa();
  trzy();
  cztery();
  piec();
  szesc();
  siedem();
  osiem();
  }
 
 void jeden () {
  digitalWrite (1, LOW);
  digitalWrite (a, HIGH);
  delay(przerwa);
  digitalWrite (1, HIGH);
  digitalWrite (a, LOW);
}

void dwa () {
  digitalWrite (1, LOW);
  digitalWrite (b, HIGH);
  delay(przerwa);
  digitalWrite (1, HIGH);
  digitalWrite (b, LOW);
  }

void trzy () {
  digitalWrite (1, LOW);
  digitalWrite (c, HIGH);
  delay(przerwa);
  digitalWrite (1, HIGH);
  digitalWrite (c, LOW);
  }

void cztery () {
  digitalWrite (1, LOW);
  digitalWrite (d, HIGH);
  delay(przerwa);
  digitalWrite (1, HIGH);
  digitalWrite (d, LOW);
  }

void piec () {
  digitalWrite (2, LOW);
  digitalWrite (a, HIGH);
  delay(przerwa);
  digitalWrite (2, HIGH);
  digitalWrite (a, LOW);
  }

void szesc () {
  digitalWrite (2, LOW);
  digitalWrite (b, HIGH);
  delay(przerwa);
  digitalWrite (2, HIGH);
  digitalWrite (b, LOW);
  }

void siedem () {
  digitalWrite (2, LOW);
  digitalWrite (c, HIGH);
  delay(przerwa);
  digitalWrite (2, HIGH);
  digitalWrite (c, LOW);
  }

void osiem () {
  digitalWrite (2, LOW);
  digitalWrite (d, HIGH);
  delay(przerwa);
  digitalWrite (2, HIGH);
  digitalWrite (d, LOW);
  }

