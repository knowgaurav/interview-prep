#include "bits/stdc++.h"
using namespace std;

/*
    Time Complexity : O(n*log(max_element))
    Space Complexity : O(1)
*/

int helper(int m, vector<int> &v)
{
    int totalTime = 0;

    for (int b : v)
    {
        totalTime += ceil((double)b / (double)m);
    }

    return totalTime;
}

int minimumRateToEatBananas(vector<int> v, int h)
{
    // Write Your Code Here
    int low = 1, high = *max_element(begin(v), end(v)), ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (helper(mid, v) <= h)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{

    return 0;
}