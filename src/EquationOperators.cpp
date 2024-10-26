#include "EquationOperators.hpp"

constexpr bool EquationOperators::ischarBinaryOperator(char ch) 
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


constexpr int EquationOperators::getPrecedence(Types type) 
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


constexpr EquationOperators::Types EquationOperators::getOperatorFromChar(char ch)
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
