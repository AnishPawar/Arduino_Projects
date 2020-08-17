#include <Keypad.h>
#include<ros.h>

#include<geometry_msgs/Twist.h>

const int ROW = 4;
const int COLUMN = 4;

char keys[ROW][COLUMN] = {{'1','2','3','A'},
                          {'4','5','6','B'},
                          {'7','8','9','C'},
                          {'*','0','#','D'}};

byte pin_row[ROW] = {2,3,4,5};//{5,4,3,2};
byte pin_column[COLUMN] = {6,7,8,9};//{9,8,7,6};

double forces[7][6] = {{2.0,0.0,0.0,0.0,0.0,0.0},
                       {0.0,0.0,0.0,0.0,0.0,0.0},
                       {0.0,0.0,0.0,0.0,0.0,2.0},
                       {0.0,0.0,0.0,0.0,0.0,0.0},
                       {0.0,0.0,0.0,0.0,0.0,-2.0},
                       {0.0,0.0,0.0,0.0,0.0,0.0},
                       {-2.0,0.0,0.0,0.0,0.0,0.0}};

Keypad keypad = Keypad( makeKeymap(keys),pin_row,pin_column,ROW,COLUMN);

ros::NodeHandle nh;
geometry_msgs::Twist twist_msg;
ros::Publisher pub("/turtle1/cmd_vel",&twist_msg);


void setup() 
{
  nh.initNode();
  nh.advertise(pub);
}


void loop() 
{
  char key = keypad.getKey();
  char

  if (key)
  {
    twist_msg.linear.x = forces[index][0];
    twist_msg.linear.y = forces[index][1];
    twist_msg.linear.z = forces[index][2];

    twist_msg.angular.x = forces[index][3];
    twist_msg.angular.y = forces[index][4];
    twist_msg.angular.z = forces[index][5];
    pub.publish(&twist_msg);
  }

  nh.spinOnce();
  delay(1);
  }
   
