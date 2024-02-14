#!/usr/bin/env python3

import rospy
from my_robot_msgs.msg import HardwareStatus

if __name__ == '__main__':
	rospy.init_node("hardware_status_publisher")

	# Here we add /my_robot/ before the node name so if in the
	# future we have different robots each one with its own
	# hardware_status we can identify which is each node
	pub = rospy.Publisher("/my_robot/hardware_status", HardwareStatus, queue_size=10)

	rate = rospy.Rate(5)

	while not rospy.is_shutdown():
		msg = HardwareStatus()
		msg.temperature = 45
		msg.are_motors_up = True
		msg.debug_message = "Everything is running well"
		pub.publish(msg)
		rate.sleep()
