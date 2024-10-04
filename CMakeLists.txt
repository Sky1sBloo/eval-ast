cmake_minimum_required(VERSION 3.0)

project(eval-ast)
set(CMAKE_BUILD_TYPE RelWithDebInfo)
add_executable(eval-ast main.cpp ParseTreeBuilder.cpp)
