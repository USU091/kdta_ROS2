cmake_minimum_required(VERSION 3.0)
project(HelloWorld)

find_package(OpenCV REQUIRED)

add_executable(HelloWorld HelloWorld.cpp)
target_link_libraries(HelloWorld ${OpenCV_LIBS}) 
target_include_directories(HelloWorld PUBLIC ${OpenCV_LIB_DIR})