#pragma once

#include <iostream>
#include <memory>
#include <stdexcept>

#include "BinaryOperators.hpp"

class StatementNode
{
public:
	virtual ~StatementNode() {};
	virtual void doStatement() = 0;
};



template <typename T>
class ExpressionNode 
{
public:
	virtual ~ExpressionNode<T>() {};
	virtual T getValue() const = 0;
};

template <typename T>
class ValueNode : public ExpressionNode<T>
{
public:
	ValueNode(std::unique_ptr<T> value) : mValue(std::move(value)) {}
	~ValueNode() override {}
	T getValue() const override { return *mValue; }
private:
	std::unique_ptr<T> mValue;
};

template <typename T>
class BinaryOperationNode : public ExpressionNode<T>
{
public:
	BinaryOperationNode(BinaryOperators operation, std::unique_ptr<ExpressionNode<T>> valueA, std::unique_ptr<ExpressionNode<T>> valueB) :
		mOperation(operation),
		mValueA(std::move(valueA)),
		mValueB(std::move(valueB)) 
	{
		if (valueA == nullptr || valueB == nullptr)
		{
			throw std::runtime_error("Invalid binary operation: One of the values is nullptr");
		}
	}

	T getValue() const override
	{
		switch (mOperation)
		{
			case BinaryOperators::ADDITION:
				return mValueA->getValue() + mValueB->getValue();
			case BinaryOperators::SUBTRACTION:
				return mValueA->getValue() - mValueB->getValue();
			case BinaryOperators::MULTIPLICATION:
				return mValueA->getValue() * mValueB->getValue();
			case BinaryOperators::DIVISION:
				return mValueA->getValue() / mValueB->getValue();
		}
		throw std::runtime_error("Invalid binary operation: Invalid operation");
	}
protected:
	std::unique_ptr<ExpressionNode<T>> mValueA;
	std::unique_ptr<ExpressionNode<T>> mValueB;
	const BinaryOperators mOperation;
};

template <typename T>
class PrintNode : public StatementNode
{
public:
	PrintNode(std::unique_ptr<ExpressionNode<T>> expression);
	void doStatement() override
	{
		if (!mExpression)
		{
			throw std::runtime_error("Invalid print operation: Expression is nullptr");
		}
		std::cout << mExpression->getValue() << std::endl;
	}
private:
	std::unique_ptr<ExpressionNode<T>> mExpression;
};


