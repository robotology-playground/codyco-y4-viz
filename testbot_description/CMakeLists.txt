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

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)

################################################
## Declare ROS messages, services and actions ##
################################################

## Generate messages in the 'msg' folder
##add_message_files(
##  FILES
##  JointStateExample.msg
##)

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  std_msgs
  geometry_msgs
  sensor_msgs
  )

################################################
## Declare ROS dynamic reconfigure parameters ##
################################################

## Generate dynamic reconfigure parameters in the 'cfg' folder
# generate_dynamic_reconfigure_options(
#   cfg/DynReconf1.cfg
#   cfg/DynReconf2.cfg
# )

###################################
## catkin specific configuration ##
###################################

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES testbot_description
#  CATKIN_DEPENDS urdf
#  DEPENDS system_lib
   CATKIN_DEPENDS message_runtime
)

###########
## Build ##
###########

include_directories(
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ library
# add_library(testbot_description
#   src/${PROJECT_NAME}/testbot_description.cpp
# )

# add_dependencies(testbot_description ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

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

#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
# install(PROGRAMS
#   scripts/my_python_script
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark executables and/or libraries for installation
# install(TARGETS testbot_description testbot_description_node
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_testbot_description.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
