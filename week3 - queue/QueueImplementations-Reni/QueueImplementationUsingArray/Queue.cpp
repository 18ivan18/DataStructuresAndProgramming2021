#include "Queue.h"

template<typename T>
bool Queue<T>::full() const
{
	return currentNum == MAX_SIZE_QUEUE;
}

template<typename T>
Queue<T>::Queue() : front{0}, back{0}, currentNum{0}
{
}

template<typename T>
bool Queue<T>::empty() const
{
	return currentNum == 0;
}

template<typename T>
void Queue<T>::push(const T& element)
{
	if (full())
	{
		std::cout << "The queue is full, you cannot push an element" << std::endl;
		return;
	}
	arr[back] = element;
	currentNum++;
	back++;
	back = back % MAX_SIZE_QUEUE;
}

template<typename T>
T Queue<T>::pop()
{
	if (empty())
	{
		std::cout << "The queue is empty, you cannot pop an element" << std::endl;
		return T();
	}
	T element = arr[front];
	currentNum--;
	front--;
	front = front % MAX_SIZE_QUEUE;
	return element;
}

template<typename T>
T Queue<T>::front() const
{
	if (empty())
	{
		std::cerr << "The queue is empty!" << std::endl;
		return T();
	}
	return arr[front];
}
