#include<ros.h>
#include<std_msgs/Float32.h>
#include <Servo.h>
//#include<Ultrasonic.h>

ros::NodeHandle nh;
std_msgs::Float32 distance_ultra;
//std_msgs::Float32 id;
ros::Publisher pub("Distance_Publisher",&distance_ultra);

//ros::Publisher id_pub("ID_Publisher",&id);

Servo first_servo;
int echo =5;
int trig = 6;

long duration;
float distance;


void setup() 
{
int ServoPin = 3;
first_servo.attach(ServoPin);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
nh.initNode();
nh.advertise(pub);
}

int flag = 0; 

void loop() 
{ 
  
    for (int i = 0;i<=180;i=i+5)
    {
      digitalWrite(trig,LOW);
      delay(50);
  
      digitalWrite(trig,HIGH);
      delayMicroseconds(10);
      digitalWrite(trig,LOW);
      first_servo.write(i);
  
      duration = pulseIn(echo,HIGH);
      distance = duration*0.034/2;
      
      distance_ultra.data = distance;
      
      pub.publish(&distance_ultra);
//      id.data = distance;
//      id_pub.publish(&id);
//      
      nh.spinOnce();
      delay(50);
      
    }  
  
 first_servo.write(0); 
 flag ++;
}
