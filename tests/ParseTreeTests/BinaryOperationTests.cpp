#include <gtest/gtest.h>
#include <array>
#include <queue>

#include "BinaryOperators.hpp"
#include "ParseTree.hpp"



TEST(ParseTreeTest, BinaryOperationConstructor_Integer)
{
    std::array<int, 2> operationValues = {1, 2};

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

TEST(ParseTreeTest, BinaryOperationConstructor_Float)
{
    std::array<float, 2> operationValues = {1.f, 2.f};

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

TEST(ParseTreeTest, BinaryOperationBuilder_Integer)
{
    std::array<int, 2> operationValues = {1, 2};

    BinaryOperationNode<int> binaryIntAddOperation(BinaryOperators::ADDITION);
    binaryIntAddOperation.setValueA(std::make_unique<ConstantNode<int>>(operationValues[0]));
    binaryIntAddOperation.setValueB(std::make_unique<ConstantNode<int>>(operationValues[1]));
    BinaryOperationNode<int> binaryIntSubtractOperation(BinaryOperators::SUBTRACTION);
    binaryIntSubtractOperation.setValueA(std::make_unique<ConstantNode<int>>(operationValues[0]));
    binaryIntSubtractOperation.setValueB(std::make_unique<ConstantNode<int>>(operationValues[1]));
    BinaryOperationNode<int> binaryIntMultiplyOperation(BinaryOperators::MULTIPLICATION);
    binaryIntMultiplyOperation.setValueA(std::make_unique<ConstantNode<int>>(operationValues[0]));
    binaryIntMultiplyOperation.setValueB(std::make_unique<ConstantNode<int>>(operationValues[1]));
    BinaryOperationNode<int> binaryIntDivideOperation(BinaryOperators::DIVISION);
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

    BinaryOperationNode<float> binaryFloatAddOperation(BinaryOperators::ADDITION);
    binaryFloatAddOperation.setValueA(std::make_unique<ConstantNode<float>>(operationValues[0]));
    binaryFloatAddOperation.setValueB(std::make_unique<ConstantNode<float>>(operationValues[1]));
    BinaryOperationNode<float> binaryFloatSubtractOperation(BinaryOperators::SUBTRACTION);
    binaryFloatSubtractOperation.setValueA(std::make_unique<ConstantNode<float>>(operationValues[0]));
    binaryFloatSubtractOperation.setValueB(std::make_unique<ConstantNode<float>>(operationValues[1]));
    BinaryOperationNode<float> binaryFloatMultiplyOperation(BinaryOperators::MULTIPLICATION);
    binaryFloatMultiplyOperation.setValueA(std::make_unique<ConstantNode<float>>(operationValues[0]));
    binaryFloatMultiplyOperation.setValueB(std::make_unique<ConstantNode<float>>(operationValues[1]));
    BinaryOperationNode<float> binaryFloatDivideOperation(BinaryOperators::DIVISION);
    binaryFloatDivideOperation.setValueA(std::make_unique<ConstantNode<float>>(operationValues[0]));
    binaryFloatDivideOperation.setValueB(std::make_unique<ConstantNode<float>>(operationValues[1]));

    EXPECT_FLOAT_EQ(binaryFloatAddOperation.getValue(), operationValues[0] + operationValues[1]);
    EXPECT_FLOAT_EQ(binaryFloatSubtractOperation.getValue(), operationValues[0] - operationValues[1]);
    EXPECT_FLOAT_EQ(binaryFloatMultiplyOperation.getValue(), operationValues[0] * operationValues[1]);
    EXPECT_FLOAT_EQ(binaryFloatDivideOperation.getValue(), operationValues[0] / operationValues[1]);
}

TEST(ParseTreeTest, BinaryOperationAppending)
{
    std::array<float, 5> operationValues = {1.f, 2.f, 3.f, 4.f, 5.f};
    std::array<BinaryOperators, 4> operations = {BinaryOperators::ADDITION, BinaryOperators::MULTIPLICATION,
                                                 BinaryOperators::SUBTRACTION, BinaryOperators::DIVISION};

    std::queue<std::unique_ptr<BinaryOperationNode<float>>> binaryOperationNodes;

    binaryOperationNodes.push(
        std::make_unique<BinaryOperationNode<float>>(operations[0], operationValues[0], operationValues[0 + 1]));
    for (int i = 1; i < operations.size(); i++)
    {
        binaryOperationNodes.push(std::make_unique<BinaryOperationNode<float>>(operations[i], operationValues[i + 1]));
    }

    auto root = std::move(binaryOperationNodes.front());
    binaryOperationNodes.pop();

    while (!binaryOperationNodes.empty())
    {
        root = BinaryOperationNode<float>::appendBinaryOperation(std::move(root),
                                                                           std::move(binaryOperationNodes.front()));
        binaryOperationNodes.pop();
    }

    EXPECT_FLOAT_EQ(root->getValue(), 1.f + 2.f * 3.f - 4.f / 5.f);
}

