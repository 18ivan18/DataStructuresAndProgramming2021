#ifndef LQUEUE_H
#define LQUEUE_H
#include <iostream>

template <typename T>
struct QueueElement
{
	T data;
	QueueElement<T>* next;
};

template <typename T>
class LQueue
{
private:
	QueueElement<T>* front, * back;

	void copyQueue(const LQueue<T>& other);
	void eraseQueue();
public:
	LQueue();
	LQueue(const LQueue<T>& other);
	LQueue& operator=(const LQueue<T>& other);
	LQueue(LQueue&& other);
	LQueue& operator=(LQueue&& other);
	~LQueue();

	bool empty() const;
	void push(const T& element);
	T pop();
	T& head();
	const T& head() const;
};

#endif // !LQUEUE_H


