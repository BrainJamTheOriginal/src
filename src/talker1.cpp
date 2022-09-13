#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include "std_msgs/String.h"
//for sin()
#include <math.h>

class SubscribeAndPublish
{
public:
	SubscribeAndPublish()
	{
	
		pub1 = n1.advertise<std_msgs::Float64>("/end/command", 1000);
		sub1 = n1.subscribe("chatter",1,&SubscribeAndPublish::chatterCallback, this);
	}
	
	void chatterCallback(const std_msgs::String::ConstPtr &msg)
	{
		std_msgs::Float64 msg_to_send;
		double bias = 0;
		double secs =ros::Time::now().toSec();
		//double u = 1;
		//if (directionIs)
		//{
		//	u = -u;
		//}
		double y = sin(secs);
		//u += bias;
		msg_to_send.data = y;
		
		pub1.publish(msg_to_send);

		ROS_INFO("isMoving");
		
		//directionIs = !directionIs;

	}


private:
	ros::NodeHandle n1;
	ros::Publisher pub1;
	ros::Subscriber sub1;

	//bool directionIs = true;

};
int main(int argc, char **argv){
ros::init(argc, argv, "rotate");

SubscribeAndPublish SAPObject;

ros::spin();

return 0;
}
