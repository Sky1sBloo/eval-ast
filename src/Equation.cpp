#include "Equation.hpp"

#include <cctype>
#include <stack>

template <typename T> Equation<T>::Equation(const std::string &infixEquation)
{
    std::stack<EquationOperators::Types> operators;
    std::string parseConstant;

    for (char parseChar : infixEquation)
    {
        if (std::isdigit(parseChar) || parseChar == '.')
        {
            parseConstant.push_back(parseChar);
        }
        else if (EquationOperators::isCharBinaryOperator(parseChar))
        {
            if (!parseConstant.empty())
            {
                postFixEquation.emplace(std::stof(parseConstant));
            }
            parseConstant.clear();
            EquationOperators::Types current = EquationOperators::getOperatorFromChar(parseChar);

            if (operators.empty() || EquationOperators::getPrecedence(current) > EquationOperators::getPrecedence(operators.top()) ||
                operators.top() == EquationOperators::Types::OPEN_PARENTHESIS)
            {
                operators.push(current);
            }
            else
            {
                while (!operators.empty() && EquationOperators::getPrecedence(operators.top()) >= EquationOperators::getPrecedence(current))
                {
                    postFixEquation.push(operators.top());
                    operators.pop();
                }
                operators.push(current);
            }
        }
        else if (EquationOperators::getOperatorFromChar(parseChar) == EquationOperators::Types::OPEN_PARENTHESIS)
        {
            operators.push(EquationOperators::Types::OPEN_PARENTHESIS);
        }
        else if (EquationOperators::getOperatorFromChar(parseChar) == EquationOperators::Types::CLOSE_PARENTHESIS)
        {
            postFixEquation.emplace(std::stof(parseConstant));
            while (operators.top() != EquationOperators::Types::OPEN_PARENTHESIS)
            {
                postFixEquation.push(operators.top());
                operators.pop();
            }
            operators.pop();
        }
    }

    postFixEquation.emplace(std::stof(parseConstant));
    while (!operators.empty())
    {
        postFixEquation.push(operators.top());
        operators.pop();
    }
}

template class Equation<float>;
