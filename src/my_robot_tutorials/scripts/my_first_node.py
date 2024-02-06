#!/usr/bin/env python3

import rospy

if __name__ == '__main__':
	# Iniciamos el nodo
	rospy.init_node('my_first_python_node')
	# Logeamos un mensaje
	rospy.loginfo("This node has been started")

	# pausa la ejecucion del programa durante 1s
	#rospy.sleep(1)

	# Manda un mensaje antes de terminar la ejecucion
	# (si fuera la ultima linea de codigo)
	#rospy.loginfo("Exit now")	

	# Definimos rate a 10Hz
	rate = rospy.Rate(10)

	# While the node is not shutdown
	# Usamos el rate para que el programa intente ponerse
	# en pausa de manera que la ejecucion del programa se
	# repita con una frecuencia de 10Hz (0.1s)
	while not rospy.is_shutdown():
		rospy.loginfo("Hello")
		rate.sleep()

