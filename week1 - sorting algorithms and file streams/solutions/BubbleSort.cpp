#include "./BubbleSort.h"

template <typename T>
void BubbleSort<T>::operator()(T *arr, int n)
{
    bool swapped;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                this->swap(arr + j, arr + j + 1);
                swapped = true;
            }
        }
        // optimization: The above function always runs O(n^2) time even if the array is sorted.
        if (!swapped)
        {
            break;
        }
    }
}
