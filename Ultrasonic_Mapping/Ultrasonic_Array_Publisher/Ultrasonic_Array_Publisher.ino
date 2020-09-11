#include<ros.h>
#include<std_msgs/Float32.h>
//#include<std_msgs/Int32.h>

#include <Servo.h>
//#include <std_msgs/Float32MultiArray.h>

//#include<Ultrasonic.h>

ros::NodeHandle nh;

std_msgs::Float32 distance_ultra;
ros::Publisher pub("Distance_Publisher",&distance_ultra);


Servo first_servo;
int echo =5;
int trig = 6;

long duration;
float distance;

float ranges[18];

void setup() 
{
int ServoPin = 3;
first_servo.attach(ServoPin);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
nh.initNode();
nh.advertise(pub);


}


void loop() 
{ 
  
    for (int i = 0;i<=180;i=i+1)
    {
      digitalWrite(trig,LOW);
      delay(50);
  
      digitalWrite(trig,HIGH);
      delayMicroseconds(10);
      digitalWrite(trig,LOW);
      first_servo.write(i);

      duration = pulseIn(echo,HIGH);
      distance = duration*0.034/2;
      
//      ranges[i/10] = distance;  
      distance_ultra.data = distance;
//      seq.data = i;
//      header.publish(&seq);
      pub.publish(&distance_ultra);  
      nh.spinOnce();

      delay(50);

    }
//    distance_ultra.data = ranges;
    
  
 first_servo.write(0); 
}
