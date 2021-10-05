#include <iostream>
#include <algorithm> // std::random_shuffle
#include "BubbleSort.cpp"
#include "InsertionSort.cpp"
#include "SelectionSort.cpp"
#include "MergeSort.cpp"
#include "QuickSort.cpp"

template <typename T>
void print(const T *arr, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, size = sizeof(arr) / sizeof(arr[0]);
    std::random_shuffle(arr, arr + size);
    print(arr, size);
    BubbleSort<int> bubbleSort;
    bubbleSort(arr, size);
    print(arr, size);

    std::random_shuffle(arr, arr + size);
    print(arr, size);
    InsertionSort<int> insertionSort;
    insertionSort(arr, size);
    print(arr, size);

    std::random_shuffle(arr, arr + size);
    print(arr, size);
    SelectionSort<int> selectionSort;
    selectionSort(arr, size);
    print(arr, size);

    std::random_shuffle(arr, arr + size);
    print(arr, size);
    MergeSort<int> mergeSort;
    mergeSort(arr, size);
    print(arr, size);

    std::random_shuffle(arr, arr + size);
    print(arr, size);
    QuickSort<int> quickSort;
    quickSort(arr, size);
    print(arr, size);
}