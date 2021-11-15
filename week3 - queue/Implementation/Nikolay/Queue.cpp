#pragma once

template <typename T>
struct QueueElement {
	T data;
	QueueElement<T>* next;
};

template <typename T>
class LinkedQueue {
private:
	QueueElement<T>* front, * back;

	void copyQueue(const LinkedQueue<T>& src);
	void eraseQueue();

public:
	LinkedQueue();

	LinkedQueue(const LinkedQueue<T>& src);

	LinkedQueue& operator=(const LinkedQueue<T>& rhs);

	LinkedQueue(LinkedQueue<T>&& src);
	LinkedQueue& operator=(LinkedQueue<T>&& rhs);

	~LinkedQueue();

	bool empty() const;
	void push(const T& x);
	T pop();
	T& head();
	const T& head() const;
};

template<typename T>
void LinkedQueue<T>::copyQueue(const LinkedQueue<T>& src)
{
	QueueElement<T>* elemPtr = src.front;
	while (elemPtr) {
		push(elemPtr->data);
		elemPtr = elemPtr->next;
	}
}

template<typename T>
void LinkedQueue<T>::eraseQueue()
{
	while (!empty()) {
		pop();
	}
}

template<typename T>
LinkedQueue<T>::LinkedQueue() : front{nullptr}, back{nullptr}
{
}

template<typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& src)
{
	copyQueue(queue);
}

template<typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& rhs)
{
	if (this != &queue) {
		eraseQueue();
		copyQueue(queue);
	}
	return *this;
}

template<typename T>
LinkedQueue<T>::LinkedQueue(LinkedQueue<T>&& src) : front{ src.front }, back{ src.back }
{
	src.front = nullptr;
	src.back = nullptr;
}

template<typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(LinkedQueue<T>&& rhs)
{
	if (this != &rhs) {
		front = rhs.front;
		back = rhs.back;
		rhs.front = nullptr;
		rhs.back = nullptr;
	}
	return *this;
}

template<typename T>
LinkedQueue<T>::~LinkedQueue()
{
	eraseQueue();
}

template<typename T>
bool LinkedQueue<T>::empty() const
{
	return front == nullptr;
}

template<typename T>
void LinkedQueue<T>::push(const T& x)
{
	QueueElement<T>* newElemPtr = new QueueElement<T>;
	newElemPtr->data = newElemData;
	newElemPtr->next = nullptr;

	if (!empty()) {
		back->next = newElemPtr;
	}
	else {
		front = newElemPtr;
	}

	back = newElemPtr;
}

template<typename T>
T LinkedQueue<T>::pop()
{
	if (empty()) {
		std::cerr << "The queue is empty!" << std::endl;
		return T();
	}

	QueueElement<T>* delElemPtr = front;
	T result = head();

	front = front->next;

	if (front == nullptr) {
		back = nullptr;
	}
	delete delElemPtr;

	return result;
}

template<typename T>
T& LinkedQueue<T>::head()
{
	if (empty()) {
		std::cerr << "The queue is empty!" << std::endl;
	}

	return front->data;
}

template<typename T>
const T& LinkedQueue<T>::head() const
{
	if (empty()) {
		std::cerr << "The queue is empty!" << std::endl;
	}

	return front->data;
}
