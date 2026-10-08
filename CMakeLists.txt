cmake_minimum_required(VERSION 3.16)
project(One-classifier)

file(GLOB SOURCES CONFIGURE_DEPENDS "src/*.cpp")

add_executable(program 
${SOURCES}
)

target_include_directories(program PUBLIC include)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)