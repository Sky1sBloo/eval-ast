#pragma once

#include <memory>
#include <stack>

#include "Equation.hpp"
#include "ParseTree.hpp"

class ParseTreeBuilder
{
  public:
    ParseTreeBuilder(const Equation<float> &equation);

    /**
     * Generates a new parse tree
     *
     * Throws std::invalid_argument if parseString is invalid
     */
    void generateParseTree();
    void runParseTree();

  private:
    std::stack<std::unique_ptr<ConstantNode<float>>> mConstantNodes;
    std::stack<BinaryOperators> mOperators;

    std::unique_ptr<StatementNode> mRootStatement;
};
