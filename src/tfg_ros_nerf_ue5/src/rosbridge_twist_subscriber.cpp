#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

void    callback_receive_msg(const geometry_msgs::Twist &msg)
{
        ROS_INFO("TWIST MESSAGE RECEIVED from UE: \n");
	ROS_INFO("linear: (%f, %f, %f)\n", msg.linear.x, msg.linear.y, msg.linear.z);
	ROS_INFO("angular: (%f, %f, %f)\n", msg.angular.x, msg.angular.y, msg.angular.z);
}

int     main(int argc, char **argv)
{
        ros::init(argc, argv, "rosbridge_twist_subscriber");
        ros::NodeHandle nh;

        ros::Subscriber sub = nh.subscribe("/UE_twist_value", 1000, callback_receive_msg);

        ros::spin();
}
