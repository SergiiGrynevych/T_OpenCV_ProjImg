cmake_minimum_required(VERSION 3.15)
project(T_OpenCV_ProjImg)

set(CMAKE_CXX_STANDARD 17)
#set(OpenCV_DIR C:/MULTIMEDIA/StudyPROGRAMMING/opencv/build)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(T_OpenCV_ProjImg T_OpenCV_ProjImg.cpp)

target_link_libraries(TEST_OPENCV_IMG_SIZE PUBLIC C:/MULTIMEDIA/StudyPROGRAMMING/opencv/build/x64/vc16/lib/opencv_world4100.lib) 
#may use env variables 
#target_link_libraries(T_OpenCV_ProjImg ${OpenCV_LIBS})
