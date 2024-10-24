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

        if (std::holds_alternative<float>(node))
        {
            constants.push(std::get<float>(node));
        }
        else if (std::holds_alternative<BinaryOperators>(node))
        {
            BinaryOperators op = std::get<BinaryOperators>(node);
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
        }
    }

    mRootStatement = std::make_unique<PrintNode<float>>(std::move(root));
}

void ParseTreeBuilder::runParseTree()
{
    mRootStatement->doStatement();
}
