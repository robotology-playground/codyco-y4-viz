# testbot_description
Ros package to visualize robot and the applied effort and wrenches in rviz.

## Usage

* Clone this repository on your computer:
```
cd github
git clone https://github.com/robotology-playground/codyco-y4-viz
```
* Make sure you have ros installed on your computer.
* If you do not have a workspace for catkin, create one following the [tutorial] (http://wiki.ros.org/catkin/Tutorials/create_a_workspace) in ros documentation;
* Move to the src folder in the catkin workspace you have created and copy the testbot_description folder from the codyco-y4-viz repository cloned:
```
cd ~/catkin_ws/src
cp -r ~/github/codyco-y4-viz/testbot_description/ .
```
* Move to the catkin_ws folder and run catkin_make:
```
cd ~/catkin_ws
catkin_make
```
* In a new terminal launch roscore:
```
roscore
```
* In a new terminal launch rviz:
```
rosrun rviz rviz
```
* Move to the testbot_description folder:
```
cd ~/catkin_ws/src/testbot_description
```
* In a new terminal run the launch file associated to the urdf model which you want to visualize (we take as an example the XSensURDF.urdf file):
```
roslaunch testbot_description displayRobot.launch  model:=urdf/XSensURDF.urdf
```
* In rviz set the *FixedFrame* to ground
* In rviz select "Add" and choose from "By display type" the option **RobotModel** in the rviz folder. Once the robot model is added in the field *Robot Description* add a "prefix" before robot_description as:
```
robot/robot_description
```
(the prefix is the "ns" value associated to the field **group** that you can find in the launch file) The robot state and transforms are set in the joint_state_publisher.cpp file that can be found in the /testbot_description/src folder.
* **Display Effort** - select "Add" and choose from "By topic" the option **Effort** in the /robot/joint_states folder. Once the effort are added in the field *Robot Description* add a "prefix" as before and in the field **Topic** select "/robot/joint_states". The efforts displayed are the ones set in the joint_state_publisher.cpp file that can be found in the /testbot_description/src folder. This file is runned through the diplayRobot.launch.
* **Display Wrenches** - select "Add" and choose from "By topic" the option **WrenchStamped** in the /robot/wrench_stamped folder. Once the wrenches are added in the field **Topic** select "/robot/wrench_stamped". The efforts displayed are the ones set in the wrench_stamped_publisher.cpp file that can be found in the /testbot_description/src folder. This file is runned through the diplayRobot.launch.

## Launch files, models and publishers association:
**Specific:**
* displayRobot.launch --> allow to display XSensURDF.urdf/XSensURDF.xml
* joint_state_publisher.cpp --> allow to set the state, transforms and effort applied on XSensURDF.urdf/XSensURDF.xml
* wrench_stamped_publisher.cpp --> allow to set the wrench applied on XSensURDF.urdf/XSensURDF.xml
* displayPhantom.launch --> allow to display PhantomURDF.urdf
* tf_phantomTransform_broadcaster.cpp --> allow to set the state, transforms and effort applied on PhantomURDF.xml
* displayHalfPhantom.launch --> allow to display HalfPhantom.launch
* tf_simpleTransform_broadcaster.cpp --> allow to set the state, transforms and effort applied on HalfPhantomURDF.xml
* tf_broadcaster.cpp --> testing purpose

**Generic:**
* displayR2D2.launch --> allow to display any urdf or xml
* displayRobotStatic.launch --> allow to display any urdf or xml
* displayHuman.launch --> allow to display any urdf or xml


