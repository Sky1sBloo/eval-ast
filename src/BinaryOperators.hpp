#pragma once
#include <unordered_map>
#include <optional>

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
    { BinaryOperators::ADDITION, 2 },
    { BinaryOperators::SUBTRACTION, 2 },
    { BinaryOperators::MULTIPLICATION, 3 },
    { BinaryOperators::DIVISION, 3 },
    { BinaryOperators::OPEN_PARENTHESIS, 1},
    { BinaryOperators::CLOSE_PARENTHESIS, 1}
};

static const std::unordered_map<char, BinaryOperators> operatorCharacters = {
    { '+', BinaryOperators::ADDITION },
    { '-', BinaryOperators::SUBTRACTION },
    { '*', BinaryOperators::MULTIPLICATION },
    { '/', BinaryOperators::DIVISION }
};

/**
 * Checks if the character is an operator
*/
inline bool isCharBinaryOperator(char ch)
{
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
 * @return Either an optional value of BinaryOperator, std::nullopt if char is invalid 
*/
inline std::optional<BinaryOperators> getOperatorFromChar(char ch)
{
    if (!isCharBinaryOperator(ch))
    {
        return std::nullopt;
    }
    return operatorCharacters.at(ch);
}
