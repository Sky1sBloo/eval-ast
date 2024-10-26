#pragma once
#include <array>
#include <unordered_map>

class EquationOperators
{
  public:
    enum class Types
    {
        INVALID,
        ADDITION,
        SUBTRACTION,
        MULTIPLICATION,
        DIVISION,
        OPEN_PARENTHESIS,
        CLOSE_PARENTHESIS
    };

    struct TypeParameters
    {
        Types type;
        int precedence;
        char symbol;
    };

    static constexpr bool ischarBinaryOperator(char ch);
    /**
     * Retrieves operator precedence from type
     *
     * @return -1 if invalid type
     */
    static constexpr int getOperatorPrecedence(Types type);

    /**
     * Retrieves operator from character
     */
    static constexpr Types getOperatorFromChar(char ch);

  private:
    static constexpr std::array<TypeParameters, 7> operatorParameters = {{{Types::INVALID, -1, ' '},
                                                                          {Types::ADDITION, 2, '+'},
                                                                          {Types::SUBTRACTION, 2, '-'},
                                                                          {Types::MULTIPLICATION, 3, '*'},
                                                                          {Types::DIVISION, 3, '/'},
                                                                          {Types::OPEN_PARENTHESIS, 1, '('},
                                                                          {Types::CLOSE_PARENTHESIS, 1, ')'}}};
};

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
    if (ch == '(' || ch == ')')
        return false;
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
