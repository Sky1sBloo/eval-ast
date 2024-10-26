#include "EquationOperators.hpp"

const std::unordered_map<EquationOperators::Types, int> EquationOperators::precedence = {
    {Types::ADDITION, 2}, {Types::SUBTRACTION, 2},      {Types::MULTIPLICATION, 3},
    {Types::DIVISION, 3}, {Types::OPEN_PARENTHESIS, 1}, {Types::CLOSE_PARENTHESIS, 1}};
