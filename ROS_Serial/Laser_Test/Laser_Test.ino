#include<ros.h>
#include<std_msgs/Float32.h>
#include <Servo.h>
#include <sensor_msgs/LaserScan.h>


ros::NodeHandle nh;
sensor_msgs::LaserScan distance_ultra;
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

int flag = 0;

void loop() 
{ if (flag ==0){
  
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

      ranges[i/10] = distance;
      delay(50);
    }
}
  flag = 1;
    
      //Header
      distance_ultra.header.stamp = nh.now();
      distance_ultra.header.frame_id = "fake_laser";
      
      //Angle 
      distance_ultra.angle_min = 0;
      distance_ultra.angle_max = 3.14;
      distance_ultra.angle_increment = 0.0174533;

      //Time 
      distance_ultra.time_increment = 0;//0.110;
      distance_ultra.scan_time = 0;//6.600;
      
      //Range 
      distance_ultra.range_min = 0.0;
      distance_ultra.range_max = 40;

      //Ranges 
//      /distance_ultra.ranges.resize(18);
      
      distance_ultra.ranges_length = 18;
         distance_ultra.ranges = ranges;      
      pub.publish(&distance_ultra);      
//      for(unsigned int i = 0; i < 18; ++i){
//         distance_ultra.ranges[i] = ranges[i];
//         scan.intensities[i] = intensities[i];
      



      nh.spinOnce();
 first_servo.write(0); 
}
