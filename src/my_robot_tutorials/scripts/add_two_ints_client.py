#!/usr/bin/env python3

import rospy
from rospy_tutorials.srv import AddTwoInts

if __name__ == '__main__':
	rospy.init_node("add_two_ints_client")

	# This line will block the execution of the node until the
	# Service is advertised
	rospy.wait_for_service("/add_two_ints")

	# If the client node tries to call the service and there is no
	# service it will rise an exception. We need to catch that exception
	# with the try and except and log it in the except
	try:
		# We create the client with rospy.ServiceProxy, we give the
		# name of the service and we give the type
		add_two_ints = rospy.ServiceProxy("/add_two_ints", AddTwoInts)
		response = add_two_ints(2,6)
		rospy.loginfo("Sum is : " + str(response.sum))
	except rospy.ServiceException as e:
		rospy.logwarn("Service failed: " + str(e))
