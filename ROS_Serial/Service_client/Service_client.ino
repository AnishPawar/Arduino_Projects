#include <ros.h>
#include <rospy_tutorials/AddTwoInts.h>
#include <gazebo_msgs/ApplyJointEffort.h>
//#include <service_client.h>


ros::NodeHandle nh;
//Initialising service client
ros::ServiceClient<rospy_tutorials::AddTwoInts::Request, rospy_tutorials::AddTwoInts::Response> client("add_test_srv");

void setup() 
{
  nh.initNode();
  nh.serviceClient(client);
  nh.loginfo("Ready!");

}

void loop() 
{
  //Defining requests and responses  
  rospy_tutorials::AddTwoInts::Request req;
  rospy_tutorials::AddTwoInts::Response res;

  rospy_tutorials::AddTwoInts srv;
  
  req.a = 1;
  req.b = 3;

//  Publishing a request to the server
  client.call(req,res);
  
  
  nh.spinOnce();
  delay(1);

}
