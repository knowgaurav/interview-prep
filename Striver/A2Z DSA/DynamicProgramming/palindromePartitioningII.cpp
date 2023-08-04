#include "bits/stdc++.h"
using namespace std;

/*
    Time Complexity : O(N^2)
    Space Complexity : O(N) + O(N)
*/

bool isPalindrome(int i, int j, string &str)
{
    while (j >= i)
    {
        if (str[j] != str[i])
            return false;

        i++;
        j--;
    }

    return true;
}

int helper(int i, string &str, vector<int> &dp)
{
    if (i == str.length())
        return 0;
    if (dp[i] != -1)
        return dp[i];

    int res = INT_MAX;

    for (int j = i; j < str.length(); j++)
    {
        int cost = INT_MAX;
        if (isPalindrome(i, j, str))
        {
            cost = 1 + helper(j + 1, str, dp);
            res = min(res, cost);
        }
    }

    return dp[i] = res;
}

int palindromePartitioning(string str)
{
    // Write your code here
    int n = str.length();
    vector<int> dp(n + 1, -1);

    return helper(0, str, dp) - 1;
}

/*
    Time Complexity : O(N^2)
    Space Complexity : O(N)
*/

int palindromePartitioning(string str)
{
    // Write your code here
    int n = str.length();
    vector<int> dp(n + 1, 0);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        int res = INT_MAX;

        for (int j = i; j < n; j++)
        {
            if (isPalindrome(i, j, str))
            {
                int cost = 1 + dp[j + 1];
                res = min(res, cost);
            }
        }

        dp[i] = res;
    }

    return dp[0] - 1;
}

int main()
{

    return 0;
}