#include "bits/stdc++.h"
using namespace std;

/*
    Time Complexity : O(N^2) + O(N)
    Space Complexity : O(N)
*/

vector<int> divisibleSet(vector<int> &arr)
{
    // Write your code here.
    int n = arr.size();
    vector<int> dp(n + 1, 1), hash(n);
    int res = 0, lastIdx = -1;

    sort(begin(arr), end(arr));

    for (int idx = 0; idx < n; idx++)
    {
        hash[idx] = idx;

        for (int prev = 0; prev < idx; prev++)
        {
            if (arr[idx] % arr[prev] == 0 && 1 + dp[prev] > dp[idx])
            {
                dp[idx] = 1 + dp[prev];
                hash[idx] = prev;
            }
        }

        if (dp[idx] > res)
        {
            res = dp[idx];
            lastIdx = idx;
        }
    }

    vector<int> temp;
    temp.push_back(arr[lastIdx]);

    while (hash[lastIdx] != lastIdx)
    {
        lastIdx = hash[lastIdx];
        temp.push_back(arr[lastIdx]);
    }

    reverse(begin(temp), end(temp));
    return temp;
}

int main()
{

    return 0;
}