cmake_minimum_required(VERSION 3.10)

project(eval-ast VERSION 0.1)
set(CMAKE_BUILD_TYPE RelWithDebInfo)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

enable_testing()

# Add testing
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
##

add_subdirectory(src)
add_executable(eval-ast main.cpp)
target_link_libraries(eval-ast PRIVATE eval-ast-lib)

add_subdirectory(tests)
