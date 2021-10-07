#include <iostream>
#include <cassert>
#include <cstring>
#include "./Sorts/BubbleSort.cpp"

int missingNumber(int *arr, int n)
{
    BubbleSort<int> bs;
    bs(arr, n);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i)
        {
            return i;
        }
    }
    return n;
}

int main()
{
    int arr[] = {3, 0, 1}, size = sizeof(arr) / sizeof(arr[0]);
    assert(missingNumber(arr, size) == 2);
    int arr1[] = {0, 1}, size1 = sizeof(arr1) / sizeof(arr1[0]);
    assert(missingNumber(arr1, size1) == 2);
    int arr2[] = {9, 6, 4, 2, 3, 5, 7, 0, 1}, size2 = sizeof(arr2) / sizeof(arr2[0]);
    assert(missingNumber(arr2, size2) == 8);
    int arr3[] = {0}, size3 = sizeof(arr3) / sizeof(arr3[0]);
    assert(missingNumber(arr3, size3) == 1);
}