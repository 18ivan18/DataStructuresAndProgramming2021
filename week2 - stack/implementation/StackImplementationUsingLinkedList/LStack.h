#ifndef LSTACK_H
#define LSTACK_H

template <typename T>
struct StackElement
{
	T data;
	StackElement<T>* next;
};

template <typename T>
class LStack
{
private:
	StackElement<T>* topPtr;

	void copy(const LStack& other);
	void erase();
public:
	LStack();;
	LStack(const LStack& other);
	LStack& operator=(const LStack& other);
	LStack(LStack&& other);
	LStack& operator=(LStack&& other);
	~LStack();

	bool empty();
	void push(const T& element);
	T pop();
	const T& top() const;   
	T& top();
};

#endif 


