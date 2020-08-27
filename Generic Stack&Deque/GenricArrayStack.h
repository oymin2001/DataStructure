#ifndef GENERIC_ARRAYSTACK_H
#define GENERIC_ARRAYSTACK_H

#include"Exceptions.h"

template<typename E>
class ArrayStack
{
	enum {DEF_CAPACITY =100};

public:
	ArrayStack(int cap = DEF_CAPACITY);
	int size() const;
	bool empty() const;
	const E& top() const throw(StackEmpty);
	void push(const E& e)throw(StackFull);
	void pop() throw(StackEmpty);
	void print();

private:
	E* stack;
	int capacity;
	int stack_top;
};

template<typename E>
ArrayStack<E>::ArrayStack(int cap)
	:stack(new E[cap]),capacity(cap),stack_top(-1)
{}

template<typename E>
int ArrayStack<E>::size() const
{
	return (stack_top + 1);
}

template<typename E>
bool ArrayStack<E>::empty() const
{
	return (stack_top < 0);
}

template<typename E>
const E& ArrayStack<E>::top()
const throw(StackEmpty)
{
	if (empty())throw
		StackEmpty("Top of empty stack!!");
	return stack[stack_top];
}

template<typename E>
void ArrayStack<E>::push(const E& e)
throw(StackFull)
{
	if (size() == capacity)
		throw StackFull("Push into full stack!!");
	stack[++stack_top] = e;
}

template<typename E>
void ArrayStack<E>::pop()
throw(StackEmpty)
{
	if (empty())throw
		StackEmpty("Pop from empty stack!!");
	--stack_top;
}

template<typename E>
void ArrayStack<E>::print()
{
	for (int i = stack_top; i >= 0; i--)
		cout << stack[i] << " ";
}

#endif // !GENERIC_ARRAYSTACK_H
