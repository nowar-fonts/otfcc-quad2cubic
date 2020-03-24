cmake_minimum_required(VERSION 3.12)
project(otfcc-quad2cubic)
find_package(Boost REQUIRED)

set(CMAKE_CXX_STANDARD 17)
include_directories(include ${Boost_INCLUDE_DIRS})

add_executable(otfcc-q2c src/otfcc-q2c.cpp src/tt2ps.cpp)
