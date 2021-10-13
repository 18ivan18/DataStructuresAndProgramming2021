#ifndef STACK
#define STACK

template <typename T>
class Stack
{
private:
    /* data */
public:
    Stack(/* args */);
    void push(T);
    T peek();
    void pop();
    bool isEmpty();
    int size();
    ~Stack();
};

#endif