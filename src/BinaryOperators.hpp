#pragma once
#include <unordered_map>

enum class BinaryOperators
{
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    OPEN_PARENTHESIS,
    CLOSE_PARENTHESIS
};

enum class BinaryDirection
{
    LEFT,
    RIGHT
};

static const std::unordered_map<BinaryOperators, int> operatorPrecedence = {
    {BinaryOperators::ADDITION, 2}, {BinaryOperators::SUBTRACTION, 2},      {BinaryOperators::MULTIPLICATION, 3},
    {BinaryOperators::DIVISION, 3}, {BinaryOperators::OPEN_PARENTHESIS, 1}, {BinaryOperators::CLOSE_PARENTHESIS, 1}};

static const std::unordered_map<char, BinaryOperators> operatorCharacters = {
    {'+', BinaryOperators::ADDITION},         {'-', BinaryOperators::SUBTRACTION},
    {'*', BinaryOperators::MULTIPLICATION},   {'/', BinaryOperators::DIVISION},
    {'(', BinaryOperators::OPEN_PARENTHESIS}, {')', BinaryOperators::CLOSE_PARENTHESIS}};

/**
 * Checks if the character is an operator
 * Doesn't include parenthesis
 */
inline bool isCharBinaryOperator(char ch)
{
    if (ch == '(' || ch == ')')  return false;
    return operatorCharacters.find(ch) != operatorCharacters.end();
}

/**
 * Returns the operator precedence
 */
inline int getOperatorPrecedence(BinaryOperators op)
{
    return operatorPrecedence.at(op);
}

/**
 * Returns the operator from character
 * Recommended to check if char is binary operator first
 */
inline BinaryOperators getOperatorFromChar(char ch)
{
    return operatorCharacters.at(ch);
}
