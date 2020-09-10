0
#include<ros.h>
#include<sensor_msgs/Range.h>

int trig =9;
int echo = 10;

long duration;
float distance;

ros::NodeHandle nh;
sensor_msgs::Range ultra_msg;
ros::Publisher pub("/Ultrasonic_Readings",&ultra_msg);

void setup() 
{
nh.initNode();
nh.advertise(pub);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
}

void loop() 
{
  digitalWrite(trig,LOW);
  delay(250);
  
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  duration = pulseIn(echo,HIGH);
  distance = duration*0.034/2;

  ultra_msg.field_of_view = 15;
  ultra_msg.min_range = 0; 
  ultra_msg.max_range = 450;
  ultra_msg.range = distance;
  
  pub.publish(&ultra_msg);
  nh.spinOnce();
  delay(1);

}
