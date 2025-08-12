cmake_minimum_required(VERSION 3.8)
project(af3_ultrasound)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

include_directories(
  include
)

add_library(af3_ultrasound_lib
  src/Component_Architecture1_ID_420.c
  src/UltraschalSensor_HW_Componete_ID_435.c
  src/Echo_ID_431.c
  src/TriggerFunk_ID_427.c
  src/Timer10_ID_579.c
  src/Kontext_Rover_ID_704.c
  src/data_dictionary.c
  src/af3_ultrasound_wrapper.c
)

add_executable(af3_ultrasound_node
  src/af3_ultrasound_node.cpp
)

target_link_libraries(af3_ultrasound_node
  af3_ultrasound_lib
)

ament_target_dependencies(
  af3_ultrasound_node
  rclcpp
  std_msgs
)

install(
  TARGETS
    af3_ultrasound_node
    af3_ultrasound_lib
  DESTINATION lib/${PROJECT_NAME}
)

install(
  DIRECTORY include/
  DESTINATION include
)

ament_package()