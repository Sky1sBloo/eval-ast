#pragma once

#include <string>
#include <queue>
#include <variant>
#include "ParseTree.hpp"

template<typename T>
using PostFixContainer = std::variant<std::unique_ptr<ConstantNode<T>>, BinaryOperators>;

/**
 * Class representing an equation
 * Used for easier building for ParseTree
 */
template<typename T>
class Equation
{
  public:
    Equation(const std::string& infixEquation);

    // Used queue with string for to store values greater than 9
    std::queue<PostFixContainer<T>> postFixEquation;
};
