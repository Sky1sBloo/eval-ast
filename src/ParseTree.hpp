#pragma once

#include <iostream>
#include <memory>
#include <stdexcept>
#include <variant>

#include "BinaryOperators.hpp"

class StatementNode;

template <typename T> class ExpressionNode;

template <typename T> class ConstantNode;

template <typename T> class BinaryOperationNode;

template <typename T> class PrintNode;

template <typename T>
using ExpressionNodeContainer = std::variant<std::unique_ptr<ExpressionNode<T>>, std::unique_ptr<ConstantNode<T>>,
                                             std::unique_ptr<BinaryOperationNode<T>>>;

class StatementNode
{
  public:
    virtual ~StatementNode() {};
    virtual void doStatement() = 0;
};

template <typename T> class ExpressionNode
{
  public:
    virtual T getValue() const = 0;
};

template <typename T> class ConstantNode : public ExpressionNode<T>
{
  public:
    ConstantNode(T value) : mValue(value)
    {
    }
    T getValue() const override
    {
        return mValue;
    }

  private:
    T mValue;
};

template <typename T> class BinaryOperationNode : public ExpressionNode<T>
{
  public:
    BinaryOperationNode(BinaryOperators operation)
        : mValueA(std::unique_ptr<ExpressionNode<T>>(nullptr)), mValueB(std::unique_ptr<ExpressionNode<T>>(nullptr)),
          mOperation(operation)
    {
    }

    /**
     * Constructor for appending binary operation
     *
     * @operation that will be used
     * @value ValueB that will be appended
     */
    BinaryOperationNode(BinaryOperators operation, std::unique_ptr<ExpressionNode<T>> value)
        : mValueA(std::unique_ptr<ExpressionNode<T>>(nullptr)), mValueB(std::move(value)), mOperation(operation)
    {
    }

    /**
     * Use this for appending new operation
     */
    BinaryOperationNode(BinaryOperators operation, std::unique_ptr<ExpressionNode<T>> valueA,
                        std::unique_ptr<ExpressionNode<T>> valueB)
        : mValueA(std::move(valueA)), mValueB(std::move(valueB)), mOperation(operation)
    {
    }

    /**
     * Use this if you prefer to construct the operation types directly
     */
    BinaryOperationNode(BinaryOperators operation, T valueA, T valueB)
        : mValueA(std::make_unique<ConstantNode<T>>(valueA)), mValueB(std::make_unique<ConstantNode<T>>(valueB)),
          mOperation(operation)
    {
    }

    /**
     * Use this for appending new operation
     */
    BinaryOperationNode(BinaryOperators operation, T value)
        : mValueA(std::unique_ptr<ExpressionNode<T>>(nullptr)), mValueB(std::make_unique<ConstantNode<T>>(value)),
          mOperation(operation)
    {
    }

    T getValue() const override
    {
        T value = std::visit(
            [this](const auto &valueA, const auto &valueB) {
                if (valueA == nullptr || valueB == nullptr)
                {
                    throw std::runtime_error("Invalid binary operation: One of the values is nullptr");
                }

                switch (mOperation)
                {
                case BinaryOperators::ADDITION:
                    return valueA->getValue() + valueB->getValue();
                case BinaryOperators::SUBTRACTION:
                    return valueA->getValue() - valueB->getValue();
                case BinaryOperators::MULTIPLICATION:
                    return valueA->getValue() * valueB->getValue();
                case BinaryOperators::DIVISION:
                    return valueA->getValue() / valueB->getValue();
                }
                throw std::runtime_error("Invalid binary operation: Invalid operation");
            },
            mValueA, mValueB);

        return value;
    }

    void setValueA(ExpressionNodeContainer<T> &&value)
    {
        mValueA = std::move(value);
    }

    void setValueB(ExpressionNodeContainer<T> &&value)
    {
        mValueB = std::move(value);
    }

    BinaryOperators getOperation() const
    {
        return mOperation;
    }

    int getOperationPrecedence() const
    {
        return operatorPrecedence.at(mOperation);
    }

    /**
     * Use this for root operation and general append operation
     *
     * @tparam root Root node of the binary operation, this will be modified
     * @tparam newBinaryOperation The operation to be appended
     *
     */
    static void appendBinaryRootOperation(std::unique_ptr<BinaryOperationNode<T>> &root,
                               std::unique_ptr<BinaryOperationNode<T>> newBinaryOperation)
    {
        if (root->getOperationPrecedence() > newBinaryOperation->getOperationPrecedence())
        {
            newBinaryOperation->setValueA(std::move(root));
            root = std::move(newBinaryOperation);
        }

        root->appendBinaryOperation(std::move(newBinaryOperation));
    }

  protected:
    ExpressionNodeContainer<T> mValueA;
    ExpressionNodeContainer<T> mValueB;
    const BinaryOperators mOperation;

    /**
     * Appends a new binary operation on mValueA or B depending on childDIr
     *
     * @tparam T holder type generally for the ConstantNode
     * @tparam newBinaryOperation New Binary operation to be added
     * @param childDir Specifies the direction where newBinaryOperation will be appended
     */
    void appendBinaryOperation(std::unique_ptr<BinaryOperationNode<T>> newBinaryOperation,
                               BinaryDirection childDir = BinaryDirection::RIGHT)
    {
        ExpressionNodeContainer<T> &selectedValue = (childDir == BinaryDirection::RIGHT) ? mValueB : mValueA;

        if (std::holds_alternative<std::unique_ptr<BinaryOperationNode<T>>>(mValueB) &&
            newBinaryOperation->getOperationPrecedence() >
                std::get<std::unique_ptr<BinaryOperationNode<T>>>(mValueB)->getOperationPrecedence())

        {
            auto &childPtr = std::get<std::unique_ptr<BinaryOperationNode<T>>>(selectedValue);
            if (!childPtr)
            {
                throw std::runtime_error("Operation appending, valueB is null");
            }
            childPtr->appendBinaryOperation(std::move(newBinaryOperation));
            return;
        }

        ExpressionNodeContainer<T> tempValue = std::move(selectedValue);
        newBinaryOperation->setValueA(std::move(tempValue));
        selectedValue = std::move(newBinaryOperation);
    }
};

template <typename T> class PrintNode : public StatementNode
{
  public:
    PrintNode() : mExpression(nullptr)
    {
    }

    PrintNode(std::unique_ptr<ExpressionNode<T>> expression) : mExpression(std::move(expression))
    {
    }

    void doStatement() override
    {
        if (!mExpression)
        {
            throw std::runtime_error("Invalid print operation: Expression is nullptr");
        }
        std::cout << mExpression->getValue() << std::endl;
    }

    void setExpression(std::unique_ptr<ExpressionNode<T>> expression)
    {
        mExpression = std::move(expression);
    }

    const ExpressionNode<T> &getExpression() const
    {
        return *mExpression;
    }

  private:
    std::unique_ptr<ExpressionNode<T>> mExpression;
};
