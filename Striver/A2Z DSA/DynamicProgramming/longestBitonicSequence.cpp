#include "bits/stdc++.h"
using namespace std;

int longestBitonicSequence(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int> dp1(n, 1);

    for (int idx = 0; idx < n; idx++)
    {
        for (int prev = 0; prev < idx; prev++)
        {
            if (arr[prev] < arr[idx] && 1 + dp1[prev] > dp1[idx])
            {
                dp1[idx] = 1 + dp1[prev];
            }
        }
    }

    vector<int> dp2(n, 1);

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int prev = n - 1; prev > idx; prev--)
        {
            if (arr[prev] < arr[idx] && 1 + dp2[prev] > dp2[idx])
            {
                dp2[idx] = 1 + dp2[prev];
            }
        }
    }

    vector<int> bitonic(n, 0);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        bitonic[i] = dp1[i] + dp2[i] - 1;
        res = max(res, bitonic[i]);
    }

    return res;
}

int main()
{

    return 0;
}