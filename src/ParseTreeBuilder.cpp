#include "ParseTreeBuilder.hpp"
#include "BinaryOperators.hpp"
#include "Equation.hpp"
#include "ParseTree.hpp"

#include <cctype>
#include <stack>
#include <stdexcept>
#include <variant>

ParseTreeBuilder::ParseTreeBuilder(const Equation<float> &equation) : mEquation(equation)
{
    /*
    Equation<float> equationCopy = equation;
    while (!equationCopy.postFixEquation.empty())
    {
        PostFixContainer<float> node = std::move(equationCopy.postFixEquation.front());
        equationCopy.postFixEquation.pop();

        std::visit(visitor{[this](float constantValue) { mConstants.push(constantValue); },
                           [this](BinaryOperators op) { mOperators.push(op); }},
                   node);
    } */
}

template <typename... callable> struct visitor : callable...
{
    using callable::operator()...;
};
void ParseTreeBuilder::generateParseTree()
{
    std::stack<float> constants;
    std::unique_ptr<BinaryOperationNode<float>> root;
    while (!mEquation.postFixEquation.empty())
    {
        PostFixContainer<float> node = std::move(mEquation.postFixEquation.front());
        mEquation.postFixEquation.pop();

        std::visit(visitor{[&constants](float constantValue) { constants.push(constantValue); },
                           [&constants, &root](BinaryOperators op) {
                               if (root == nullptr)
                               {
                                   if (constants.size() < 2)
                                   {
                                       throw std::invalid_argument("Invalid ParseString: Constants too few");
                                   }

                                   float valueA = constants.top();
                                   constants.pop();
                                   float valueB = constants.top();
                                   constants.pop();

                                   root = std::make_unique<BinaryOperationNode<float>>(op, valueA, valueB);
                               }
                               else
                               {
                                   auto newOperation = std::make_unique<BinaryOperationNode<float>>(
                                       op, std::move(root), std::make_unique<ConstantNode<float>>(constants.top()));
                                   constants.pop();
                                   root = std::move(newOperation);
                               }
                           }},
                   node);
    }

    mRootStatement = std::make_unique<PrintNode<float>>(std::move(root));
}

void ParseTreeBuilder::runParseTree()
{
    mRootStatement->doStatement();
}
