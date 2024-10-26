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


constexpr int EquationOperators::getOperatorPrecedence(Types type) 
{
    
}
