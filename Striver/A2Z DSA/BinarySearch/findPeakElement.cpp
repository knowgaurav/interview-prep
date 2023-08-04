#include "bits/stdc++.h"
using namespace std;

int findPeakElement(vector<int> &arr)
{
    // Write your code here
    int n = arr.size();

    if (n == 1)
        return 0;
    if (arr[0] > arr[1])
        return 0;
    if (arr[n - 1] > arr[n - 2])
        return n - 1;

    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1])
        {
            return i;
        }
    }

    return 0;
}

/*
    Time Complexity : O(logN)
    Space Complexity : O(1)
*/

int findPeakElement(vector<int> &arr)
{
    // Write your code here
    int n = arr.size();

    if (n == 1)
        return 0;
    if (arr[0] > arr[1])
        return 0;
    if (arr[n - 1] > arr[n - 2])
        return n - 1;

    int low = 1, high = arr.size() - 2;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        else if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{

    return 0;
}