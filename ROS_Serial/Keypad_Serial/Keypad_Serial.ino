#include <Keypad.h>
#include<ros.h>
#include<std_msgs/String.h>
#include<std_msgs/Char.h>


const int ROW = 4;
const int COLUMN = 4;

char keys[ROW][COLUMN] = {{'1','2','3','A'},
                          {'4','5','6','B'},
                          {'7','8','9','C'},
                          {'*','0','#','D'}};

byte pin_row[ROW] = {9,8,7,6};
byte pin_column[COLUMN] = {5,4,3,2};


Keypad keypad = Keypad( makeKeymap(keys),pin_row,pin_column,ROW,COLUMN);

ros::NodeHandle nh;
std_msgs::Char char_msg;
ros::Publisher pub("Key_Input",&char_msg);


void setup() 
{
  nh.initNode();
  nh.advertise(pub);
}


void loop() 
{
  char key = keypad.getKey();
  
  if (key)
  {
    char_msg.data = key;
    pub.publish(&char_msg);
  }
  nh.spinOnce();
  delay(1);
  }
   
