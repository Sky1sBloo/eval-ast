#pragma once
#include <algorithm>
#include <unordered_map>

enum class BinaryOperators
{
	ADDITION,
	SUBTRACTION,
	MULTIPLICATION,
	DIVISION
};

enum class BinaryDirection
{
    LEFT,
    RIGHT
};

static std::unordered_map<BinaryOperators, int> operatorPrecedence = {
    { BinaryOperators::ADDITION, 1 },
    { BinaryOperators::SUBTRACTION, 1 },
    { BinaryOperators::MULTIPLICATION, 2 },
    { BinaryOperators::DIVISION, 2 },
};

static std::unordered_map<char, BinaryOperators> operatorCharacters = {
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
