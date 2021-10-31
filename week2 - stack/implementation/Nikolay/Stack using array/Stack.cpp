#include "Stack.h"
#include <stack>

template<typename T>
Stack<T>::Stack(int _size) : arr(new T[_size]), size(_size), topIndex(-1)
{
}

template<typename T>
Stack<T>::Stack(const Stack<T>& source)
{
	copyStack(source);
}

template<typename T>
Stack<T>::Stack(Stack<T>&& source) : size(source.size), topIndex(source.topIndex), arr(source.arr)
{
	source.arr = nullptr;
}

template<typename T>
bool Stack<T>::isFull() const
{
	return topIndex == size - 1;
}

template<typename T>
void Stack<T>::resize()
{
	T* oldArrPointer = arr;
	arr = new T[2 * size];
	copyArr(oldArrPointer);
	size *= 2;
	delete[oldArrPointer];
}

template<typename T>
void Stack<T>::copyArr(const T* src)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = src[i];
	}
}

template<typename T>
void Stack<T>::copyStack(const Stack<T> source)
{
	topIndex = source.topIndex;
	size = source.size;
	arr = new T[size];
	copyArr(source.arr);
}

template<typename T>
void Stack<T>::deleteStack()
{
	delete[] arr;
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& rhs)
{
	if (this != &rhs) {
		deleteStack();
		copyStack(rhs);
	}
	return *this;
}

template<typename T>
Stack<T>& Stack<T>::operator=(Stack<T>&& rhs)
{
	if (this != &rhs) {
		delete[] arr;
		arr = rhs.arr;
		size = rhs.size;
		topIndex = rhs.topIndex;
		rhs.arr = nullptr;
	}
	return *this;
}

template<typename T>
void Stack<T>::push(const T& x)
{
	if (isFull()) {
		resize();
	}
	else {
		arr[++topIndex] = x;
	}
}

template<typename T>
T Stack<T>::pop()
{
	T popedElement;
	if (empty()) {
		std::cout << "Stack underflow\n";
		return T();
	}
	else {
		popedElement = arr[topIndex--];
	}
	return popedElement;
}

template<typename T>
const T Stack<T>::peek(int index)
{
	T peekedElement;
	if (topIndex - index + 1 < 0) {
		std::cout << "Invalid index\n";
		return T();
	}
	else {
		peekedElement = arr[topIndex - index + 1];
	}
	return peekedElement;
}

template<typename T>
const T& Stack<T>::top() const
{
	return (empty()) ? T() : arr[topIndex];
}

template<typename T>
bool Stack<T>::empty() const
{
	return topIndex == -1;
}

template<typename T>
void Stack<T>::display() const
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << '\n';
}
