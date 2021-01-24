#include<Servo.h>
Servo myservo;
const int trigPin=3;
const int echoPin=5;
long tmeduration;
int distance;
int Buzzer = 13;

void setup()
{
   myservo.attach(9);
   pinMode(trigPin,OUTPUT);
   pinMode(echoPin,INPUT);
   pinMode(13,OUTPUT);
   Serial.begin(9600);
   
}

void loop()
{
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  
  tmeduration=pulseIn(echoPin,HIGH);
  distance=(0.034*tmeduration)/2;

  if(distance<=60)
  {

    myservo.write(90);
    digitalWrite(Buzzer,HIGH);
  }
  else{
    myservo.write(0);
    digitalWrite(Buzzer,LOW);
  }
  Serial.print("distance:");
  Serial.println(distance);

  delay(1);
}
