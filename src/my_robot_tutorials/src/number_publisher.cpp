#include <ros/ros.h>
#include <std_msgs/Int64.h>

int	main(int argc, char **argv)
{
	ros::init(argc, argv, "number_publisher");
	ros::NodeHandle nh;

	ros::Publisher pub = nh.advertise<std_msgs::Int64>("/number", 10);

	// to get a parameter from the parameter server first you need to 
	// create a varible to store it
	double publish_frequency;

	// then use the corresponding method of the NodeHandle to get the param
	// you have to give the name of the param and where to store it
	nh.getParam("/number_publish_frequency", publish_frequency);
	ros::Rate rate (publish_frequency);

	int number;
	nh.getParam("/number_to_publish", number);

	// to set the value of an existing param or to create a new one use 
	// this call
	nh.setParam("/just_another_param", "Bye");

	while(ros::ok())
	{
		std_msgs::Int64 msg;
		msg.data = number;
		pub.publish(msg);
		rate.sleep();
	}
}
