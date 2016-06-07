cmake_minimum_required(VERSION 3.5)
project(QuickSort)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp)
add_executable(QuickSort ${SOURCE_FILES})

configure_file(greatexpectations.txt greatexpectations.txt COPYONLY)

find_package(Boost 1.60.0 COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})