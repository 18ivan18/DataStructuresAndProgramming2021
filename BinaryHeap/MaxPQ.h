#ifndef MAX_PRIORITY_QUEUE
#define MAX_PRIORITY_QUEUE

template <typename T>
class MaxPQ
{
private:
    int capacity;
    int size;
    T *data;

    bool less(int, int);
    void exch(int, int);

    void swim(int);
    void sink(int);

    void resize(int);

    void del();

public:
    MaxPQ();
    ~MaxPQ();

    bool isEmpty();
    T delMax();
    void insert(const T &);
    int getSize();
    T getMax();
};

#endif
