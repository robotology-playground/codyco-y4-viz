cmake_minimum_required(VERSION 2.8.3)
project(testbot_description)

find_package(catkin REQUIRED COMPONENTS
catkin
urdf
std_msgs
geometry_msgs
sensor_msgs
message_generation
roscpp
rospy
tf
)

## Generate added messages and services with any dependencies listed here
generate_messages(
DEPENDENCIES
std_msgs
geometry_msgs
sensor_msgs
)

catkin_package(
CATKIN_DEPENDS message_runtime
)

include_directories(
${catkin_INCLUDE_DIRS}
)

## Declare a C++ executable
add_executable(joint_state_publisher src/joint_state_publisher.cpp)
add_executable(wrench_stamped_publisher src/wrench_stamped_publisher.cpp)
add_executable(tf_broadcaster src/tf_broadcaster.cpp)
add_executable(tf_simpleTransform_broadcaster src/tf_simpleTransform_broadcaster.cpp)
add_executable(tf_phantomTransform_broadcaster src/tf_phantomTransform_broadcaster.cpp)

# add_dependencies
add_dependencies(joint_state_publisher testbot_description_generate_messages_cpp)
add_dependencies(wrench_stamped_publisher testbot_description_generate_messages_cpp)
add_dependencies(tf_broadcaster testbot_description_generate_messages_cpp)
add_dependencies(tf_simpleTransform_broadcaster testbot_description_generate_messages_cpp)
add_dependencies(tf_phantomTransform_broadcaster testbot_description_generate_messages_cpp)

## Specify libraries to link a library or executable target against
target_link_libraries(joint_state_publisher ${catkin_LIBRARIES})
target_link_libraries(wrench_stamped_publisher ${catkin_LIBRARIES})
target_link_libraries(tf_broadcaster ${catkin_LIBRARIES})
target_link_libraries(tf_simpleTransform_broadcaster ${catkin_LIBRARIES})
target_link_libraries(tf_phantomTransform_broadcaster ${catkin_LIBRARIES})

