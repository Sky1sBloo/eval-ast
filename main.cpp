#include "ParseTree.hpp"
#include <iostream>
#include <memory>

int main()
{
	auto valueA = std::make_unique<ValueNode<int>>(std::make_unique<int>(5));
	auto valueB = std::make_unique<ValueNode<int>>(std::make_unique<int>(3));
	auto valueC = std::make_unique<ValueNode<int>>(std::make_unique<int>(3));
	auto additionNodeA = std::make_unique<AdditionNode<int>>(std::move(valueA), std::move(valueB));
	AdditionNode<int> additionNodeB(std::move(additionNodeA), std::move(valueC));
	std::cout <<additionNodeB.getValue() << std::endl;
}
