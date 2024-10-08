#include "ParseTreeBuilder.hpp"
#include "ParseTree.hpp"

ParseTreeBuilder::ParseTreeBuilder(const std::string &parseString) : mParseString(parseString)
{
}

void ParseTreeBuilder::generateParseTree()
{
    auto testNode = std::make_unique<BinaryOperationNode<int>>(BinaryOperators::ADDITION);
    auto testNodeB = std::make_unique<BinaryOperationNode<int>>(BinaryOperators::SUBTRACTION,
                                                                std::make_unique<ConstantNode<int>>(2));
    testNode->setValueA(std::make_unique<ConstantNode<int>>(5));
    testNode->setValueB(std::make_unique<ConstantNode<int>>(3));

    testNode->appendBinaryOperation(std::move(testNodeB), false);


    std::cout << testNode->getValue() << std::endl;
}

