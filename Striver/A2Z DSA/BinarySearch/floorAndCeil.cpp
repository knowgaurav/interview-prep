#include "bits/stdc++.h"
using namespace std;

int floor(int arr[], int n, int x)
{
    int res = -1, low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] <= x)
        {
            res = arr[mid];
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return res;
}

int ceil(int arr[], int n, int x)
{
    int res = -1, low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= x)
        {
            res = arr[mid];
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return res;
}

pair<int, int> getFloorAndCeil(int arr[], int n, int x)
{
    // Write your code here.
    sort(arr, arr + n);
    int f = floor(arr, n, x);
    int c = ceil(arr, n, x);

    return {f, c};
}

int main()
{

    return 0;
}