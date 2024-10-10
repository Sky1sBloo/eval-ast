#include "ParseTreeBuilder.hpp"
#include "BinaryOperators.hpp"
#include "ParseTree.hpp"

ParseTreeBuilder::ParseTreeBuilder(const std::string &parseString) : mParseString(parseString)
{
}

void ParseTreeBuilder::generateParseTree()
{
    auto testNode = std::make_unique<BinaryOperationNode<int>>(BinaryOperators::ADDITION);
    auto testNodeB = std::make_unique<BinaryOperationNode<int>>(BinaryOperators::MULTIPLICATION,
                                                                std::make_unique<ConstantNode<int>>(2));
    testNode->setValueA(std::make_unique<ConstantNode<int>>(5));
    testNode->setValueB(std::make_unique<ConstantNode<int>>(3));


    auto newBinaryRoot = BinaryOperationNode<int>::appendBinaryOperation(std::move(testNode), std::move(testNodeB));

    PrintNode<int> root(std::move(newBinaryRoot));

    root.doStatement();
}
