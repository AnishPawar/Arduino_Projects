#include <ros.h>
#include <std_msgs/Int32.h>

int brightness = 0;
int led_pin = 9;

//Initialising Node handle
ros::NodeHandle  nh;

void messageCb( const std_msgs::Int32& toggle_msg)
{
  brightness = brightness + toggle_msg.data;
  analogWrite(led_pin,brightness);
}


//Initialising ros subscriber
ros::Subscriber<std_msgs::Int32>sub("led_glower",&messageCb);

void setup() 
{
  pinMode(led_pin,OUTPUT);
  nh.initNode();
  //ros::Subscriber sub = nh.subscribe("led_glower",1000,messageCb);
  nh.subscribe(sub);

}

void loop() 
{
  nh.spinOnce();
  delay(1);
}
