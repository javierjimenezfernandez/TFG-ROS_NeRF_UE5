#include <ros/ros.h>
#include <rospy_tutorials/AddTwoInts.h>

int	main(int argc, char **argv)
{
	ros::init(argc, argv, "add_two_nodes_client", \
		ros::init_options::AnonymousName);
	ros::NodeHandle nh;

	// We create the client node with the following syntax. We create a client
	// ServiceClient object, then we use the nh serviceClient and specify the
	// type rospy_tutorials::AddTwoInts object type, finally we give the service name
	ros::ServiceClient client = \
		nh.serviceClient<rospy_tutorials::AddTwoInts>("/add_two_ints");

	// We create the srv object, and we need to fill the request inside the object
	// (please see the ROS Wiki for AddTwoInts Service)
	rospy_tutorials::AddTwoInts srv;
	srv.request.a = 12;
	srv.request.b = 5;

	// This function will call the server. The service server will receive the srv
	// object with the request. It will return true or false depending on if the
	// service call is successful or not. Also the response will be added inside the
	// srv object. So we just need to check if client call return true
	if (client.call(srv))
	{
		ROS_INFO("Returned sum is %d", (int)srv.response.sum);
	}
	else
	{
		ROS_WARN("Service call failed");
	}
}
