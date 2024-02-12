#!/usr/bin/env python3

import rospy
# Service types libraries have the .svr extension
from rospy_tutorials.srv import AddTwoInts

def handle_add_two_ints(req):
	# Please read ROS Wiki about AddTwoInts Service type to see
	# what contains the variable
	result = req.a + req.b
	rospy.loginfo("Sum of " + str(req.a) + " and " + str(req.b) + " is " + str(result))
	return result

if __name__ == '__main__':
	rospy.init_node("add_two_ints_sever")
	rospy.loginfo("Add two ints server node created")

	# We create a service and give it a name, the most appropriate
	# is to start service names with a verb, because they are actions.
	# Then we need a message type for the service, the definition of the
	# service types include the type of the request and below the type 
	# of the answer (look for it in the ROS Wiki)
	# Last we need to add a callback
	service = rospy.Service("/add_two_ints", AddTwoInts, handle_add_two_ints)
	rospy.loginfo("Service server has been started")

	# This will keep the server alive all the node live
	rospy.spin()

