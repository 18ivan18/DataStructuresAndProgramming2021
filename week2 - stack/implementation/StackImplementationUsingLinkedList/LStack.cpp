#include "LStack.h"
#include <iostream>

template<typename T>
void LStack<T>::copy(const LStack& other)
{
	topPtr = nullptr; 

	StackElement<T>* tempPtr = other.topPtr;
	LStack<T> tempStack;
	while (tempPtr != nullptr)
	{
		tempStack.push(tempPtr->data);
		tempPtr = tempPtr->next;
	}
	while (!tempStack.empty())
	{
		push(tempStack.pop();)
	}
}

template<typename T>
void LStack<T>::erase()
{
	while (!empty())
	{
		pop();
	}
}

template<typename T>
LStack<T>::LStack()
{
	topPtr = nullptr;
}

template<typename T>
LStack<T>::LStack(const LStack& other)
{
	copy(other);
}

template<typename T>
LStack<T>& LStack<T>::operator=(const LStack& other)
{
	if (this != &other)
	{
		erase();
		copy(other);
	}
	return *this;
}

template<typename T>
LStack<T>::LStack(LStack&& other)
{
	topPtr = other.topPtr;
	other.topPtr = nullptr;
}

template<typename T>
LStack<T>& LStack<T>::operator=(LStack&& other)
{
	if (this != &other)
	{
		erase();
		topPtr = other.topPtr;
		other.topPtr = nullptr;
	}
	return *this;
}

template<typename T>
LStack<T>::~LStack()
{
	erase();
}

template<typename T>
bool LStack<T>::empty()
{
	return topPtr == nullptr;
}

template<typename T>
void LStack<T>::push(const T& element)
{
	StackElement<T>* newElement = new StackElement<T>;
	newElement->data = element;
	newElement->next = topPtr;
	topPtr = newElement;
}

template<typename T>
T LStack<T>::pop()
{
	if (empty())
	{
		std::cerr << "The stack is empty, you cannot pop an element!" << std::endl;
		return T();
	}

	T result = top();
	StackElement<T>* temp = topPtr;
	topPtr = topPtr->next;
	delete temp;

	return result;
}

template<typename T>
const T& LStack<T>::top() const
{
	if (empty())
	{
		std::cerr << "The stack is empty!\n";
		return T();
	}
	return topPtr->data;
}

template<typename T>
T& LStack<T>::top()
{
	if (empty())
	{
		std::cerr << "The stack is empty!" << std::endl;
		return T();
	}
	return topPtr->data;
}
