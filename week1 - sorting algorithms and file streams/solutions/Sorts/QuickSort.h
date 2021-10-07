#include "./Sort.h"

// Worst complexity: n^2
// Average complexity: n*log(n)
// Best complexity: n*log(n)
// Is QuickSort stable?
// The default implementation is not stable. However any sorting algorithm can be made stable by considering indexes as comparison parameter.

// Is QuickSort In-place?
// As per the broad definition of in-place algorithm it qualifies as an in-place sorting algorithm as it uses extra space only for storing recursive function calls but not for manipulating the input.

template <typename T>
class QuickSort : public Sort<T>
{
private:
    int partition(T *arr, int low, int high);
    void quickSort(T *arr, int low, int high);

public:
    void operator()(T *arr, int n);
};
