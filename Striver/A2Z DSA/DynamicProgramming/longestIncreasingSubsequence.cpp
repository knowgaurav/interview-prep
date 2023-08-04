#include "bits/stdc++.h"
using namespace std;

/*
    Time Complexity : O(N^2)
    Space Complexity : O(N)
*/

int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<int> dp(n + 1, 1);
    int res = 1;

    for (int idx = 0; idx < n; idx++)
    {
        for (int prev = 0; prev < idx; prev++)
        {
            if (arr[prev] < arr[idx])
            {
                dp[idx] = max(dp[idx], 1 + dp[prev]);
            }

            res = max(res, dp[idx]);
        }
    }

    return res;
}

int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<int> dp(n + 1, 1), hash(n);
    int res = 1, lastIdx = -1;

    for (int idx = 0; idx < n; idx++)
    {
        hash[idx] = idx;

        for (int prev = 0; prev < idx; prev++)
        {
            if (arr[prev] < arr[idx] && dp[idx] < 1 + dp[prev])
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

    vector<int> printLIS;
    printLIS.push_back(arr[lastIdx]);

    while (hash[lastIdx] != lastIdx)
    {
        lastIdx = hash[lastIdx];
        printLIS.push_back(arr[lastIdx]);
    }

    reverse(printLIS.begin(), printLIS.end());

    for (int ele : printLIS)
    {
        cout << ele << " ";
    }

    cout << endl;

    return res;
}

/*
    Time Complexity : O(N*logN)
    Space Complexity : O(N)
*/

int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<int> temp;
    temp.push_back(arr[0]);

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > temp.back())
        {
            temp.push_back(arr[i]);
        }
        else
        {
            int idx = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[idx] = arr[i];
        }
    }

    return temp.size();
}

int main()
{

    return 0;
}