#pragma once
#include "Node.h"

template <typename T>
class LinkedStack
{
	Node<T>* topPtr;
	void emptyStack();
	void copyStack(const LinkedStack<T>& src);
public:
	LinkedStack<T>();

	LinkedStack<T>(const LinkedStack<T>& src);
	LinkedStack<T>& operator=(const LinkedStack<T>& rhs);

	LinkedStack<T>(LinkedStack<T>&& src);
	LinkedStack<T>& operator=(LinkedStack<T>&& rhs);
	~LinkedStack<T>();

	void push(const T& x);
	T pop();
	const T peek(int index);
	const T& top() const;
	bool empty() const;
};

