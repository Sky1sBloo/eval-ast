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

        std::visit(visitor{[this](std::unique_ptr<ConstantNode<float>> &constNode) {
                               mConstantNodes.push(std::move(constNode));
                           },
                           [this](BinaryOperators op) { mOperators.push(op); }},
                   node);
    }
}

void ParseTreeBuilder::generateParseTree()
{
    if (mConstantNodes.size() < 2)
    {
        throw std::invalid_argument("Invalid ParseString: Constants too few");
    }
    if (mOperators.size() != mConstantNodes.size() - 1)
    {
        throw std::invalid_argument("Invalid ParseStriing: Operators too many/few");
    }


    /*

    // For retrieving the first 2 operations
    std::unique_ptr<ConstantNode<float>> valueA = std::move(mConstantNodes.front());
    mConstantNodes.pop();
    std::unique_ptr<ConstantNode<float>> valueB = std::move(mConstantNodes.front());
    mConstantNodes.pop();

    auto root = std::make_unique<BinaryOperationNode<float>>(mOperators.front(), std::move(valueA), std::move(valueB));
    mOperators.pop();

    // For appending
    while (!mOperators.empty())
    {
        auto newOperation = std::make_unique<BinaryOperationNode<float>>(mOperators.front(),
    std::move(mConstantNodes.front())); mConstantNodes.pop(); mOperators.pop();
        BinaryOperationNode<float>::appendBinaryRootOperation(root, std::move(newOperation));
    }

    mRootStatement = std::make_unique<PrintNode<float>>(std::move(root)); */
}

void ParseTreeBuilder::runParseTree()
{
    mRootStatement->doStatement();
}
