#include "./SelectionSort.h"

template <typename T>
void SelectionSort<T>::operator()(T *arr, int n)
{
    int minIndex;

    // One by one move boundary of unsorted subarray
    for (size_t i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        minIndex = i;
        for (size_t j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element
        this->swap(arr + minIndex, arr + i);
    }
}
