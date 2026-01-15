cmake_minimum_required(VERSION 3.5)
project(mars_rover_projekt_1)

# C++17 Standard
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()
include_directories(inc)
include_directories(inc-gen)
include_directories(src-gen)

# ROS2 Abhängigkeiten
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# --- Executable 1: mars_rover_node_1 ---
add_executable(mars_rover_node_1
  src/mars_rover_node_1.cpp
  src-gen/Component_Architecture1_ID_420.c
  src-gen/data_dictionary.c
  src-gen/Echo_ID_431.c
  src-gen/Kontext_Rover_ID_704.c
  src-gen/Timer10_ID_579.c
  src-gen/TriggerFunk_ID_427.c
  src-gen/UltraschalSensor_HW_Componete_ID_435.c
)

ament_target_dependencies(mars_rover_node_1 rclcpp std_msgs)

# --- Executable 2: mars_rover_listener ---
add_executable(mars_rover_listener 
src/mars_rover_listener.cpp)
ament_target_dependencies(mars_rover_listener rclcpp std_msgs)

# Installationsregeln
install(TARGETS
 mars_rover_node_1
  mars_rover_listener
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()

