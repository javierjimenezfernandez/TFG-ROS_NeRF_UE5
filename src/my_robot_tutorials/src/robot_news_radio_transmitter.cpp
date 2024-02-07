#include <ros/ros.h>
#include <std_msgs/String.h>

int	main(int argc, char **argv)
{
	// We initialize the node with its name, and we give an
	// optional argument to make it anonymous, this means
	// a set of random numbers will be added at the end
	// of the name when the new node is run avoiding naming 
	// conflict and so allowing several versions of the same 
	// node to work at the same time
	ros::init(argc, argv, "robot_news_radio_transmitter", \
		ros::init_options::AnonymousName);
	ros::NodeHandle nh;

	// We create a ros Publisher, and the way to create it is
	// through node handler. We need to give it the message type,
	// the topic name and the queue size
	ros::Publisher pub = nh.advertise<std_msgs::String>("/robot_news_radio", 10);

	// We create the rate at 3Hz
	ros::Rate rate(3);

	while (ros::ok())
	{
		// We create the message
		std_msgs::String msg;
		// Wee add the data field
		msg.data = "Hi, this is LLei from the Robot News Radio";
		// We pulish the message
		pub.publish(msg);
		rate.sleep();
	}
}
