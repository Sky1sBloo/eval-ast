#pragma once

#include <memory>
#include <string>
#include <queue>

#include "ParseTree.hpp"

class ParseTreeBuilder
{
  public:
    ParseTreeBuilder(const std::string &parseString);

    /**
     * Generates a new parse tree
     * 
     * @return If parse tree creation failed
    */
    bool generateParseTree();
    void runParseTree();

  private:
    std::string mParseString;
    std::queue<std::unique_ptr<ConstantNode<float>>> mConstantNodes;
    std::queue<BinaryOperators> mOperators;

    std::unique_ptr<StatementNode> mRootStatement;
};
