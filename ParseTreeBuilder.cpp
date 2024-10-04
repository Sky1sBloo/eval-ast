#include "ParseTreeBuilder.hpp"

ParseTreeBuilder::ParseTreeBuilder(const std::string& parseString) :
	mParseString(parseString)
{
}

void ParseTreeBuilder::generateParseTree()
{
	PrintNode<int> root;
	root.setExpression(std::make_unique<BinaryOperationNode<int>>(BinaryOperators::SUBTRACTION,
				std::make_unique<ConstantNode<int>>(5),
				std::make_unique<ConstantNode<int>>(3)
				));
	root.doStatement();
}
