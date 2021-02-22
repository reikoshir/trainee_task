cmake_minimum_required(VERSION 3.8)



set(CMAKE_BUILD_TYPE Debug)


project (parent)

add_executable(parent parent.cpp)
add_executable(child child.cpp)

TARGET_LINK_LIBRARIES(parent pthread)
