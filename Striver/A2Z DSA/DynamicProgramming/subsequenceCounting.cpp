#include "bits/stdc++.h"
using namespace std;

int mod = (int)1e9 + 7;

int helper(int i, int j, string &t, string &s, vector<vector<int>> &dp)
{
    if (j < 0)
        return 1;
    if (i < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (t[i] == s[j])
    {
        return dp[i][j] = (helper(i - 1, j - 1, t, s, dp) + helper(i - 1, j, t, s, dp)) % mod;
    }

    return dp[i][j] = helper(i - 1, j, t, s, dp) % mod;
}

int subsequenceCounting(string &t, string &s, int lt, int ls)
{
    // Write your code here.
    vector<vector<int>> dp(lt, vector<int>(ls, -1));

    return helper(lt - 1, ls - 1, t, s, dp);
}

int subsequenceCounting(string &t, string &s, int lt, int ls)
{
    // Write your code here.
    vector<vector<int>> dp(lt + 1, vector<int>(ls + 1, 0));

    for (int i = 0; i <= lt; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= lt; i++)
    {
        for (int j = 1; j <= ls; j++)
        {
            if (t[i - 1] == s[j - 1])
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
            }
            else
            {
                dp[i][j] = (dp[i - 1][j]) % mod;
            }
        }
    }

    return dp[lt][ls];
}

int subsequenceCounting(string &t, string &s, int lt, int ls)
{
    // Write your code here.
    vector<int> prev(lt + 1, 0);

    prev[0] = 1;

    for (int i = 1; i <= lt; i++)
    {
        vector<int> curr(lt + 1, 0);
        curr[0] = 1;

        for (int j = 1; j <= ls; j++)
        {
            if (t[i - 1] == s[j - 1])
            {
                curr[j] = (prev[j - 1] + prev[j]) % mod;
            }
            else
            {
                curr[j] = (prev[j]) % mod;
            }
        }

        prev = curr;
    }

    return prev[ls];
}

int main()
{

    return 0;
}