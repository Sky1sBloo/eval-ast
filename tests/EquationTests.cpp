#include <gtest/gtest.h>
#include <variant>

#include "Equation.hpp"

template <typename... tVisit>
struct Visitor : tVisit... { using tVisit::operator()...; };

template <typename... tVisit> Visitor(tVisit...) -> Visitor<tVisit...>;
TEST (EQUATION_TEST, BINARY_OPERATION)
{
    std::string constantValues = "2+3";
    std::queue<PostFixContainer<float>> expectedAnswer;
    expectedAnswer.push(2.f);
    expectedAnswer.push(3.f);
    expectedAnswer.push(BinaryOperators::ADDITION);
    
    Equation<float> testEq(constantValues);

    if (expectedAnswer.size() != testEq.postFixEquation.size())
    {
        FAIL();
    }

    while (!testEq.postFixEquation.empty())
    {
        std::visit(Visitor{
            [](float postFixValue, float expectedValue)
            {
                EXPECT_FLOAT_EQ(postFixValue, expectedValue);
            },
            [](BinaryOperators postFixOp, BinaryOperators expectedOp)
            {
                EXPECT_EQ(postFixOp, expectedOp);
            },
            [](auto &&postFixValue, auto &&expectedOp)
            {
                FAIL();
            },
        }, testEq.postFixEquation.front(), expectedAnswer.front());

        testEq.postFixEquation.pop();
        expectedAnswer.pop();
    }
}
