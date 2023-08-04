#include "bits/stdc++.h"
using namespace std;

int search(vector<int> &arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    int res = -1, low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == k)
            return mid;
        // Left is sorted
        else if (arr[low] <= arr[mid])
        {
            // check whether target is present in the sorted range
            if (arr[low] <= k && arr[mid] >= k)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            // check whether target is present in the sorted range
            if (arr[mid] <= k && arr[high] >= k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }

    return res;
}

int main()
{

    return 0;
}