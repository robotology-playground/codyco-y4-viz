#include <ros/ros.h>
#include <string>
#include <tf/transform_broadcaster.h>
#include <geometry_msgs/TransformStamped.h>


int main(int argc, char **argv){

    ros::init(argc, argv, "tf_broadcaster");
    ros::NodeHandle n;

    tf::TransformBroadcaster broadcaster;
    ros::Rate loop_rate(30);

    const double degree = M_PI/180;

    // robot state
    double null = 0, w = 1.0;
    double tx_m = -0.000075, tz_m = 0.09681;

    double tx_a = 0.000037, ty_a = -0.079215, tz_a = 0.000367;
    double tx_d = -0.000002, tz_d = -0.40926;
    double tx_e = -0.000373, tz_e = -0.42811;
    double tx_f = 0.13428, tz_f = -0.078689;

    double tx_g = 0.000037, ty_g = 0.079215, tz_g = 0.000367;
    double tx_h = -0.000002, tz_h = -0.40926;
    double tx_i = -0.000373, tz_i = -0.42811;
    double tx_l = 0.13428, tz_l = -0.078689;
    double tx_n = -0.13428, tz_n = 0.078689;

    // message declarations
    geometry_msgs::TransformStamped Pelvis_L5_f1;
    Pelvis_L5_f1.header.frame_id = "Pelvis";
    Pelvis_L5_f1.child_frame_id = "L5_f1";

    geometry_msgs::TransformStamped Pelvis_RightUpperLeg_f1;
    Pelvis_RightUpperLeg_f1.header.frame_id = "Pelvis";
    Pelvis_RightUpperLeg_f1.child_frame_id = "RightUpperLeg_f1";

    geometry_msgs::TransformStamped RightUpperLeg_f1_RightUpperLeg_f2;
    RightUpperLeg_f1_RightUpperLeg_f2.header.frame_id = "RightUpperLeg_f1";
    RightUpperLeg_f1_RightUpperLeg_f2.child_frame_id = "RightUpperLeg_f2";

    geometry_msgs::TransformStamped RightUpperLeg_f2_RightUpperLeg;
    RightUpperLeg_f2_RightUpperLeg.header.frame_id = "RightUpperLeg_f2";
    RightUpperLeg_f2_RightUpperLeg.child_frame_id = "RightUpperLeg";

    geometry_msgs::TransformStamped RightUpperLeg_RightLowerLeg_f1;
    RightUpperLeg_RightLowerLeg_f1.header.frame_id = "RightUpperLeg";
    RightUpperLeg_RightLowerLeg_f1.child_frame_id = "RightLowerLeg_f1";

    geometry_msgs::TransformStamped RightLowerLeg_f1_RightLowerLeg;
    RightLowerLeg_f1_RightLowerLeg.header.frame_id = "RightLowerLeg_f1";
    RightLowerLeg_f1_RightLowerLeg.child_frame_id = "RightLowerLeg";

    geometry_msgs::TransformStamped RightLowerLeg_RightFoot_f1;
    RightLowerLeg_RightFoot_f1.header.frame_id = "RightLowerLeg";
    RightLowerLeg_RightFoot_f1.child_frame_id = "RightFoot_f1";

    geometry_msgs::TransformStamped RightFoot_f1_RightFoot_f2;
    RightFoot_f1_RightFoot_f2.header.frame_id = "RightFoot_f1";
    RightFoot_f1_RightFoot_f2.child_frame_id = "RightFoot_f2";

    geometry_msgs::TransformStamped RightFoot_f2_RightFoot;
    RightFoot_f2_RightFoot.header.frame_id = "RightFoot_f2";
    RightFoot_f2_RightFoot.child_frame_id = "RightFoot";

    geometry_msgs::TransformStamped RightFoot_RightToe;
    RightFoot_RightToe.header.frame_id = "RightFoot";
    RightFoot_RightToe.child_frame_id = "RightToe";

    geometry_msgs::TransformStamped Pelvis_LeftUpperLeg_f1;
    Pelvis_LeftUpperLeg_f1.header.frame_id = "Pelvis";
    Pelvis_LeftUpperLeg_f1.child_frame_id = "LeftUpperLeg_f1";

    geometry_msgs::TransformStamped LeftUpperLeg_f1_LeftUpperLeg_f2;
    LeftUpperLeg_f1_LeftUpperLeg_f2.header.frame_id = "LeftUpperLeg_f1";
    LeftUpperLeg_f1_LeftUpperLeg_f2.child_frame_id = "LeftUpperLeg_f2";

    geometry_msgs::TransformStamped LeftUpperLeg_f2_LeftUpperLeg;
    LeftUpperLeg_f2_LeftUpperLeg.header.frame_id = "LeftUpperLeg_f2";
    LeftUpperLeg_f2_LeftUpperLeg.child_frame_id = "LeftUpperLeg";

    geometry_msgs::TransformStamped LeftUpperLeg_LeftLowerLeg_f1;
    LeftUpperLeg_LeftLowerLeg_f1.header.frame_id = "LeftUpperLeg";
    LeftUpperLeg_LeftLowerLeg_f1.child_frame_id = "LeftLowerLeg_f1";

    geometry_msgs::TransformStamped LeftLowerLeg_f1_LeftLowerLeg;
    LeftLowerLeg_f1_LeftLowerLeg.header.frame_id = "LeftLowerLeg_f1";
    LeftLowerLeg_f1_LeftLowerLeg.child_frame_id = "LeftLowerLeg";

    geometry_msgs::TransformStamped LeftLowerLeg_LeftFoot_f1;
    LeftLowerLeg_LeftFoot_f1.header.frame_id = "LeftLowerLeg";
    LeftLowerLeg_LeftFoot_f1.child_frame_id = "LeftFoot_f1";

    geometry_msgs::TransformStamped LeftFoot_f1_LeftFoot_f2;
    LeftFoot_f1_LeftFoot_f2.header.frame_id = "LeftFoot_f1";
    LeftFoot_f1_LeftFoot_f2.child_frame_id = "LeftFoot_f2";

    geometry_msgs::TransformStamped LeftFoot_f2_LeftFoot;
    LeftFoot_f2_LeftFoot.header.frame_id = "LeftFoot_f2";
    LeftFoot_f2_LeftFoot.child_frame_id = "LeftFoot";

    geometry_msgs::TransformStamped LeftFoot_LeftToe;
    LeftFoot_LeftToe.header.frame_id = "LeftFoot";
    LeftFoot_LeftToe.child_frame_id = "LeftToe";

    while (ros::ok()){

        //update trasform

        Pelvis_L5_f1.header.stamp = ros::Time::now();
        Pelvis_L5_f1.transform.translation.x = tx_m;
        Pelvis_L5_f1.transform.translation.y = null;
        Pelvis_L5_f1.transform.translation.z = tz_m;
        Pelvis_L5_f1.transform.rotation.x = null;
        Pelvis_L5_f1.transform.rotation.y = null;
        Pelvis_L5_f1.transform.rotation.z = null;
        Pelvis_L5_f1.transform.rotation.w = w;

        //Left Leg
        Pelvis_RightUpperLeg_f1.header.stamp = ros::Time::now();
        Pelvis_RightUpperLeg_f1.transform.translation.x = tx_a;
        Pelvis_RightUpperLeg_f1.transform.translation.y = ty_a;
        Pelvis_RightUpperLeg_f1.transform.translation.z = tz_a;
        Pelvis_RightUpperLeg_f1.transform.rotation.x = null;
        Pelvis_RightUpperLeg_f1.transform.rotation.y = null;
        Pelvis_RightUpperLeg_f1.transform.rotation.z = null;
        Pelvis_RightUpperLeg_f1.transform.rotation.w = w;

        RightUpperLeg_f1_RightUpperLeg_f2.header.stamp = ros::Time::now();
        RightUpperLeg_f1_RightUpperLeg_f2.transform.translation.x = null;
        RightUpperLeg_f1_RightUpperLeg_f2.transform.translation.y = null;
        RightUpperLeg_f1_RightUpperLeg_f2.transform.translation.z = null;
        RightUpperLeg_f1_RightUpperLeg_f2.transform.rotation.x = null;
        RightUpperLeg_f1_RightUpperLeg_f2.transform.rotation.y = null;
        RightUpperLeg_f1_RightUpperLeg_f2.transform.rotation.z = null;
        RightUpperLeg_f1_RightUpperLeg_f2.transform.rotation.w = w;

        RightUpperLeg_f2_RightUpperLeg.header.stamp = ros::Time::now();
        RightUpperLeg_f2_RightUpperLeg.transform.translation.x = null;
        RightUpperLeg_f2_RightUpperLeg.transform.translation.y = null;
        RightUpperLeg_f2_RightUpperLeg.transform.translation.z = null;
        RightUpperLeg_f2_RightUpperLeg.transform.rotation.x = null;
        RightUpperLeg_f2_RightUpperLeg.transform.rotation.y = null;
        RightUpperLeg_f2_RightUpperLeg.transform.rotation.z = null;
        RightUpperLeg_f2_RightUpperLeg.transform.rotation.w = w;

        RightUpperLeg_RightLowerLeg_f1.header.stamp = ros::Time::now();
        RightUpperLeg_RightLowerLeg_f1.transform.translation.x = tx_d;
        RightUpperLeg_RightLowerLeg_f1.transform.translation.y = null;
        RightUpperLeg_RightLowerLeg_f1.transform.translation.z = tz_d;
        RightUpperLeg_RightLowerLeg_f1.transform.rotation.x = null;
        RightUpperLeg_RightLowerLeg_f1.transform.rotation.y = null;
        RightUpperLeg_RightLowerLeg_f1.transform.rotation.z = null;
        RightUpperLeg_RightLowerLeg_f1.transform.rotation.w = w;

        RightLowerLeg_f1_RightLowerLeg.header.stamp = ros::Time::now();
        RightLowerLeg_f1_RightLowerLeg.transform.translation.x = null;
        RightLowerLeg_f1_RightLowerLeg.transform.translation.y = null;
        RightLowerLeg_f1_RightLowerLeg.transform.translation.z = null;
        RightLowerLeg_f1_RightLowerLeg.transform.rotation.x = null;
        RightLowerLeg_f1_RightLowerLeg.transform.rotation.y = null;
        RightLowerLeg_f1_RightLowerLeg.transform.rotation.z = null;
        RightLowerLeg_f1_RightLowerLeg.transform.rotation.w = w;

        RightLowerLeg_RightFoot_f1.header.stamp = ros::Time::now();
        RightLowerLeg_RightFoot_f1.transform.translation.x = tx_e;
        RightLowerLeg_RightFoot_f1.transform.translation.y = null;
        RightLowerLeg_RightFoot_f1.transform.translation.z = tz_e;
        RightLowerLeg_RightFoot_f1.transform.rotation.x = null;
        RightLowerLeg_RightFoot_f1.transform.rotation.y = null;
        RightLowerLeg_RightFoot_f1.transform.rotation.z = null;
        RightLowerLeg_RightFoot_f1.transform.rotation.w = w;

        RightFoot_f1_RightFoot_f2.header.stamp = ros::Time::now();
        RightFoot_f1_RightFoot_f2.transform.translation.x = null;
        RightFoot_f1_RightFoot_f2.transform.translation.y = null;
        RightFoot_f1_RightFoot_f2.transform.translation.z = null;
        RightFoot_f1_RightFoot_f2.transform.rotation.x = null;
        RightFoot_f1_RightFoot_f2.transform.rotation.y = null;
        RightFoot_f1_RightFoot_f2.transform.rotation.z = null;
        RightFoot_f1_RightFoot_f2.transform.rotation.w = w;

        RightFoot_f2_RightFoot.header.stamp = ros::Time::now();
        RightFoot_f2_RightFoot.transform.translation.x = null;
        RightFoot_f2_RightFoot.transform.translation.y = null;
        RightFoot_f2_RightFoot.transform.translation.z = null;
        RightFoot_f2_RightFoot.transform.rotation.x = null;
        RightFoot_f2_RightFoot.transform.rotation.y = null;
        RightFoot_f2_RightFoot.transform.rotation.z = null;
        RightFoot_f2_RightFoot.transform.rotation.w = w;

        RightFoot_RightToe.header.stamp = ros::Time::now();
        RightFoot_RightToe.transform.translation.x = tx_f;
        RightFoot_RightToe.transform.translation.y = null;
        RightFoot_RightToe.transform.translation.z = tz_f;
        RightFoot_RightToe.transform.rotation.x = null;
        RightFoot_RightToe.transform.rotation.y = null;
        RightFoot_RightToe.transform.rotation.z = null;
        RightFoot_RightToe.transform.rotation.w = w;

        //Left Leg
        Pelvis_LeftUpperLeg_f1.header.stamp = ros::Time::now();
        Pelvis_LeftUpperLeg_f1.transform.translation.x = tx_g;
        Pelvis_LeftUpperLeg_f1.transform.translation.y = ty_g;
        Pelvis_LeftUpperLeg_f1.transform.translation.z = tz_g;
        Pelvis_LeftUpperLeg_f1.transform.rotation.x = null;
        Pelvis_LeftUpperLeg_f1.transform.rotation.y = null;
        Pelvis_LeftUpperLeg_f1.transform.rotation.z = null;
        Pelvis_LeftUpperLeg_f1.transform.rotation.w = w;

        LeftUpperLeg_f1_LeftUpperLeg_f2.header.stamp = ros::Time::now();
        LeftUpperLeg_f1_LeftUpperLeg_f2.transform.translation.x = null;
        LeftUpperLeg_f1_LeftUpperLeg_f2.transform.translation.y = null;
        LeftUpperLeg_f1_LeftUpperLeg_f2.transform.translation.z = null;
        LeftUpperLeg_f1_LeftUpperLeg_f2.transform.rotation.x = null;
        LeftUpperLeg_f1_LeftUpperLeg_f2.transform.rotation.y = null;
        LeftUpperLeg_f1_LeftUpperLeg_f2.transform.rotation.z = null;
        LeftUpperLeg_f1_LeftUpperLeg_f2.transform.rotation.w = w;

        LeftUpperLeg_f2_LeftUpperLeg.header.stamp = ros::Time::now();
        LeftUpperLeg_f2_LeftUpperLeg.transform.translation.x = null;
        LeftUpperLeg_f2_LeftUpperLeg.transform.translation.y = null;
        LeftUpperLeg_f2_LeftUpperLeg.transform.translation.z = null;
        LeftUpperLeg_f2_LeftUpperLeg.transform.rotation.x = null;
        LeftUpperLeg_f2_LeftUpperLeg.transform.rotation.y = null;
        LeftUpperLeg_f2_LeftUpperLeg.transform.rotation.z = null;
        LeftUpperLeg_f2_LeftUpperLeg.transform.rotation.w = w;

        LeftUpperLeg_LeftLowerLeg_f1.header.stamp = ros::Time::now();
        LeftUpperLeg_LeftLowerLeg_f1.transform.translation.x = tx_h;
        LeftUpperLeg_LeftLowerLeg_f1.transform.translation.y = null;
        LeftUpperLeg_LeftLowerLeg_f1.transform.translation.z = tz_h;
        LeftUpperLeg_LeftLowerLeg_f1.transform.rotation.x = null;
        LeftUpperLeg_LeftLowerLeg_f1.transform.rotation.y = null;
        LeftUpperLeg_LeftLowerLeg_f1.transform.rotation.z = null;
        LeftUpperLeg_LeftLowerLeg_f1.transform.rotation.w = w;

        LeftLowerLeg_f1_LeftLowerLeg.header.stamp = ros::Time::now();
        LeftLowerLeg_f1_LeftLowerLeg.transform.translation.x = null;
        LeftLowerLeg_f1_LeftLowerLeg.transform.translation.y = null;
        LeftLowerLeg_f1_LeftLowerLeg.transform.translation.z = null;
        LeftLowerLeg_f1_LeftLowerLeg.transform.rotation.x = null;
        LeftLowerLeg_f1_LeftLowerLeg.transform.rotation.y = null;
        LeftLowerLeg_f1_LeftLowerLeg.transform.rotation.z = null;
        LeftLowerLeg_f1_LeftLowerLeg.transform.rotation.w = w;

        LeftLowerLeg_LeftFoot_f1.header.stamp = ros::Time::now();
        LeftLowerLeg_LeftFoot_f1.transform.translation.x = tx_i;
        LeftLowerLeg_LeftFoot_f1.transform.translation.y = null;
        LeftLowerLeg_LeftFoot_f1.transform.translation.z = tz_i;
        LeftLowerLeg_LeftFoot_f1.transform.rotation.x = null;
        LeftLowerLeg_LeftFoot_f1.transform.rotation.y = null;
        LeftLowerLeg_LeftFoot_f1.transform.rotation.z = null;
        LeftLowerLeg_LeftFoot_f1.transform.rotation.w = w;

        LeftFoot_f1_LeftFoot_f2.header.stamp = ros::Time::now();
        LeftFoot_f1_LeftFoot_f2.transform.translation.x = null;
        LeftFoot_f1_LeftFoot_f2.transform.translation.y = null;
        LeftFoot_f1_LeftFoot_f2.transform.translation.z = null;
        LeftFoot_f1_LeftFoot_f2.transform.rotation.x = null;
        LeftFoot_f1_LeftFoot_f2.transform.rotation.y = null;
        LeftFoot_f1_LeftFoot_f2.transform.rotation.z = null;
        LeftFoot_f1_LeftFoot_f2.transform.rotation.w = w;

        LeftFoot_f2_LeftFoot.header.stamp = ros::Time::now();
        LeftFoot_f2_LeftFoot.transform.translation.x = null;
        LeftFoot_f2_LeftFoot.transform.translation.y = null;
        LeftFoot_f2_LeftFoot.transform.translation.z = null;
        LeftFoot_f2_LeftFoot.transform.rotation.x = null;
        LeftFoot_f2_LeftFoot.transform.rotation.y = null;
        LeftFoot_f2_LeftFoot.transform.rotation.z = null;
        LeftFoot_f2_LeftFoot.transform.rotation.w = w;

        LeftFoot_LeftToe.header.stamp = ros::Time::now();
        LeftFoot_LeftToe.transform.translation.x = tx_l;
        LeftFoot_LeftToe.transform.translation.y = null;
        LeftFoot_LeftToe.transform.translation.z = tz_l;
        LeftFoot_LeftToe.transform.rotation.x = null;
        LeftFoot_LeftToe.transform.rotation.y = null;
        LeftFoot_LeftToe.transform.rotation.z = null;
        LeftFoot_LeftToe.transform.rotation.w = w;

        //send transform
        //broadcaster.sendTransform(Pelvis_RightUpperLeg_f1);
        broadcaster.sendTransform(RightUpperLeg_f1_RightUpperLeg_f2);
        broadcaster.sendTransform(RightUpperLeg_f2_RightUpperLeg);
        broadcaster.sendTransform(RightUpperLeg_RightLowerLeg_f1);
        broadcaster.sendTransform(RightLowerLeg_f1_RightLowerLeg);
        broadcaster.sendTransform(RightLowerLeg_RightFoot_f1);
        broadcaster.sendTransform(RightFoot_f1_RightFoot_f2);
        broadcaster.sendTransform(RightFoot_f2_RightFoot);
        broadcaster.sendTransform(RightFoot_RightToe);

        broadcaster.sendTransform(Pelvis_LeftUpperLeg_f1);
        broadcaster.sendTransform(LeftUpperLeg_f1_LeftUpperLeg_f2);
        broadcaster.sendTransform(LeftUpperLeg_f2_LeftUpperLeg);
        broadcaster.sendTransform(LeftUpperLeg_LeftLowerLeg_f1);
        broadcaster.sendTransform(LeftLowerLeg_f1_LeftLowerLeg);
        broadcaster.sendTransform(LeftLowerLeg_LeftFoot_f1);
        broadcaster.sendTransform(LeftFoot_f1_LeftFoot_f2);
        broadcaster.sendTransform(LeftFoot_f2_LeftFoot);
        broadcaster.sendTransform(LeftFoot_LeftToe);

        // This will adjust as needed per iteration
        loop_rate.sleep();
      }
    return 0;
  }
