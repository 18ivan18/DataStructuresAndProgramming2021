#include "Stack.h"
#include <iostream>

template<typename T>
bool Stack<T>::full() const
{
	return topIndex == MAX_STACK_SIZE - 1;
}

template <typename T>
Stack<T>::Stack() : topIndex{-1} {}

template<typename T>
bool Stack<T>::empty() const
{
	return topIndex == -1;
}

template<typename T>
void Stack<T>::push(T const& element)
{
	if (full())
	{
		std::cerr << "The stack is full, you cannot push an element!" << std::endl;
	}
	arr[++topIndex] = element;
}

template<typename T>
T Stack<T>::pop()
{
	if (empty())
	{
		std::cerr << "The stack is empty, you cannot pop an element!" << std::endl;
		return T();
	}
	return arr[topIndex--];
}

template<typename T>
T Stack<T>::top() const
{
	if (empty())
	{
		std::cerr << "The stack is empty!" << std::endl;
		return T();
	}
	return arr[topIndex];
}
