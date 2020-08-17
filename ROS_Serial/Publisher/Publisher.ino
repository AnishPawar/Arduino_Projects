#include<ros.h>
#include<std_msgs/String.h>

ros::NodeHandle nh;
std_msgs::String str_msg;
ros::Publisher pub("Chatter",&str_msg);

char hello[13] = "hello world!";

void setup() 
{
  nh.initNode();
  nh.advertise(pub);

}

void loop() {
  str_msg.data = hello;
  pub.publish(&str_msg);
  nh.spinOnce();
  delay(1);

}
