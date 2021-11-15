#pragma once

template <typename T>
class Stack
{
	T* arr;
	int size;
	int topIndex;

	bool isFull() const;
	void resize();
	void copyArr(const T* src);
	void copyStack(const Stack<T> source);
	void deleteStack();
public:
	Stack<T>(int size = 10);

	Stack<T>(const Stack<T>& source);
	Stack<T>& operator=(const Stack<T>& rhs);

	Stack<T>(Stack<T>&& source);
	Stack<T>& operator=(Stack<T>&& rhs);

	void push(const T& x);
	T pop();
	const T peek(int index);
	const T& top() const;
	bool empty() const;
	void display() const;
};


