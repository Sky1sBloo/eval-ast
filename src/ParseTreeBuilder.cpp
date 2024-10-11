#include "ParseTreeBuilder.hpp"
#include "BinaryOperators.hpp"
#include "ParseTree.hpp"

#include <cctype>
#include <iostream>
#include <string>

ParseTreeBuilder::ParseTreeBuilder(const std::string &parseString) : mParseString(parseString)
{
    std::string parseConstant;
    int s = 0;
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
                s++;
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
        std::cerr << "Invalid ParseString: Constants too few" << std::endl;
    }
    if (mOperators.size() != mConstantNodes.size() - 1)
    {
        std::cerr << "Invalid ParseString: Operators too few/many" << std::endl;
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

        BinaryOperationNode<float>::appendBinaryRootOperation(root, std::move(newOperation)); 
    } 

    PrintNode<float> printNode(std::move(root));
    printNode.doStatement();
}
