add_library(eval-ast-lib ParseTreeBuilder.cpp)
target_include_directories(eval-ast-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
