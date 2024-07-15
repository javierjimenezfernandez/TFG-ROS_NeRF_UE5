#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>

class	TwistNormalizer
{
	private:
	long int		publish_quantity;
	double			publish_rate;
	float			publish_seconds;
	float			linear_scale;
	float			angular_scale;
	geometry_msgs::Twist	normalized_twist;
	geometry_msgs::Twist	normalized_odom;
	ros::Publisher		pub_cmd_vel;
	ros::Publisher		pub_ROS_twist;
	ros::Subscriber		sub_UE_twist;
	ros::Subscriber		sub_odom;

	public:
	TwistNormalizer(ros::NodeHandle *nh)
	{
		nh->getParam("/cmd_vel_publish_rate", publish_rate);
		nh->getParam("/cmd_vel_publish_seconds", publish_seconds);
		nh->getParam("/normalizer_linear_scale", linear_scale);
		nh->getParam("/normalizer_angular_scale", angular_scale);

		publish_quantity = publish_rate * publish_seconds;

		pub_cmd_vel = nh->advertise<geometry_msgs::Twist>("/cmd_vel", 1000);
		pub_ROS_twist = nh->advertise<geometry_msgs::Twist>("/ROS_twist_value", 1000);

		sub_UE_twist = nh->subscribe("/UE_twist_value", 1000,
			&TwistNormalizer::callback_receive_UE, this);
		sub_odom = nh->subscribe("/odom", 1000,
                        &TwistNormalizer::callback_receive_arturito, this);
	}

	void	reset_twist(geometry_msgs::Twist &twist)
	{
		twist.linear.x = 0;
		twist.linear.y = 0;
		twist.linear.z = 0;

		twist.angular.x = 0;
		twist.angular.y = 0;
		twist.angular.z = 0;
	}

	void	callback_receive_UE(const geometry_msgs::Twist &msg)
	{
		ros::Rate rate (publish_rate);

		publish_quantity = publish_rate * publish_seconds;

		normalized_twist.linear.x = linear_scale * msg.linear.x;
		normalized_twist.linear.y = linear_scale * msg.linear.y;
		normalized_twist.linear.z = linear_scale * msg.linear.z;

		normalized_twist.angular.x = angular_scale * msg.angular.x;
		normalized_twist.angular.y = angular_scale * msg.angular.y;
		normalized_twist.angular.z = angular_scale * msg.angular.z;

		while (publish_quantity--)
		{
			pub_cmd_vel.publish(normalized_twist);
			rate.sleep();
		}

		reset_twist(normalized_twist);
		pub_cmd_vel.publish(normalized_twist);
	}

	void    callback_receive_arturito(const nav_msgs::Odometry &msg)
        {
		/*normalized_odom.linear.x = msg.twist.twist.linear.x / linear_scale;
		normalized_odom.linear.y = msg.twist.twist.linear.y / linear_scale;
		normalized_odom.linear.z = msg.twist.twist.linear.z / linear_scale;*/

		normalized_odom.linear.x = msg.twist.twist.linear.x;
		normalized_odom.linear.y = msg.twist.twist.linear.y;
		normalized_odom.linear.z = msg.twist.twist.linear.z;

		/*normalized_odom.angular.x = msg.twist.twist.angular.x / angular_scale;
		normalized_odom.angular.y = msg.twist.twist.angular.y / angular_scale;
		normalized_odom.angular.z = msg.twist.twist.angular.z / angular_scale;*/

		normalized_odom.angular.x = msg.twist.twist.angular.x;
		normalized_odom.angular.y = msg.twist.twist.angular.y;
		normalized_odom.angular.z = msg.twist.twist.angular.z;

		pub_ROS_twist.publish(normalized_odom);
        }
};

int     main(int argc, char **argv)
{
        ros::init(argc, argv, "rosbridge_twist_normalizer");
        ros::NodeHandle nh;
	TwistNormalizer tn = TwistNormalizer(&nh);

        ros::spin();
}
