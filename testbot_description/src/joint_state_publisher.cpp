#include <ros/ros.h>
#include <string>
#include <std_msgs/Header.h>
#include <sensor_msgs/JointState.h>
#include <tf/transform_broadcaster.h>
#include <geometry_msgs/TransformStamped.h>

int main(int argc, char **argv){

        ros::init(argc, argv, "joint_state_pub");
        ros::NodeHandle n;

        ros::Publisher joint_pub = n.advertise<sensor_msgs::JointState>("joint_states", 1);
        tf::TransformBroadcaster broadcaster;
        ros::Rate loop_rate(30);

        // declarations
        const double degree = M_PI/180;
        double angle = 0;

        //robot state
        double zero_pos = 0, zero_vel = 0, zero_effort = 0,
        inc = degree, var = 0,
        speed = 1, wrench = 0, wrench_inc = 1;

        // message declarations
        sensor_msgs::JointState joint_state;
        geometry_msgs::TransformStamped going_around;
        going_around.header.frame_id = "ground";
        going_around.child_frame_id = "Pelvis";

        while (ros::ok()){

            //update joint_state
            joint_state.header.stamp = ros::Time::now();
            joint_state.name.resize(48);
            joint_state.name[0] ="jL5S1_rotx";
            joint_state.name[1] ="jL5S1_roty";
            joint_state.name[2] ="jL4L3_rotx";
            joint_state.name[3] ="jL4L3_roty";
            joint_state.name[4] ="jL1T12_rotx";
            joint_state.name[5] ="jL1T12_roty";
            joint_state.name[6] ="jT9T8_rotx";
            joint_state.name[7] ="jT9T8_roty";
            joint_state.name[8] ="jT9T8_rotz";
            joint_state.name[9] ="jT1C7_rotx";
            joint_state.name[10] ="jT1C7_roty";
            joint_state.name[11] ="jT1C7_rotz";
            joint_state.name[12] ="jC1Head_rotx";
            joint_state.name[13] ="jC1Head_roty";
            joint_state.name[14] ="jRightC7Shoulder_rotx";
            joint_state.name[15] ="jRightShoulder_rotx";
            joint_state.name[16] ="jRightShoulder_roty";
            joint_state.name[17] ="jRightShoulder_rotz";
            joint_state.name[18] ="jRightElbow_roty";
            joint_state.name[19] ="jRightElbow_rotz";
            joint_state.name[20] ="jRightWrist_rotx";
            joint_state.name[21] ="jRightWrist_rotz";
            joint_state.name[22] ="jLeftC7Shoulder_rotx";
            joint_state.name[23] ="jLeftShoulder_rotx";
            joint_state.name[24] ="jLeftShoulder_roty";
            joint_state.name[25] ="jLeftShoulder_rotz";
            joint_state.name[26] ="jLeftElbow_roty";
            joint_state.name[27] ="jLeftElbow_rotz";
            joint_state.name[28] ="jLeftWrist_rotx";
            joint_state.name[29] ="jLeftWrist_rotz";
            joint_state.name[30] ="jRightHip_rotx";
            joint_state.name[31] ="jRightHip_roty";
            joint_state.name[32] ="jRightHip_rotz";
            joint_state.name[33] ="jRightKnee_roty";
            joint_state.name[34] ="jRightKnee_rotz";
            joint_state.name[35] ="jRightAnkle_rotx";
            joint_state.name[36] ="jRightAnkle_roty";
            joint_state.name[37] ="jRightAnkle_rotz";
            joint_state.name[38] ="jRightBallFoot_roty";
            joint_state.name[39] ="jLeftHip_rotx";
            joint_state.name[40] ="jLeftHip_roty";
            joint_state.name[41] ="jLeftHip_rotz";
            joint_state.name[42] ="jLeftKnee_roty";
            joint_state.name[43] ="jLeftKnee_rotz";
            joint_state.name[44] ="jLeftAnkle_rotx";
            joint_state.name[45] ="jLeftAnkle_roty";
            joint_state.name[46] ="jLeftAnkle_rotz";
            joint_state.name[47] ="jLeftBallFoot_roty";

            //joint_state.name[48] ="hjRightHip_roty";

            joint_state.position.resize(48);
            //for(int i=0; i<=47; i++){
            //	joint_state.position[i] = zero_pos;
            //}
            // Create new robot state
            joint_state.position[31] = var;
            var += inc;
            if (var<-0.3 || var>0.3) inc *= -1;


//             joint_state.position[0] = zero_pos;
//             joint_state.position[1] = zero_pos;
//             joint_state.position[2] = zero_pos;
//             joint_state.position[3] = zero_pos;
//             joint_state.position[4] = zero_pos;
//             joint_state.position[5] = zero_pos;
//             joint_state.position[6] = zero_pos;
//             joint_state.position[7] = zero_pos;
//             joint_state.position[8] = zero_pos;
//             joint_state.position[9] = zero_pos;
//             joint_state.position[10] = zero_pos;
//             joint_state.position[11] = zero_pos;
//             joint_state.position[12] = zero_pos;
//             joint_state.position[13] = zero_pos;
//             joint_state.position[14] = zero_pos;
//             joint_state.position[15] = zero_pos;
//             joint_state.position[16] = zero_pos;
//             joint_state.position[17] = zero_pos;
//             joint_state.position[18] = zero_pos;
//             joint_state.position[19] = zero_pos;
//             joint_state.position[20] = zero_pos;
//             joint_state.position[21] = zero_pos;
//             joint_state.position[22] = zero_pos;
//             joint_state.position[23] = zero_pos;
//             joint_state.position[24] = zero_pos;
//             joint_state.position[25] = zero_pos;
//             joint_state.position[26] = zero_pos;
//             joint_state.position[27] = zero_pos;
//             joint_state.position[28] = zero_pos;
//             joint_state.position[29] = zero_pos;
//             joint_state.position[30] = zero_pos;
//             joint_state.position[31] = zero_pos;
//             joint_state.position[32] = zero_pos;
//             joint_state.position[33] = zero_pos;
//             joint_state.position[34] = zero_pos;
//             joint_state.position[35] = zero_pos;
//             joint_state.position[36] = zero_pos;
//             joint_state.position[37] = zero_pos;
//             joint_state.position[38] = zero_pos;
//             joint_state.position[39] = zero_pos;
//             joint_state.position[40] = zero_pos;
//             joint_state.position[41] = zero_pos;
//             joint_state.position[42] = zero_pos;
//             joint_state.position[43] = zero_pos;
//             joint_state.position[44] = zero_pos;
//             joint_state.position[45] = zero_pos;
//             joint_state.position[46] = zero_pos;
//             joint_state.position[47] = zero_pos;

            joint_state.velocity.resize(48);
//             for(int i=0; i<=47; i++){
//                 joint_state.velocity[i] = zero_vel;
//             }

            joint_state.effort.resize(48);
//             for(int i=0; i<=47; i++){
//                 joint_state.effort[i] = zero_effort;
//             }
            joint_state.effort[31] = wrench;
            wrench += wrench_inc;
            if (wrench<-50 || wrench>50) wrench_inc *= -1;

            // Send the joint state
            joint_pub.publish(joint_state);

            // update transform
            // (moving in a circle with radius=2)
            going_around.header.stamp = ros::Time::now();
            going_around.transform.translation.x = cos(angle)*3;
            going_around.transform.translation.y = sin(angle)*3;
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








