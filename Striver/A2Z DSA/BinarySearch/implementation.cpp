#include "bits/stdc++.h"
using namespace std;

int search(vector<int> &nums, int target)
{
    // Write Your Code Here
    int low = 0, high = nums.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int binarySearch(int low, int high, vector<int> &nums, int target)
{
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;
    if (nums[mid] == target)
        return mid;
    else if (nums[mid] < target)
        return binarySearch(mid + 1, high, nums, target);
    else
        return binarySearch(low, mid - 1, nums, target);
}

int search(vector<int> &nums, int target)
{
    // Write Your Code Here
    return binarySearch(0, nums.size() - 1, nums, target);
}