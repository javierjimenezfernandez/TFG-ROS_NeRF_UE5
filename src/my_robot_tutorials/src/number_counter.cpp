#include <ros/ros.h>
#include <std_msgs/Int64.h>
#include <std_srvs/SetBool.h>

static std_msgs::Int64 counter;
static ros::Publisher pub;

void	callback_receive_number(const std_msgs::Int64& msg)
{
	ROS_INFO("Message received: %ld", msg.data); 
	counter.data = counter.data + msg.data;
	pub.publish(counter);
}

bool	callback_reset_counter(std_srvs::SetBool::Request &req, \
				  std_srvs::SetBool::Response &res)
{
	if (req.data)
	{
		counter.data = 0;
		res.success = true;
		res.message = "Counter has been successfully reset";
	}
	else
	{
		res.success = false;
		res.message = "Counter has not been reset";
	}	
	return true;
}

int	main(int argc, char **argv)
{
	ros::init(argc, argv, "number_counter");
	ros::NodeHandle nh;

	ros::Subscriber sub = nh.subscribe("/number", \
		1000, callback_receive_number);

	pub = nh.advertise<std_msgs::Int64>("/number_count", 10);

	ros::ServiceServer server = nh.advertiseService("/reset_counter", \
		callback_reset_counter);

	ros::spin();
}
