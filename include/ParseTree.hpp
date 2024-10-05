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
class ConstantNode : public ExpressionNode<T>
{
public:
	ConstantNode(T value) : mValue(value) {}
	~ConstantNode() override {}
	T getValue() const override { return mValue; }
private:
	T mValue;
};

template <typename T>
class BinaryOperationNode : public ExpressionNode<T>
{
public:
	BinaryOperationNode(BinaryOperators operation) :
		mValueA(nullptr),
		mValueB(nullptr),
		mOperation(operation)
	{
	}

	BinaryOperationNode(BinaryOperators operation, std::unique_ptr<ExpressionNode<T>> valueA, std::unique_ptr<ExpressionNode<T>> valueB) :
		mValueA(std::move(valueA)),
		mValueB(std::move(valueB)),
		mOperation(operation)
	{
	}

	T getValue() const override
	{
		if (mValueA == nullptr || mValueB == nullptr)
		{
			throw std::runtime_error("Invalid binary operation: One of the values is nullptr");
		}
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

	void setValueA(std::unique_ptr<ExpressionNode<T>> value)
	{
		mValueA = std::move(value);
	}

	void setValueB(std::unique_ptr<ExpressionNode<T>> value)
	{
		mValueB = std::move(value);
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
	PrintNode() :
		mExpression(nullptr)
	{}

	PrintNode(std::unique_ptr<ExpressionNode<T>> expression) :
		mExpression(std::move(expression)) {}

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

	const ExpressionNode<T>& getExpression() const
	{
		return *mExpression;
	}
private:
	std::unique_ptr<ExpressionNode<T>> mExpression;
};


