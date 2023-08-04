#include "bits/stdc++.h"
using namespace std;

int getMinInRotatedSortedArr(vector<int> &arr)
{
    int res = INT_MAX, resIdx = -1, low = 0, high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[low] <= arr[mid])
        {
            if (arr[low] <= res)
            {
                res = arr[low];
                resIdx = low;
            }
            low = mid + 1;
        }
        else
        {
            if (arr[mid] <= res)
            {
                res = arr[mid];
                resIdx = mid;
            }
            high = mid - 1;
        }
    }

    return resIdx;
}

int findKRotation(vector<int> &arr)
{
    // Write your code here.
    int minEleIdx = getMinInRotatedSortedArr(arr);
    return minEleIdx;
}

int main()
{

    return 0;
}