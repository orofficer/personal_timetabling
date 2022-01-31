cmake_minimum_required(VERSION 3.1)

project(Timetabling)

#set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

FIND_PACKAGE(Boost 1.65 COMPONENTS filesystem system iostreams REQUIRED)
include_directories(${CMAKE_HOME_DIRECTORY})

file(GLOB source *.cpp)
add_executable(${PROJECT_NAME} ${source})

target_link_libraries( ${PROJECT_NAME} LINK_PUBLIC ${Boost_LIBRARIES} )
