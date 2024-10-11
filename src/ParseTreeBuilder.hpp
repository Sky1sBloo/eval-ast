#pragma once

#include <memory>
#include <string>
#include <queue>

#include "ParseTree.hpp"

class ParseTreeBuilder
{
  public:
    ParseTreeBuilder(const std::string &parseString);
    void generateParseTree();

  private:
    std::string mParseString;
    std::queue<std::unique_ptr<ConstantNode<float>>> mConstantNodes;
    std::queue<BinaryOperators> mOperators;
};
