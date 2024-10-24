#include "Equation.hpp"

#include "BinaryOperators.hpp"
#include <cctype>
#include <stack>

template<typename T>
Equation<T>::Equation(const std::string &infixEquation)
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
            postFixEquation.emplace(std::stof(parseConstant));
            parseConstant.clear();
            BinaryOperators current = getOperatorFromChar(parseChar);

            if (current == BinaryOperators::OPEN_PARENTHESIS)
            {
                operators.push(current);
            }
            else if (current == BinaryOperators::CLOSE_PARENTHESIS)
            {
                while (operators.top() != BinaryOperators::OPEN_PARENTHESIS)
                {
                    postFixEquation.push(operators.top());
                    operators.pop();
                }
                operators.pop();
            }

            if (!operators.empty() && getOperatorPrecedence(current) > getOperatorPrecedence(operators.top()) ||
                operators.top() == BinaryOperators::OPEN_PARENTHESIS)
            {
                operators.push(current);
            }
            else
            {
                while (!operators.empty() && getOperatorPrecedence(operators.top()) >= getOperatorPrecedence(current))
                {
                    postFixEquation.emplace(operators.top());
                    operators.pop();
                }
            }
        }
    }
}

template class Equation<float>;
