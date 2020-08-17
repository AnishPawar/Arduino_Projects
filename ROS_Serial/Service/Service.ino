#include <ros.h>
#include <std_msgs/String.h>
#include <rosserial_arduino/Test.h>
#include <std_srvs/SetBool.h>
#include <rospy_tutorials/AddTwoInts.h>

ros::NodeHandle nh;

void srv_callback(const rospy_tutorials::AddTwoIntsRequest &req, rospy_tutorials::AddTwoIntsResponse &res)
{
  res.sum = 12;
}

ros::ServiceServer<rospy_tutorials::AddTwoIntsRequest,rospy_tutorials::AddTwoIntsResponse> server("add_two_ints",&srv_callback);

void setup(){
  nh.initNode();
  nh.advertiseService(server);
}
void loop(void)
{
  nh.spinOnce();
}
