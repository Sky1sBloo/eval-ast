#include "ParseTreeBuilder.hpp"
#include "ParseTree.hpp"

ParseTreeBuilder::ParseTreeBuilder(const std::string &parseString) : mParseString(parseString)
{
}

void ParseTreeBuilder::generateParseTree()
{
    auto testNode = std::make_unique<BinaryOperationNode<int>>(BinaryOperators::ADDITION);
    auto testNodeB = std::make_unique<BinaryOperationNode<int>>(BinaryOperators::SUBTRACTION);
    testNode->setValueA(std::make_unique<ConstantNode<int>>(5));
    testNode->setValueB(std::make_unique<ConstantNode<int>>(3));
    testNodeB->setValueB(std::make_unique<ConstantNode<int>>(2));

    testNode->appendBinaryOperation(std::move(testNodeB), false);

    PrintNode<int> root;
    root.setExpression(std::move(testNode));
    root.doStatement();

    /*
     * constructor version
    PrintNode<int> root;
    root.setExpression(std::make_unique<BinaryOperationNode<int>>(
        BinaryOperators::SUBTRACTION, std::make_unique<ConstantNode<int>>(5), std::make_unique<ConstantNode<int>>(3)));
    root.doStatement(); */

}

