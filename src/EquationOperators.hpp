#pragma once
#include <array>
#include <unordered_map>

/**
 * Class for operating equation operators
 */
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

    /**
     * Checks if the given char is binary operator
     * (this excludes open and close parenthesis)
     */
    static constexpr bool isCharBinaryOperator(char ch)
    {
        if (ch == '(' || ch == ')')
            return false;

        for (const TypeParameters &param : operatorParameters)
        {
            if (ch == param.symbol)
            {
                return true;
            }
        }

        return false;
    }
    /**
     * Retrieves operator precedence from type
     *
     * @return -1 if invalid type
     */
    static constexpr int getPrecedence(Types type)
    {
        for (const TypeParameters &param : operatorParameters)
        {
            if (type == param.type)
            {
                return param.precedence;
            }
        }
        return -1;
    }

    /**
     * Retrieves operator from character
     */
    static constexpr Types getOperatorFromChar(char ch)
    {
        for (const TypeParameters &param : operatorParameters)
        {
            if (ch == param.symbol)
            {
                return param.type;
            }
        }

        return Types::INVALID;
    }

  private:
    /**
     * Struct holding operator information
     */
    struct TypeParameters
    {
        Types type;
        int precedence;
        char symbol;
    };

    /**
     * Holds operator information
     */
    static constexpr std::array<TypeParameters, 7> operatorParameters = {{{Types::INVALID, -1, ' '},
                                                                          {Types::ADDITION, 2, '+'},
                                                                          {Types::SUBTRACTION, 2, '-'},
                                                                          {Types::MULTIPLICATION, 3, '*'},
                                                                          {Types::DIVISION, 3, '/'},
                                                                          {Types::OPEN_PARENTHESIS, 1, '('},
                                                                          {Types::CLOSE_PARENTHESIS, 1, ')'}}};
};

