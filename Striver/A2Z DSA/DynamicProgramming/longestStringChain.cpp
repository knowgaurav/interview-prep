#include "bits/stdc++.h"
using namespace std;

bool compareStrs(string &s1, string &s2)
{
    if (s1.size() != s2.size() + 1)
        return false;

    int i = 0, j = 0;

    while (i < s1.size())
    {
        if (s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }

    if (i == s1.size() and j == s2.size())
        return true;
    return false;
}

bool comp(string &s1, string &s2)
{
    return s1.size() < s2.size();
}

int longestStrChain(vector<string> &arr)
{
    // Write your code here.
    sort(begin(arr), end(arr), comp);
    int n = arr.size();
    vector<int> dp(n, 1);

    int res = 0;

    for (int idx = 0; idx < n; idx++)
    {
        for (int prev = 0; prev < idx; prev++)
        {
            if (compareStrs(arr[idx], arr[prev]) and 1 + dp[prev] > dp[idx])
            {
                dp[idx] = 1 + dp[prev];
            }
        }

        res = max(res, dp[idx]);
    }

    return res;
}

int main()
{

    return 0;
}