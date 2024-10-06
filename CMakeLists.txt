cmake_minimum_required(VERSION 3.0)

project(eval-ast)
set(CMAKE_BUILD_TYPE RelWithDebInfo)

file (GLOB_RECURSE SRC_FILES main.cpp src/*.cpp)
add_executable(eval-ast main.cpp ${SRC_FILES})
target_include_directories(eval-ast PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
