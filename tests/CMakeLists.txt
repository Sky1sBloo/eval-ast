add_executable(
    eval-ast-unit-tests
    ParseTreeTests/ConstantNodeTests.cpp
    ParseTreeTests/BinaryOperationTests.cpp
)

target_link_libraries(
    eval-ast-unit-tests PRIVATE
    eval-ast-lib
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(eval-ast-unit-tests)
