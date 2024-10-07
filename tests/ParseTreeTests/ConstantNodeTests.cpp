#include <array>
#include <gtest/gtest.h>
#include "ParseTree.hpp"

TEST(ParseTreeTest, ConstantNodeTest)
{
    const int constantIntegerValue = 5;
    const float constantFloatValue = 5.f;
    std::string constantStringValue = "Hello world";


    ConstantNode<int> constantIntNode(constantIntegerValue);
    ConstantNode<float> constantFloatNode(constantFloatValue);
    ConstantNode<std::string> constantStringNode(constantStringValue);
    
    EXPECT_EQ(constantIntNode.getValue(), constantIntegerValue);
    EXPECT_FLOAT_EQ(constantFloatNode.getValue(), constantFloatValue);
    EXPECT_TRUE(constantStringNode.getValue().compare(constantStringValue) == 0);
}

