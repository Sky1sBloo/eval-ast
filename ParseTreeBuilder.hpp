#pragma once

#include <string>
#include "ParseTree.hpp"

class ParseTreeBuilder
{
public:
	ParseTreeBuilder(const std::string& parseString);
	void generateParseTree();
private:
	std::string mParseString;
};
