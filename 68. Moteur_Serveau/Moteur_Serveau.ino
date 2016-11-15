#include<Servo.h>
Servo myservo;
void setup()
{
  myservo.attach(8);
}

void loop ()
{
  for (int i=0;i<180;i+=1)
  {
    myservo.write(i);
    delay(1000);
  }
  for (int i=180;i>=0;i-=1)
  {
    myservo.write(i);
    delay(15);
  }
}
