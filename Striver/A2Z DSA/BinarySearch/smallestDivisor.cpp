#include "bits/stdc++.h"
using namespace std;

int divisionResult(vector<int> &arr, int divisor)
{
    int res = 0;

    for (int num : arr)
    {
        res += ceil((double)num / (double)divisor);
    }

    return res;
}

int smallestDivisor(vector<int> &arr, int limit)
{
    // Write your code here.
    int res = -1;
    int low = 1, high = *max_element(arr.begin(), arr.end());

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (divisionResult(arr, mid) <= limit)
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

int main()
{

    return 0;
}