testbot_description

Usage

- in a new terminal launch roscore: 
	$ roscore
- in a new terminal launch rviz:
	$ rosrun rviz rviz
- move to the testbot_description folder:
	$ cd testbot_description
- in a new terminal run the launch file associated to the urdf model which you want to visualize:
	$ roslaunch testbot_description <display.launch>  model:=urdf/<model.urdf>
- in rviz set the <FixedFrame> to ground
- in rviz add a "RobotModel" and in the field "Robot Description" the <prefix> before robot_description as <prefix>/robot_description (the prefix is the "ns" value associated to the field <group> that you can find in the launch file)

Launch file and model association:

	Specific:
	displayHuman.launch --> HumanURDF.urdf
	displayRobot.launch --> XSensURDF.urdf/XSensURDF.xml
	displayPhantom.launch --> PhantomURDF.urdf
	displayHalfPhantom.launch --> HalfPhantom.launch  

	Generic:
	displayR2D2.launch --> any urdf or xml
	displayRobotStatic.launch --> any urdf or xml	


