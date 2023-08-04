#include "bits/stdc++.h"
using namespace std;

int findMin(vector<int> &arr)
{
    // Write your code here.
    int low = 0, high = arr.size() - 1, res = INT_MAX;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // Means this is sorted
        if (arr[low] <= arr[mid])
        {
            res = min(res, arr[low]);
            low = mid + 1;
        }
        else
        {
            res = min(res, arr[mid]);
            high = mid - 1;
        }
    }

    return res;
}

int main()
{

    return 0;
}