#include<ros.h>
#include<std_msgs/Float32.h>
#include <Servo.h>
#include <sensor_msgs/LaserScan.h>

//#include<Ultrasonic.h>

ros::NodeHandle nh;
sensor_msgs::LaserScan distance_ultra;
ros::Publisher pub("Distance_Publisher",&distance_ultra);

//ros::Publisher id_pub("ID_Publisher",&id);

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


for (int j = 0;j<18;j++)
{
  ranges[j] = 0;  
}

nh.initNode();
nh.advertise(pub);


}

int flag = 0; 



void loop() 
{ 
  
    for (int i = 0;i<=180;i=i+10)
    {
      digitalWrite(trig,LOW);
      delay(50);
  
      digitalWrite(trig,HIGH);
      delayMicroseconds(10);
      digitalWrite(trig,LOW);
      first_servo.write(i);

      duration = pulseIn(echo,HIGH);
      distance = duration*0.034/2;

//      ranges[i] = i;
    
      //Header
      distance_ultra.header.stamp = nh.now();
      distance_ultra.header.frame_id = "laser_frame";
      
      //Angle 
      distance_ultra.angle_min = 0;
      distance_ultra.angle_max = 3.14;
      distance_ultra.angle_increment = 0.0174533;

      //Time 
      distance_ultra.time_increment = 0.110;
      distance_ultra.scan_time = 6.600;
      
      //Range 
      distance_ultra.range_min = 0.3;
      distance_ultra.range_max = 400;

      //Ranges 
    distance_ultra.ranges = ranges;
  pub.publish(&distance_ultra);

      
      
      
      delay(100);
    }
    
    
  nh.spinOnce();
 first_servo.write(0); 
}
