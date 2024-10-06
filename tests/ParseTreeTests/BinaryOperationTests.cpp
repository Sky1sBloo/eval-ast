#include <gtest/gtest.h>
#include "ParseTree.hpp"

TEST(ParseTreeTest, BinaryOperationConstructor_Integer)
{
    std::array<int, 2> operationValues  = {1, 2};

    BinaryOperationNode<int> binaryIntAddOperation(BinaryOperators::ADDITION, 
                                                std::make_unique<ConstantNode<int>>(operationValues[0]),
                                                std::make_unique<ConstantNode<int>>(operationValues[1]));
    BinaryOperationNode<int> binaryIntSubtractOperation(BinaryOperators::SUBTRACTION, 
                                                std::make_unique<ConstantNode<int>>(operationValues[0]),
                                                std::make_unique<ConstantNode<int>>(operationValues[1]));
    BinaryOperationNode<int> binaryIntMultiplyOperation(BinaryOperators::MULTIPLICATION, 
                                                std::make_unique<ConstantNode<int>>(operationValues[0]),
                                                std::make_unique<ConstantNode<int>>(operationValues[1]));
    BinaryOperationNode<int> binaryIntDivideOperation(BinaryOperators::DIVISION, 
                                                std::make_unique<ConstantNode<int>>(operationValues[0]),
                                                std::make_unique<ConstantNode<int>>(operationValues[1]));

    EXPECT_EQ(binaryIntAddOperation.getValue(), operationValues[0] + operationValues[1]);
    EXPECT_EQ(binaryIntSubtractOperation.getValue(), operationValues[0] - operationValues[1]);
    EXPECT_EQ(binaryIntMultiplyOperation.getValue(), operationValues[0] * operationValues[1]);
    EXPECT_EQ(binaryIntDivideOperation.getValue(), operationValues[0] / operationValues[1]);
}

TEST(ParseTreeTest, BinaryOperationConstructor_FLOAT)
{
    std::array<float, 2> operationValues  = {1.f, 2.f};

    BinaryOperationNode<float> binaryFloatAddOperation(BinaryOperators::ADDITION, 
                                                std::make_unique<ConstantNode<float>>(operationValues[0]),
                                                std::make_unique<ConstantNode<float>>(operationValues[1]));
    BinaryOperationNode<float> binaryFloatSubtractOperation(BinaryOperators::SUBTRACTION, 
                                                std::make_unique<ConstantNode<float>>(operationValues[0]),
                                                std::make_unique<ConstantNode<float>>(operationValues[1]));
    BinaryOperationNode<float> binaryFloatMultiplyOperation(BinaryOperators::MULTIPLICATION, 
                                                std::make_unique<ConstantNode<float>>(operationValues[0]),
                                                std::make_unique<ConstantNode<float>>(operationValues[1]));
    BinaryOperationNode<float> binaryFloatDivideOperation(BinaryOperators::DIVISION, 
                                                std::make_unique<ConstantNode<float>>(operationValues[0]),
                                                std::make_unique<ConstantNode<float>>(operationValues[1]));

    EXPECT_FLOAT_EQ(binaryFloatAddOperation.getValue(), operationValues[0] + operationValues[1]);
    EXPECT_FLOAT_EQ(binaryFloatSubtractOperation.getValue(), operationValues[0] - operationValues[1]);
    EXPECT_FLOAT_EQ(binaryFloatMultiplyOperation.getValue(), operationValues[0] * operationValues[1]);
    EXPECT_FLOAT_EQ(binaryFloatDivideOperation.getValue(), operationValues[0] / operationValues[1]);
}
