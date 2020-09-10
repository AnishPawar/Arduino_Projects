#include <ros.h>
#include <sensor_msgs/LaserScan.h>

ros::NodeHandle nh;

// Laser Scan
sensor_msgs::LaserScan lidar_msg;
ros::Publisher lidar_pub("/laser_scan", &lidar_msg);
float ranges[10] = {0};
float intensities[10] = {0};

void setup()
{  
  // Initialize ROS node handle, advertise and subscribe the topics
  nh.initNode();
  nh.getHardware()->setBaud(57600);
  nh.advertise(lidar_pub);

  // Set LaserScan Definition
  lidar_msg.header.frame_id = "lidar";
  lidar_msg.angle_min = 0.0;               // start angle of the scan [rad]
  lidar_msg.angle_max = 3.14*2;            // end angle of the scan [rad]
  lidar_msg.angle_increment = 3.14*2/360;  // angular distance between measurements [rad]
  lidar_msg.range_min = 0.3;               // minimum range value [m]
  lidar_msg.range_max = 50.0;                // maximum range value [m]
}


void loop(){

  // simple loop to generate values
  for (int i=0 ; i<10 ; ++i){
    ranges[i] = 1.0*i;
  }

  lidar_msg.ranges = ranges;
  lidar_msg.header.stamp = nh.now();
  lidar_pub.publish(&lidar_msg);
  nh.spinOnce();

}
