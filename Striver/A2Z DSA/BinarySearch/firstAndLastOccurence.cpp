#include "bits/stdc++.h"
using namespace std;

int lowerBound(vector<int> &arr, int n, int k)
{
    int res = n, low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= k)
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return res;
}

int upperBound(vector<int> &arr, int n, int k)
{
    int res = n, low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] > k)
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return res;
}

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{
    // Write your code here
    int lb = lowerBound(arr, n, k);
    if ((lb == n) || (arr[lb] != k))
        return {-1, -1};
    int ub = upperBound(arr, n, k);

    return {lb, ub - 1};
}

int main()
{

    return 0;
}