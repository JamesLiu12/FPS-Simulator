cmake_minimum_required(VERSION 3.24)
project(FPS_Simulator C)

set(CMAKE_C_STANDARD 17)

add_executable(FPS_Simulator main.c op_engine/canvas.c op_engine/triangle.h op_engine/vector.h)
