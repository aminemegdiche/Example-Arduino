
#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
int val;    // variable to read the value from the analog pin 
 
void setup() 
{ 
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
} 
 
void loop() 
{ 
  val = Serial.parseInt();
  if(val>0) {
  myservo.write(val);                  // sets the servo position according to the provided value 
  delay(15); }                          // waits for the servo to get there 
} 
