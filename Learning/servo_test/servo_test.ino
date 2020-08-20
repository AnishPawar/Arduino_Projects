#include <Servo.h>
Servo first_servo;
int echo =5;
int trig = 6;

long duration;
int distance;

void setup() 
{
int ServoPin = 3;
first_servo.attach(ServoPin);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
Serial.begin(9600);
}

int flag = 0; 

void loop() 
{
  if (flag == 0)
   { for (int i = 0;i<=180;i=i+5)
    {
      digitalWrite(trig,LOW);
      delay(250);
  
      digitalWrite(trig,HIGH);
      delayMicroseconds(10);
      digitalWrite(trig,LOW);
      first_servo.write(i);
  
      duration = pulseIn(echo,HIGH);
      distance = duration*0.034/2;
//      Serial.println("Distance (cm):");
      Serial.println(distance);
  
      delay(500);
      flag = 1;
    }  
  }
 first_servo.write(0); 
}
