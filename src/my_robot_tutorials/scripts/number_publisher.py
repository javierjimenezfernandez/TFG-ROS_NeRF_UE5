#!/usr/bin/env python3

import rospy
from std_msgs.msg import Int64

if __name__ == '__main__':
	rospy.init_node("number_publisher")

	pub = rospy.Publisher("/number", Int64, queue_size=10)

	# to get a parameter from the parameter server use this call
	publish_frequency = rospy.get_param("/number_publish_frequency")
	rate = rospy.Rate(publish_frequency)

	number = rospy.get_param("/number_to_publish")

	# to set an existing or to add a parameter to the parameter 
	# server use this call
	rospy.set_param("/another_param", "Hello")

	while not rospy.is_shutdown():
		msg = Int64()
		msg.data = number
		pub.publish(msg)
		rate.sleep()
