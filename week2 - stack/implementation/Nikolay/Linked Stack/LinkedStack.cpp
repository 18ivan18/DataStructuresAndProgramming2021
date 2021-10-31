#include "LinkedStack.h"

template<typename T>
void LinkedStack<T>::emptyStack()
{
	while (!topPtr) {
		Node<T>* node = topPtr;
		topPtr = topPtr->next;
		delete node;
	}
}

template<typename T>
void LinkedStack<T>::copyStack(const LinkedStack<T>& src)
{
	Node<T>* p = src.top();
	Node<T>* temp = new Node<T>;
	temp->data = p->data;
	top = temp;
	Node<T>* tail = temp;
	while (p->next != nullptr) {
		p = p->next;
		temp = new Node<T>;
		temp.data = p->data;
		tail->next = temp;
		tail = temp;
	}
}

template<typename T>
LinkedStack<T>& LinkedStack<T>::operator=(const LinkedStack<T>& rhs)
{
	if (this != &rhs) {
		emptyStack();
		copyStack(rhs);
	}
	return *this;
}

template<typename T>
LinkedStack<T>& LinkedStack<T>::operator=(LinkedStack<T>&& rhs)
{
	if (this != &rhs) {
		topPtr = nullptr;
		topPtr = rhs.topPtr;
		rhs.topPtr = nullptr;
	}
	return *this;
}

template<typename T>
void LinkedStack<T>::push(const T& x)
{
	Node<T>* newElemPtr = new Node<T>;
	newElemPtr->data = x;
	newElemPtr->next = topPtr;
	topPtr = newElemPtr;
}

template<typename T>
T LinkedStack<T>::pop()
{
	if (empty()) {
		std::cerr << "Stack underflow\n";
		return T();
	}
	
	T poppedElem = top();

	Node<T>* tempElemPtr = topPtr;
	
	topPtr = topPtr->next;

	delete tempElemPtr;

	return poppedElem;
}

template<typename T>
const T& LinkedStack<T>::top() const
{
	if (empty()) {
		std::cerr << "Stack is empty\n";
		return T();
	}
	return topPtr->data;
}

template<typename T>
bool LinkedStack<T>::empty() const
{
	return topPtr == nullptr;
}


template<typename T>
LinkedStack<T>::LinkedStack() : topPtr(nullptr)
{
}

template<typename T>
LinkedStack<T>::LinkedStack(const LinkedStack<T>& src)
{
	if (src.empty()) {
		top = nullptr;
	}
	else {
		copyStack(src);
	}
}

template<typename T>
LinkedStack<T>::LinkedStack(LinkedStack<T>&& src)
{
	topPtr = src.topPtr;
	src.topPtr = nullptr;
}

template<typename T>
LinkedStack<T>::~LinkedStack()
{
	emptyStack();
}
