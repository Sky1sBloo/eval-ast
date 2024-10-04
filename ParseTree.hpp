#pragma once

#include <memory>
#include <stdexcept>

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
class AdditionNode : public ExpressionNode<T>
{
public:
	AdditionNode(std::unique_ptr<ExpressionNode<T>> valueA, std::unique_ptr<ExpressionNode<T>> valueB) :
		mValueA(std::move(valueA)),
		mValueB(std::move(valueB)) {}

	T getValue() const override
	{
		if (!mValueA || !mValueB)
		{
			throw std::runtime_error("Invalid operation on addition: One of the values is nullptr");
		}
		return mValueA->getValue() + mValueB->getValue();
	}
private:
	std::unique_ptr<ExpressionNode<T>> mValueA;
	std::unique_ptr<ExpressionNode<T>> mValueB;
};
