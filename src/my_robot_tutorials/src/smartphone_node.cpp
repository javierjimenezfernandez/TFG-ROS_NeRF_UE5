#include <ros/ros.h>
#include <std_msgs/String.h>

// Message type is a const type and is a String object of std_msgs
void	callback_receive_radio_data(const std_msgs::String& msg)
{
	// We use ROS_INFO the same way as we would use printf
	// Also we convert the msg.data into a C string so we
	// can use it to log info
	ROS_INFO("Message received : %s", msg.data.c_str());
}

int	main(int argc, char **argv)
{
	ros::init(argc, argv, "smartphone");
	ros::NodeHandle nh;

	// We create the Subscriber analogue to the Publisher
	// A Subscriber needs 3 parameters: the topic name,
	// a buffer size (so if the subscriber cannot listen to
	// the topic up to 1000 (bytes?) will be stored, and
	// a callback function
	ros::Subscriber sub = nh.subscribe("/robot_news_radio", \
		1000, callback_receive_radio_data);

	// The ros::spin will keep the node running until we ask
	// it to shutdown
	ros::spin();
}
