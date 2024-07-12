#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

class	TwistNormalizer
{
	private:
	double			publish_quantity;
	double			publish_rate;
	float			publish_seconds;
	float			linear_scale;
	float			angular_scale;
	geometry_msgs::Twist	normalized_twist;
	ros::Publisher		pub;
	ros::Subscriber		sub;

	public:
	TwistNormalizer(ros::NodeHandle *nh)
	{
		nh->getParam("/cmd_vel_publish_rate", publish_rate);
		nh->getParam("/cmd_vel_publish_seconds", publish_seconds);
		nh->getParam("/normalizer_linear_scale", linear_scale);
		nh->getParam("/normalizer_angular_scale", angular_scale);

		publish_quantity = publish_rate * publish_seconds;

		pub = nh->advertise<geometry_msgs::Twist>("/cmd_vel", 1000);

		sub = nh->subscribe("/UE_twist_value", 1000,
			&TwistNormalizer::callback_receive_msg, this);
	}

	void	callback_receive_msg(const geometry_msgs::Twist &msg)
	{
		ros::Rate rate (publish_rate);

		normalized_twist.linear.x = linear_scale * msg.linear.x;
		normalized_twist.linear.y = linear_scale * msg.linear.y;
		normalized_twist.linear.z = linear_scale * msg.linear.z;

		normalized_twist.angular.x = angular_scale * msg.angular.x;
		normalized_twist.angular.y = angular_scale * msg.angular.y;
		normalized_twist.angular.z = angular_scale * msg.angular.z;

		while (publish_quantity--)
		{
			pub.publish(normalized_twist);
			rate.sleep();
		}
	}
};

int     main(int argc, char **argv)
{
        ros::init(argc, argv, "rosbridge_twist_normalizer");
        ros::NodeHandle nh;
	TwistNormalizer tn = TwistNormalizer(&nh);

        ros::spin();
}
