#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

const int MAX_SIZE_QUEUE = 128; // 1 << 7

template <typename T>
class Queue
{
private:
	T arr[MAX_SIZE_QUEUE];
	int front, back, currentNum;

	bool full() const;
public:
	Queue();

	bool empty() const;
	void push(const T& element);
	T pop();
	T front() const;
};

#endif // !QUEUE_H

