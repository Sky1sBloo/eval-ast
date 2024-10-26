#include "Equation.hpp"

#include "BinaryOperators.hpp"
#include <cctype>
#include <stack>

template <typename T> Equation<T>::Equation(const std::string &infixEquation)
{
    std::stack<BinaryOperators> operators;
    std::string parseConstant;

    for (char parseChar : infixEquation)
    {
        if (std::isdigit(parseChar) || parseChar == '.')
        {
            parseConstant.push_back(parseChar);
        }
        else if (isCharBinaryOperator(parseChar))
        {
            if (!parseConstant.empty())
            {
                postFixEquation.emplace(std::stof(parseConstant));
            }
            parseConstant.clear();
            BinaryOperators current = getOperatorFromChar(parseChar);

            if (operators.empty() || getOperatorPrecedence(current) > getOperatorPrecedence(operators.top()) ||
                operators.top() == BinaryOperators::OPEN_PARENTHESIS)
            {
                operators.push(current);
            }
            else
            {
                while (!operators.empty() && getOperatorPrecedence(operators.top()) >= getOperatorPrecedence(current))
                {
                    postFixEquation.push(operators.top());
                    operators.pop();
                }
                operators.push(current);
            }
        }
        else if (getOperatorFromChar(parseChar) == BinaryOperators::OPEN_PARENTHESIS)
        {
            operators.push(BinaryOperators::OPEN_PARENTHESIS);
        }
        else if (getOperatorFromChar(parseChar) == BinaryOperators::CLOSE_PARENTHESIS)
        {
            postFixEquation.emplace(std::stof(parseConstant));
            while (operators.top() != BinaryOperators::OPEN_PARENTHESIS)
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
