#pragma once
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
