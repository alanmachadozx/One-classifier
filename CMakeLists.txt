cmake_minimum_required(VERSION 3.16)
project(One-classifier)

add_executable(program 
src/main.cpp
)

target_include_directories(program PUBLIC include)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)