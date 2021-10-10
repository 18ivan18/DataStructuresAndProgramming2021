#include "./Sorts/BubbleSort.cpp"
#include <vector>

int majorityElement(int *nums, int n)
{
    BubbleSort<int> bs;
    bs(nums, n);

    return nums[n / 2];
}

// Boyer-Moore Voting Algorithm
int majorityElement(std::vector<int> nums)
{
    int count = 0;
    int candidate = 0;

    for (int num : nums)
    {
        if (count == 0)
        {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }

    return candidate;
}