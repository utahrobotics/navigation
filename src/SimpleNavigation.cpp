#include <math.h>
#include <stdio.h>
#include <ros/ros.h>

#include "geometry_msgs/Twist.h"
#include "geometry_msgs/PoseStamped.h"


ros::Publisher steerpub;
ros::Publisher drivepub;

void UpdateNavigation (const geometry_msgs::PoseStamped::ConstPtr& msg) {
    drivepub.publish(command.WheelPower.toMessage());
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "SimpleNav");
    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("goal", 100, UpdateNavigation);

    drivepub = n.advertise<geometry_msgs::Twist.h>("cmd_vel", 100);

    ros::spin();
}
