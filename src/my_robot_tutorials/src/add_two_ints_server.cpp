#include <ros/ros.h>
#include <rospy_tutorials/AddTwoInts.h>

// The service callback will just tell if the callback was succesfull, so the
// return type has to be true or false
bool	handle_add_two_ints(rospy_tutorials::AddTwoInts::Request &req, \
			    rospy_tutorials::AddTwoInts::Response &res)
{
	// First we will collect the data from the request
	int result = req.a + req.b;
	ROS_INFO("%d + %d = %d", (int)req.a, (int)req.b, (int)result);
	res.sum = result;
	return true;
}

int	main(int argc, char **argv)
{
	ros::init(argc, argv, "add_two_ints_server");
	ros::NodeHandle nh;

	// We create a service with the node handle and the following syntax,
	// the advertiseService will advertise that the server is online and
	// if it is it will call the callback function handle_add_two_ints
	ros::ServiceServer server = nh.advertiseService("/add_two_ints", \
		handle_add_two_ints);

	ros::spin();
}
