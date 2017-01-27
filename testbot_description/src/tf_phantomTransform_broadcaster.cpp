#include <ros/ros.h>
#include <string>
#include <std_msgs/Header.h>
#include <sensor_msgs/JointState.h>
#include <tf/transform_broadcaster.h>
#include <geometry_msgs/TransformStamped.h>


int main(int argc, char **argv){

    ros::init(argc, argv, "tf_phantomTransform_broadcaster");
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
    going_around.child_frame_id = "bacino";

    while (ros::ok()) {

        //update joint_state
        joint_state.header.stamp = ros::Time::now();
        joint_state.name.resize(49);
        joint_state.name[0] ="tinc";
        joint_state.name[1] ="Lomb5Sac1_x";
        joint_state.name[2] ="Lomb5Sac1_y";
        joint_state.name[3] ="Lomb4Lomb3_x";
        joint_state.name[4] ="Lomb4Lomb3_y";
        joint_state.name[5] ="Lomb1Tor12_x";
        joint_state.name[6] ="Lomb1Tor12_y";
        joint_state.name[7] ="Tor9Tor8_x";
        joint_state.name[8] ="Tor9Tor8_y";
        joint_state.name[9] ="Tor9Tor8_z";
        joint_state.name[10] ="Tor1Cer7_x";
        joint_state.name[11] ="Tor1Cer7_y";
        joint_state.name[12] ="Tor1Cer7_z";
        joint_state.name[13] ="Cer1Testa_x";
        joint_state.name[14] ="Cer1Testa_y";
        joint_state.name[15] ="Cer7SpallaDestra_x";
        joint_state.name[16] ="SpallaDestra_x";
        joint_state.name[17] ="SpallaDestra_y";
        joint_state.name[18] ="SpallaDestra_z";
        joint_state.name[19] ="GomitoDestro_y";
        joint_state.name[20] ="GomitoDestro_z";
        joint_state.name[21] ="PolsoDestro_x";
        joint_state.name[22] ="PolsoDestro_z";
        joint_state.name[23] ="Cer7SpallaSinistra_x";
        joint_state.name[24] ="SpallaSinistra_x";
        joint_state.name[25] ="SpallaSinistra_y";
        joint_state.name[26] ="SpallaSinistra_z";
        joint_state.name[27] ="GomitoSinistro_y";
        joint_state.name[28] ="GomitoSinistro_z";
        joint_state.name[29] ="PolsoSinistro_x";
        joint_state.name[30] ="PolsoSinistro_z";
        joint_state.name[31] ="AncaDestra_x";
        joint_state.name[32] ="AncaDestra_y";
        joint_state.name[33] ="AncaDestra_z";
        joint_state.name[34] ="GinocchioDestro_y";
        joint_state.name[35] ="GinocchioDestro_z";
        joint_state.name[36] ="CavigliaDestra_x";
        joint_state.name[37] ="CavigliaDestra_y";
        joint_state.name[38] ="CavigliaDestra_z";
        joint_state.name[39] ="TarsoDestro_y";
        joint_state.name[40] ="AncaSinistra_x";
        joint_state.name[41] ="AncaSinistra_y";
        joint_state.name[42] ="AncaSinistra_z";
        joint_state.name[43] ="GinocchioSinistro_y";
        joint_state.name[44] ="GinocchioSinistro_z";
        joint_state.name[45] ="CavigliaSinistra_x";
        joint_state.name[46] ="CavigliaSinistra_y";
        joint_state.name[47] ="CavigliaSinistra_z";
        joint_state.name[48] ="TarsoSinistro_y";

        joint_state.position.resize(49);

        // Create new robot state
        //             joint_state.position[1] = varhip;

        //             varhip += inc;
        //             if (varhip<-0.5 || varhip>0.5) inc *= -1;

        joint_state.velocity.resize(49);
        joint_state.effort.resize(49);

        joint_state.effort[32] = wrench;
        wrench += wrench_inc;
        if (wrench<-50 || wrench>50) wrench_inc *= -1;

        // Send the joint state
        joint_pub.publish(joint_state);

        // update transform
        // (moving in a circle with radius=2)
        going_around.header.stamp = ros::Time::now();
        going_around.transform.translation.x = cos(angle)*4;
        going_around.transform.translation.y = sin(angle)*4;
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