#include "bits/stdc++.h"
using namespace std;

int firstOccurence(vector<int> &arr, int n, int x)
{
    int res = n, low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
        {
            res = mid;
            high = mid - 1;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return res;
}

int lastOccurence(vector<int> &arr, int n, int x)
{
    int res = n, low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
        {
            res = mid;
            low = mid + 1;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return res;
}

int count(vector<int> &arr, int n, int x)
{
    // Write Your Code Here
    int first = firstOccurence(arr, n, x);
    if (first == n)
        return 0;

    int last = lastOccurence(arr, n, x);

    return last - first + 1;
}

int main()
{

    return 0;
}