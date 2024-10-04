#include "ParseTreeBuilder.hpp"
#include "BinaryOperators.hpp"
#include <iostream>
#include <memory>

int main()
{
	
	ParseTreeBuilder parseTreeBuilder("Test");
	parseTreeBuilder.generateParseTree();
	/*
	auto valueA = std::make_unique<ValueNode<int>>(std::make_unique<int>(5));
	auto valueB = std::make_unique<ValueNode<int>>(std::make_unique<int>(3));
	//auto valueC = std::make_unique<ValueNode<int>>(nullptr);
	auto valueC = std::make_unique<ValueNode<int>>(std::make_unique<int>(2));
	auto additionNodeA = std::make_unique<BinaryOperationNode<int>>(
			BinaryOperators::ADDITION,
			std::move(valueA), 
			std::move(valueB));
	BinaryOperationNode<int> subtractionNodeB(
			BinaryOperators::SUBTRACTION,
			std::move(additionNodeA), 
			std::move(valueC)); 
	std::cout << subtractionNodeB.getValue() << std::endl; */
}
