#include <iostream>

bool isOdd(int n)
{
    return n % 2;
}

/*
    
    Notice that we added a counter to count how many times the inner block is executed.
    If you get the time complexity, it would be something like this:
    Line 2-3: 2 operations
    Line 4: a loop of size n
    Line 6-8: 3 operations inside the for-loop.
    So, this gets us 3(n) + 2.
*/

int findMax(int *arr, int n)
{
    int max;
    int counter = 0;

    for (size_t i = 0; i < n; i++)
    {
        counter++;
        if (max < arr[i])
        {
            max = arr[i];
        }
    }

    std::cout << "n: " << n << " counter: " << counter << std::endl;
    return max;
}
/*
Time complexity analysis:
Line 2-3: 2 operations
Line 5-6: double-loop of size n, so n^2.
Line 7-13: has ~3 operations inside the double-loop
We get 3n^2 + 2.
When we have an asymptotic analysis, we drop all constants and leave the most critical term: n^2. So, in the big O notation, it would be O(n^2).
*/

bool hasDuplicates(int *arr, int n)
{
    int counter = 0; // debug

    for (size_t outter = 0; outter < n; outter++)
    {
        for (size_t inner = 0; inner < n; inner++)
        {
            counter++; // debug

            if (outter == inner)
                continue;

            if (arr[outter] == arr[inner])
            {
                return true;
            }
        }
    }

    std::cout << "n: " << n << " counter: " << counter << std::endl; // debug
    return false;
}

void findXYZ(int *arr, int n)
{

    for (size_t x = 0; x < n; x++)
    {
        for (size_t y = 0; y < n; y++)
        {
            for (size_t z = 0; z < n; z++)
            {
                if (3 * x + 9 * y + 8 * z == 79)
                {
                    std::cout << x << " " << y << " " << z << std::endl;
                }
            }
        }
    }
}

#include <cstring>

// index of in sorted array
int binarySearch(char **arr, int l, int r, char *x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (strcmp(arr[mid], x) == 0)
        {
            return mid;
        }

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (strcmp(arr[mid], x) > 0)
        {
            return binarySearch(arr, l, mid - 1, x);
        }

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }

    // We reach here when element is not
    // present in array
    return -1;
}
