#include "./MergeSort.h"

template <typename T>
void MergeSort<T>::merge(T *array, int const left, int const mid, int const right)
{
    const T subArrayOne = mid - left + 1;
    const T subArrayTwo = right - mid;

    // Create temp arrays
    T *leftArray = new int[subArrayOne],
      *rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (size_t i = 0; i < subArrayOne; i++)
    {
        leftArray[i] = array[left + i];
    }
    for (size_t i = 0; i < subArrayTwo; i++)
    {
        rightArray[i] = array[mid + 1 + i];
    }

    int indexOfSubArrayOne = 0,    // Initial index of first sub-array
        indexOfSubArrayTwo = 0;    // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
        {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

template <typename T>
void MergeSort<T>::mergeSort(T *array, const int begin, const int end)
{
    if (begin >= end)
    {
        return; // Returns recursively
    }

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

template <typename T>
void MergeSort<T>::operator()(T *arr, int n)
{
    mergeSort(arr, 0, n - 1);
}
