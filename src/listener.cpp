
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"


void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}
geometry_msgs::Twist twist;

void TwistCallback(const geometry_msgs::Twist::ConstPtr& rcv_msg){
	twist.linear.x = rcv_msg->linear.x; // throttle
	twist.linear.y = rcv_msg->linear.y; // braking
	twist.angular.z = rcv_msg->angular.z; // steering
	
	ROS_INFO("throttle: [%f]", (twist.linear.x));
    ROS_INFO("braking: [%f]", (twist.linear.y));
    ROS_INFO("steering: [%f]",(twist.angular.z));
	std::cout << "\n";
}

int main(int argc, char **argv)
{
  std::cout << "TEST";
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;

  ros::Subscriber twist_sub = n.subscribe("avt_341/cmd_vel",1,TwistCallback);

  ros::spin();
  return 0;
}
// %EndTag(FULLTEXT)%
