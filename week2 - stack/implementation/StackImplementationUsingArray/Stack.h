#ifndef STACK_H
#define STACK_H

const int MAX_STACK_SIZE = 128; // 1 << 7

template <typename T>
class Stack
{
private:
	T arr[MAX_STACK_SIZE];
	int topIndex;

	bool full() const;
public:
	Stack();

	bool empty() const;
	void push(const T& element);
	T pop();
	T top() const;
};

#endif 