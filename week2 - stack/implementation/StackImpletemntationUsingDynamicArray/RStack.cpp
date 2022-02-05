#include "RStack.h"
#include <iostream>

template <typename T>
bool RStack<T>::full() const
{
	return topIndex == capacity - 1;
}

template<typename T>
void RStack<T>::erase()
{
	delete[] arr;
}

template<typename T>
void RStack<T>::copy(const T* other)
{
	for (size_t i = 0; i < capacity; i++)
	{
		arr[i] = other[i];
	}
}

template<typename T>
void RStack<T>::copyStack(const RStack& other)
{
	topIndex = other.topIndex;
	capacity = other.capacity;
	if (arr != nullptr) 
	{
		erase();
	}
	arr == new T[capacity];
	copy(other.arr);
}

template<typename T>
void RStack<T>::resize()
{
	T* temp = arr;
	arr = new T[capacity * 2];
	copy(temp);
	capacity *= 2;
	delete[] temp;
}

template<typename T>
RStack<T>::RStack() : topIndex{-1}, capacity{INITIAL_CAPACITY}
{
	arr = new T[capacity];
}

template<typename T>
RStack<T>::RStack(const RStack& other)
{
	copyStack(other);
}

template<typename T>
RStack<T>& RStack<T>::operator=(const RStack& other)
{
	if (this != &other)
	{
		erase();
		copyStack(other);
	}
	return *this;
}

template<typename T>
RStack<T>::RStack(RStack&& other)
{
}

template<typename T>
RStack<T>& RStack<T>::operator=(RStack&& other)
{
}

template<typename T>
RStack<T>::~RStack()
{
	erase();
}

template<typename T>
bool RStack<T>::empty()
{
	return topIndex == -1;
}

template<typename T>
void RStack<T>::push(const T& element)
{
	if (full())
	{
		resize();
	}
	arr[++topIndex] = element;
}

template<typename T>
T RStack<T>::pop()
{
	if (empty())
	{
		std::cerr << "The stack is empty, you cannot pop an element!" << std::endl;
		return T();
	}
	return arr[topIndex--];
}

template<typename T>
T RStack<T>::top() const
{
	if (empty())
	{
		std::cerr << "The stack is empty!" << std::endl;
	}
	return arr[topIndex];
}
