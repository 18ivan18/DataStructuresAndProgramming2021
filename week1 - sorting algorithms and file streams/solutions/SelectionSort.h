#include "./Sort.h"

// Time Complexity: O(n^2) as there are two nested loops.
// Auxiliary Space: O(1)
// The good thing about selection sort is it never makes more than O(n) swaps and can be useful when memory write is a costly operation.
// Stability: The default implementation is not stable. However it can be made stable.
// In Place: Yes, it does not require extra space.

template <typename T>
class SelectionSort : public Sort<T>
{
public:
    void operator()(T *arr, int n);
};
