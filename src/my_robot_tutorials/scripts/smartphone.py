#!/usr/bin/env python3

import rospy
from std_msgs.msg import String

def callback_receive_radio_data(msg):
	rospy.loginfo("Message received : ")
	rospy.loginfo(msg)

if __name__ == '__main__':

	rospy.init_node('smartphone')

	# The creattion of the subscriber is analogue to
	# the Publisher. Both must share the same topic 
	# name and type for the communication to work
	# In Publishers we needed a queue_size, here we
	# need to give a callback function that we have to
	# create previously
	sub = rospy.Subscriber("/robot_news_radio", String, callback_receive_radio_data)

	# This will keep the script running until the node
	# is stoppped
	rospy.spin()
