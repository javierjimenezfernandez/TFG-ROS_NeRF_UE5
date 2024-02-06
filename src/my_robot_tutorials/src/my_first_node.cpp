#include <ros/ros.h>

int	main(int argc, char **argv)
{
	// init para inicializar el nodo
	ros::init(argc, argv, "my_first_cpp_node");
	// NodeHandle para iniciar el nodo
	ros::NodeHandle nh;

	// Macro que funciona como un printf para logear info
	//ROS_INFO("Node has been started");

	// En ROS para cpp no existe una funcion sleep directa 
	// asi ­que hay qe genera primero un objeto duracion
	//ros::Duration(1.0).sleep();

	// Mandamos un Ãºltimo mensaje antes de terminar la
	// ejecucion del programa
	// (si esta fuera la ultima linea de codigo)
	//ROS_INFO("Exit");

	// Creamos una frecuencia de 10Hz para que nuestro nodo
	// se ejecute con esa frecuencia
	ros::Rate rate(10);

	// Mientras el nodo este activo se ejecutara el while
	while (ros::ok())
	{
		ROS_INFO("Hello");
		// Notese que aqui el sleep no es lo mismo
		// que con duration. Si hicieramos sleep normal
		// serian 0.1 segundos mas la ejecucion del
		// programa, sin embargo este sleep tratara de 
		// mantener la ejecucion del programa a 10Hz 
		rate.sleep();
	}
}
