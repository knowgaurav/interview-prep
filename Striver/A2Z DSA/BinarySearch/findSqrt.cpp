#include "bits/stdc++.h"
using namespace std;

int floorSqrt(int n)
{
    // Write your code here.
    int low = 1, high = n;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (mid <= n / mid)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return high;
}

int main()
{

    return 0;
}