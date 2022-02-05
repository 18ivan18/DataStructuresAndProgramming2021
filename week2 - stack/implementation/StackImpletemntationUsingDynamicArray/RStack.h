#ifndef RSTACK_H
#define RSTACK_H

const int INITIAL_CAPACITY = 16;

template <typename T>
class RStack
{
private:
	T* arr;
	int topIndex;
	int capacity;

	bool full() const;

	void erase();
	void copy(const T* other);
	void copyStack(const RStack& other);

	void resize();
public:
	RStack();
	RStack(const RStack& other);
	RStack& operator=(const RStack& other);
	RStack(RStack&& other);
	RStack& operator=(RStack&& other);
	~RStack();

	bool empty();
	void push(const T& element);
	T pop();
	T top() const;
};

#endif 
