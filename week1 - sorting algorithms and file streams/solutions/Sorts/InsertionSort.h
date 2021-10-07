#include "./Sort.h"

template <typename T>
class InsertionSort : public Sort<T>
{
public:
    void operator()(T *arr, int n);
};
