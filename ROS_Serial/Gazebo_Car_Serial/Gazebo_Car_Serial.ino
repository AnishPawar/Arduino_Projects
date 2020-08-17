#include <Keypad.h>

//Serial Gazebo Car Simulation
#include<ros.h>
#include<gazebo_msgs/ApplyJointEffort.h>

//Keypad Setup
const int ROW = 4; 
const int COLUMN = 4;

char keys[ROW][COLUMN] = {{'1','2','3','A'},
                          {'4','5','6','B'},
                          {'7','8','9','C'},
                          {'*','0','#','D'}};
byte pin_row[ROW] = {2,3,4,5};
byte pin_column[COLUMN] = {6,7,8,9};

Keypad keypad = Keypad(makeKeymap(keys),pin_row,pin_column,ROW,COLUMN);

//Force Values
float force_values[7] = {-0.5,0.0,-0.01,0.0,0.01,0.0,0.5};
char joint_names[7][10] = {"Engine","Engine","Steering","Steering","Steering","Steering","Engine"};



//ROS Setup
ros::NodeHandle nh;
ros::ServiceClient<gazebo_msgs::ApplyJointEffort::Request,gazebo_msgs::ApplyJointEffort::Response>client("/gazebo/apply_joint_effort");


void setup() {
nh.initNode();
nh.serviceClient(client);
}

void loop() {
  //Defining Requests and Responses  
  gazebo_msgs::ApplyJointEffort::Request req;
  gazebo_msgs::ApplyJointEffort::Response res;
  char key = keypad.getKey();
  int index = key-50;
  if (key)
  {
    req.joint_name = joint_names[index];
    req.effort = force_values[index];
    req.start_time = nh.now();
    req.duration = ros::Duration(1,1);
    client.call(req,res);
    }
    nh.spinOnce();
}                 
