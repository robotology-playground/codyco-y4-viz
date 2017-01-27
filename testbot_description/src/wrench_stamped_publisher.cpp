#include <ros/ros.h>
#include <std_msgs/Header.h>
#include <std_msgs/String.h>
#include <geometry_msgs/WrenchStamped.h>

struct wrench {
    double Fx;
    double Fy;
    double Fz;
    double Mx;
    double My;
    double Mz;
};

int main(int argc, char **argv){

    ros::init(argc, argv, "wrench_stamped_publisher");
    ros::NodeHandle n;

    ros::Publisher wrench_pub = n.advertise<geometry_msgs::WrenchStamped>("wrench_stamped", 1);
    ros::Rate loop_rate(30);

    // message declarations
    geometry_msgs::WrenchStamped wrenchMsg;
    ros::param::param<std::string>("~frame_id", wrenchMsg.header.frame_id, "LeftFoot");
    //wrenchMsg.header.frame_id="wrench_stamped_frame_id";

    double null_F = 0, null_M = 0;
    wrench msgStream;

    while (ros::ok()){

        msgStream.Fx = 0.5;
        msgStream.Fy = 0.5;
        msgStream.Fz = 1;
        msgStream.Mx = 0.5;
        msgStream.My = 0.5;
        msgStream.Mz = -1.1;

        //msg.stream = getdata();

        //compose WrenchStamped Msg
        wrenchMsg.header.stamp = ros::Time::now();
        wrenchMsg.wrench.force.x = msgStream.Fx;
        wrenchMsg.wrench.force.y = msgStream.Fy;
        wrenchMsg.wrench.force.z = msgStream.Fz;
        wrenchMsg.wrench.torque.x = msgStream.Mx;
        wrenchMsg.wrench.torque.y = msgStream.My;
        wrenchMsg.wrench.torque.z = msgStream.Mz;
        wrench_pub.publish(wrenchMsg);

        // This will adjust as needed per iteration
        loop_rate.sleep();
    }
    return 0;
}

