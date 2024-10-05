#include "ParseTreeBuilder.hpp"
#include "ParseTree.hpp"

ParseTreeBuilder::ParseTreeBuilder(const std::string &parseString) : mParseString(parseString)
{
}

void ParseTreeBuilder::generateParseTree()
{
    for (char e : mParseString)
    {

    }
    PrintNode<int> root;
    root.setExpression(std::make_unique<BinaryOperationNode<int>>(
      BinaryOperators::SUBTRACTION, std::make_unique<ConstantNode<int>>(5), std::make_unique<ConstantNode<int>>(3)));
    root.doStatement();
}
