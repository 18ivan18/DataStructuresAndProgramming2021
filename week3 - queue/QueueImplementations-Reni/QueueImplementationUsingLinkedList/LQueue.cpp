#include "LQueue.h"

template<typename T>
void LQueue<T>::copyQueue(const LQueue<T>& other)
{
	front = back = nullptr;

	QueueElement<T>* newElement = other.front();
	while (newElement)
	{
		push(newElement->data);
		newElement = newElement->next;
	}
}

template<typename T>
void LQueue<T>::eraseQueue()
{
	while (!empty())
	{
		pop();
	}
}

template<typename T>
LQueue<T>::LQueue() : front{nullptr}, back{nullptr}
{
}

template<typename T>
LQueue<T>::LQueue(const LQueue<T>& other)
{
	copyQueue(other);
}

template<typename T>
LQueue<T>& LQueue<T>::operator=(const LQueue<T>& other)
{
	if (this != &other)
	{
		eraseQueue();
		copyQueue(other);
	}
	return *this;
}

template<typename T>
LQueue<T>::LQueue(LQueue&& other)
{
	front = other.front;
	back = other.back;
	front = nullptr;
	back = nullptr;
}

template<typename T>
LQueue<T>& LQueue<T>::operator=(LQueue&& other)
{
	if (this != &other)
	{
		eraseQueue();
		front = other.front;
		back = other.back;
		front = nullptr;
		back = nullptr;
	}
	return *this;
}

template<typename T>
LQueue<T>::~LQueue()
{
	eraseQueue();
}

template<typename T>
bool LQueue<T>::empty() const
{
	return front == nullptr;
}

template<typename T>
void LQueue<T>::push(const T& newElementData)
{
	QueueElement<T>* newElementPtr = new QueueElement<T>{ newElementData, nullptr };
	if (!empty())
	{
		back->next = newElementPtr;
	}
	else
	{
		front = newElementPtr;
	}
	back = newElementPtr;
}

template<typename T>
T LQueue<T>::pop()
{
	if (empty()) 
	{
		std::cerr << "The queue is empty, you cannot pop an element!" << std::endl;
		return T();
	}
	QueueElement<T>* deletedElementPtr = front;
	T result = head();
	front = front->next;
	if (front == nullptr)
	{
		back = nullptr;
	}
	delete deletedElementPtr;
	return result;
}

template<typename T>
T& LQueue<T>::head()
{
	if (empty()) 
	{
		std::cerr << "The queue is empty!" << std::endl;
	}
	return front->data;
}

template<typename T>
const T& LQueue<T>::head() const
{
	if (empty()) 
	{
		std::cerr << "The queue is empty!" << std::endl;
	}
	return front->data;
}
