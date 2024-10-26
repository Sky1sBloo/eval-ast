#include <gtest/gtest.h>
#include <array>

#include "EquationOperators.hpp"
#include "ParseTree.hpp"



TEST(ParseTreeTest, BinaryOperationConstructor_Integer)
{
    std::array<int, 2> operationValues = {1, 2};

    BinaryOperationNode<int> binaryIntAddOperation(EquationOperators::Types::ADDITION,
                                                   std::make_unique<ConstantNode<int>>(operationValues[0]),
                                                   std::make_unique<ConstantNode<int>>(operationValues[1]));
    BinaryOperationNode<int> binaryIntSubtractOperation(EquationOperators::Types::SUBTRACTION,
                                                        std::make_unique<ConstantNode<int>>(operationValues[0]),
                                                        std::make_unique<ConstantNode<int>>(operationValues[1]));
    BinaryOperationNode<int> binaryIntMultiplyOperation(EquationOperators::Types::MULTIPLICATION,
                                                        std::make_unique<ConstantNode<int>>(operationValues[0]),
                                                        std::make_unique<ConstantNode<int>>(operationValues[1]));
    BinaryOperationNode<int> binaryIntDivideOperation(EquationOperators::Types::DIVISION,
                                                      std::make_unique<ConstantNode<int>>(operationValues[0]),
                                                      std::make_unique<ConstantNode<int>>(operationValues[1]));

    EXPECT_EQ(binaryIntAddOperation.getValue(), operationValues[0] + operationValues[1]);
    EXPECT_EQ(binaryIntSubtractOperation.getValue(), operationValues[0] - operationValues[1]);
    EXPECT_EQ(binaryIntMultiplyOperation.getValue(), operationValues[0] * operationValues[1]);
    EXPECT_EQ(binaryIntDivideOperation.getValue(), operationValues[0] / operationValues[1]);
}

TEST(ParseTreeTest, BinaryOperationConstructor_Float)
{
    std::array<float, 2> operationValues = {1.f, 2.f};

    BinaryOperationNode<float> binaryFloatAddOperation(EquationOperators::Types::ADDITION,
                                                       std::make_unique<ConstantNode<float>>(operationValues[0]),
                                                       std::make_unique<ConstantNode<float>>(operationValues[1]));
    BinaryOperationNode<float> binaryFloatSubtractOperation(EquationOperators::Types::SUBTRACTION,
                                                            std::make_unique<ConstantNode<float>>(operationValues[0]),
                                                            std::make_unique<ConstantNode<float>>(operationValues[1]));
    BinaryOperationNode<float> binaryFloatMultiplyOperation(EquationOperators::Types::MULTIPLICATION,
                                                            std::make_unique<ConstantNode<float>>(operationValues[0]),
                                                            std::make_unique<ConstantNode<float>>(operationValues[1]));
    BinaryOperationNode<float> binaryFloatDivideOperation(EquationOperators::Types::DIVISION,
                                                          std::make_unique<ConstantNode<float>>(operationValues[0]),
                                                          std::make_unique<ConstantNode<float>>(operationValues[1]));

    EXPECT_FLOAT_EQ(binaryFloatAddOperation.getValue(), operationValues[0] + operationValues[1]);
    EXPECT_FLOAT_EQ(binaryFloatSubtractOperation.getValue(), operationValues[0] - operationValues[1]);
    EXPECT_FLOAT_EQ(binaryFloatMultiplyOperation.getValue(), operationValues[0] * operationValues[1]);
    EXPECT_FLOAT_EQ(binaryFloatDivideOperation.getValue(), operationValues[0] / operationValues[1]);
}

TEST(ParseTreeTest, BinaryOperationBuilder_Integer)
{
    std::array<int, 2> operationValues = {1, 2};

    BinaryOperationNode<int> binaryIntAddOperation(EquationOperators::Types::ADDITION);
    binaryIntAddOperation.setValueA(std::make_unique<ConstantNode<int>>(operationValues[0]));
    binaryIntAddOperation.setValueB(std::make_unique<ConstantNode<int>>(operationValues[1]));
    BinaryOperationNode<int> binaryIntSubtractOperation(EquationOperators::Types::SUBTRACTION);
    binaryIntSubtractOperation.setValueA(std::make_unique<ConstantNode<int>>(operationValues[0]));
    binaryIntSubtractOperation.setValueB(std::make_unique<ConstantNode<int>>(operationValues[1]));
    BinaryOperationNode<int> binaryIntMultiplyOperation(EquationOperators::Types::MULTIPLICATION);
    binaryIntMultiplyOperation.setValueA(std::make_unique<ConstantNode<int>>(operationValues[0]));
    binaryIntMultiplyOperation.setValueB(std::make_unique<ConstantNode<int>>(operationValues[1]));
    BinaryOperationNode<int> binaryIntDivideOperation(EquationOperators::Types::DIVISION);
    binaryIntDivideOperation.setValueA(std::make_unique<ConstantNode<int>>(operationValues[0]));
    binaryIntDivideOperation.setValueB(std::make_unique<ConstantNode<int>>(operationValues[1]));

    EXPECT_EQ(binaryIntAddOperation.getValue(), operationValues[0] + operationValues[1]);
    EXPECT_EQ(binaryIntSubtractOperation.getValue(), operationValues[0] - operationValues[1]);
    EXPECT_EQ(binaryIntMultiplyOperation.getValue(), operationValues[0] * operationValues[1]);
    EXPECT_EQ(binaryIntDivideOperation.getValue(), operationValues[0] / operationValues[1]);
}

TEST(ParseTreeTest, BinaryOperationBuilder_FLOAT)
{
    std::array<float, 2> operationValues = {1.f, 2.f};

    BinaryOperationNode<float> binaryFloatAddOperation(EquationOperators::Types::ADDITION);
    binaryFloatAddOperation.setValueA(std::make_unique<ConstantNode<float>>(operationValues[0]));
    binaryFloatAddOperation.setValueB(std::make_unique<ConstantNode<float>>(operationValues[1]));
    BinaryOperationNode<float> binaryFloatSubtractOperation(EquationOperators::Types::SUBTRACTION);
    binaryFloatSubtractOperation.setValueA(std::make_unique<ConstantNode<float>>(operationValues[0]));
    binaryFloatSubtractOperation.setValueB(std::make_unique<ConstantNode<float>>(operationValues[1]));
    BinaryOperationNode<float> binaryFloatMultiplyOperation(EquationOperators::Types::MULTIPLICATION);
    binaryFloatMultiplyOperation.setValueA(std::make_unique<ConstantNode<float>>(operationValues[0]));
    binaryFloatMultiplyOperation.setValueB(std::make_unique<ConstantNode<float>>(operationValues[1]));
    BinaryOperationNode<float> binaryFloatDivideOperation(EquationOperators::Types::DIVISION);
    binaryFloatDivideOperation.setValueA(std::make_unique<ConstantNode<float>>(operationValues[0]));
    binaryFloatDivideOperation.setValueB(std::make_unique<ConstantNode<float>>(operationValues[1]));

    EXPECT_FLOAT_EQ(binaryFloatAddOperation.getValue(), operationValues[0] + operationValues[1]);
    EXPECT_FLOAT_EQ(binaryFloatSubtractOperation.getValue(), operationValues[0] - operationValues[1]);
    EXPECT_FLOAT_EQ(binaryFloatMultiplyOperation.getValue(), operationValues[0] * operationValues[1]);
    EXPECT_FLOAT_EQ(binaryFloatDivideOperation.getValue(), operationValues[0] / operationValues[1]);
}

