cmake_minimum_required(VERSION 3.0.2)
project(image2opm_pkg)

Set(OpenCV_DIR /usr/share/OpenCV)

find_package(catkin REQUIRED COMPONENTS
  nav_msgs
  roscpp
  std_msgs
  OpenCV
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES image2opm_pkg
#  CATKIN_DEPENDS nav_msgs roscpp std_msgs
#  DEPENDS system_lib
)


include_directories(
  ${PROJECT_SOURCE_DIR}/include
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

add_library(OPM_GENERATOR
        include/opm_generator.hpp
        src/opm_generator.cpp
        )


add_executable(image2opm app/main.cpp)
target_link_libraries(image2opm
        ${catkin_LIBRARIES}
        ${OpenCV_LIBS}
        OPM_GENERATOR
        )
