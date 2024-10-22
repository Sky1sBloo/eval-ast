#include "ParseTreeBuilder.hpp"
#include "BinaryOperators.hpp"
#include "ParseTree.hpp"

#include <cctype>
#include <stdexcept>
#include <string>

ParseTreeBuilder::ParseTreeBuilder(const std::string &parseString) : mParseString(parseString)
{
    std::string parseConstant;
    for (char parseChar : parseString)
    {
        if (std::isdigit(parseChar) || parseChar == '.')
        {
            parseConstant.push_back(parseChar);
        }
        else if (isCharBinaryOperator(parseChar))
        {
            if (!parseConstant.empty())
            {
                mConstantNodes.push(std::make_unique<ConstantNode<float>>(std::stof(parseConstant)));
                parseConstant.clear();
            }
            mOperators.push(operatorCharacters.at(parseChar));
        }
    }

    if (!parseConstant.empty())
    {
        mConstantNodes.push(std::make_unique<ConstantNode<float>>(std::stof(parseConstant)));
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
        auto newOperation = std::make_unique<BinaryOperationNode<float>>(mOperators.front(), std::move(mConstantNodes.front()));
        mConstantNodes.pop();
        mOperators.pop();
        root, std::move(newOperation);

        BinaryOperationNode<float>::appendBinaryRootOperation(root, std::move(newOperation)); 
    } 

    mRootStatement = std::make_unique<PrintNode<float>>(std::move(root));
}

void ParseTreeBuilder::runParseTree()
{
    mRootStatement->doStatement();
}
