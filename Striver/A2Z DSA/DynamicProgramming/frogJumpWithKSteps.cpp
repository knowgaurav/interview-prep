#include "bits/stdc++.h"
using namespace std;

/*
    Time Complexity : O(N*K)
    Space Complexity : O(N) + O(N)
*/

int helper(int idx, int K, vector<int> &heights, vector<int> &dp)
{
    if (idx == 0)
    {
        return 0;
    }

    if (dp[idx] != -1)
        return dp[idx];

    int minSteps = INT_MAX;

    for (int j = 1; j <= K; j++)
    {
        int jump = INT_MAX;
        if (idx - j >= 0)
        {
            jump = helper(idx - j, K, heights, dp) + abs(heights[idx] - heights[idx - j]);
        }
        minSteps = min(minSteps, jump);
    }

    return dp[idx] = minSteps;
}

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> heights(N, 0);
    for (int i = 0; i < N; i++)
        cin >> heights[i];

    vector<int> dp(N, -1);

    cout << helper(N - 1, K, heights, dp) << endl;

    return 0;
}