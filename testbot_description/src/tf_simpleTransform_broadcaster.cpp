#include <ros/ros.h>
#include <string>
#include <std_msgs/Header.h>
#include <sensor_msgs/JointState.h>
#include <tf/transform_broadcaster.h>
#include <geometry_msgs/TransformStamped.h>


int main(int argc, char **argv){

        ros::init(argc, argv, "tf_simpleTransform_broadcaster");
        ros::NodeHandle n;

        ros::Publisher joint_pub = n.advertise<sensor_msgs::JointState>("joint_states", 1);
        tf::TransformBroadcaster broadcaster;
        ros::Rate loop_rate(30);

        // declarations
        const double degree = M_PI/180;
        double angle = 0;
        //robot state
        double zero_pos = 0, zero_vel = 0, zero_effort = 0,
        inc = degree, varhip = 0, speed = 1, wrench = 0, wrench_inc = 1;

        // message declarations
        sensor_msgs::JointState joint_state;
        geometry_msgs::TransformStamped going_around;
        going_around.header.frame_id = "ground";
        going_around.child_frame_id = "Box";

        while (ros::ok()) {

            //update joint_state
            joint_state.header.stamp = ros::Time::now();
            joint_state.name.resize(16);
            joint_state.name[0] ="RightRotHip_x";
            joint_state.name[1] ="RightRotHip_y";
            joint_state.name[2] ="RightRotHip_z";
            joint_state.name[3] ="RightRotKnee_y";
            joint_state.name[4] ="RightRotKnee_z";
            joint_state.name[5] ="RightRotAnkle_x";
            joint_state.name[6] ="RightRotAnkle_y";
            joint_state.name[7] ="RightRotAnkle_z";
            joint_state.name[8] ="LeftRotHip_x";
            joint_state.name[9] ="LeftRotHip_y";
            joint_state.name[10] ="LeftRotHip_z";
            joint_state.name[11] ="LeftRotKnee_y";
            joint_state.name[12] ="LeftRotKnee_z";
            joint_state.name[13] ="LeftRotAnkle_x";
            joint_state.name[14] ="LeftRotAnkle_y";
            joint_state.name[15] ="LeftRotAnkle_z";


            joint_state.position.resize(16);

            // Create new robot state
            joint_state.position[1] = varhip;

            varhip += inc;
            if (varhip<-0.5 || varhip>0.5) inc *= -1;

            joint_state.velocity.resize(16);
            joint_state.effort.resize(16);

            joint_state.effort[1] = wrench;
            wrench += wrench_inc;
            if (wrench<-50 || wrench>50) wrench_inc *= -1;

            // Send the joint state
            joint_pub.publish(joint_state);

            // update transform
            // (moving in a circle with radius=2)
            going_around.header.stamp = ros::Time::now();
            going_around.transform.translation.x = cos(angle)*2;
            going_around.transform.translation.y = sin(angle)*2;
            going_around.transform.translation.z = 1;
            going_around.transform.rotation = tf::createQuaternionMsgFromYaw(angle+M_PI/2);
            angle += degree/4;

            // send the transform
            broadcaster.sendTransform(going_around);

            // This will adjust as needed per iteration
            loop_rate.sleep();
        }

        return 0;

}