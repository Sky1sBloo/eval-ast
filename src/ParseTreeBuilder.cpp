#include "ParseTreeBuilder.hpp"
#include "BinaryOperators.hpp"
#include "Equation.hpp"
#include "ParseTree.hpp"

#include <cctype>
#include <stdexcept>
#include <variant>

template <typename... callable> struct visitor : callable...
{
    using callable::operator()...;
};
ParseTreeBuilder::ParseTreeBuilder(const Equation<float> &equation)
{
    Equation<float> equationCopy = equation;
    while (!equationCopy.postFixEquation.empty())
    {
        PostFixContainer<float> node = std::move(equationCopy.postFixEquation.front());
        equationCopy.postFixEquation.pop();

        std::visit(visitor{[this](float constantValue) { mConstants.push(constantValue); },
                           [this](BinaryOperators op) { mOperators.push(op); }},
                   node);
    }
}

void ParseTreeBuilder::generateParseTree()
{
    if (mConstants.size() < 2)
    {
        throw std::invalid_argument("Invalid ParseString: Constants too few");
    }
    if (mOperators.size() != mConstants.size() - 1)
    {
        throw std::invalid_argument("Invalid ParseStriing: Operators too many/few");
    }

    // To retrieve the first 2 values
    float valueA = mConstants.top();
    mConstants.pop();
    float valueB = mConstants.top();
    mConstants.pop();

    auto root =
        std::make_unique<BinaryOperationNode<float>>(mOperators.front(), std::make_unique<ConstantNode<float>>(valueA),
                                                     std::make_unique<ConstantNode<float>>(valueB));
    mOperators.pop();

    // To append remaining values
    while (!mOperators.empty())
    {
        auto newOperation = std::make_unique<BinaryOperationNode<float>>(mOperators.front(), std::make_unique<ConstantNode<float>>(mConstants.top()));
        mConstants.pop();

        BinaryOperationNode<float>::appendBinaryRootOperation(root, std::move(newOperation));
        mOperators.pop();
    }

    mRootStatement = std::make_unique<PrintNode<float>>(std::move(root));

    /*

    // For retrieving the first 2 operations
    std::unique_ptr<ConstantNode<float>> valueA = std::move(mConstants.front());
    mConstants.pop();
    std::unique_ptr<ConstantNode<float>> valueB = std::move(mConstants.front());
    mConstants.pop();

    auto root = std::make_unique<BinaryOperationNode<float>>(mOperators.front(), std::move(valueA), std::move(valueB));
    mOperators.pop();

    // For appending
    while (!mOperators.empty())
    {
        auto newOperation = std::make_unique<BinaryOperationNode<float>>(mOperators.front(),
    std::move(mConstants.front())); mConstants.pop(); mOperators.pop();
        BinaryOperationNode<float>::appendBinaryRootOperation(root, std::move(newOperation));
    }

    mRootStatement = std::make_unique<PrintNode<float>>(std::move(root)); */
}

void ParseTreeBuilder::runParseTree()
{
    mRootStatement->doStatement();
}
