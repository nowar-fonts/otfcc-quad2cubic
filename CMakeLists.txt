cmake_minimum_required(VERSION 3.12)
project(otfcc-quad2cubic)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)

add_executable(otfcc-q2c src/otfcc-q2c.cpp src/tt2ps.cpp)
add_executable(otfcc-c2q src/otfcc-c2q.cpp src/ps2tt.cpp)
