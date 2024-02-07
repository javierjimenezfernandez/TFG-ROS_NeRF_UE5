#!/usr/bin/env python3

import rospy
from std_msgs.msg import String

if __name__ == '__main__':

	# We give our node a name, which is the same
	# as the file name, and it's ok in python scropts
	# the anonymous argument is optional, but it gives the
	# possibility that 2 nodes with the same name exist
	# because it adds some random numbers at the end of its name
	rospy.init_node('robot_news_radio_transmitter', anonymous=True)

	# We create a publisher using the Publisher class 
	# inside rospy. 1st we give a name to the topic and
	# then a message type. We will use the message types
	# provided by the std_msgs dependancy that we used
	# when we created the package (see ROS Wiki).
	# We will use String type that contains just string
	# data.
	# Last thing we need to add is a queue size (~buffer)
	pub = rospy.Publisher("/robot_news_radio", String, queue_size=10)

	# We define a rate of 2Hz
	rate = rospy.Rate(2)

	# Now let's publish some data
	while not rospy.is_shutdown():
		msg = String()
		# From ROS Wiki: in String message we have data
		msg.data = "Hi, this is J from the Robot News Radio !"
		# We publish the message
		pub.publish(msg)
		rate.sleep()

	# To ensure we see that the node was stopped when we make 
	# rosnode kill, we log a message after the loop
	rospy.loginfo("Node was stopped")
