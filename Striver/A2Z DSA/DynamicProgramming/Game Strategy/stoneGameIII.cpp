#include "bits/stdc++.h"
using namespace std;

class Solution
{

    /*
        Time Complexity : O(N)
        Space Complexity : O(N)
    */

private:
    int n;
    vector<int> dp;

    int helper(int idx, vector<int> &stoneValue)
    {
        if (idx >= n)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int result = stoneValue[idx] - helper(idx + 1, stoneValue);

        if (idx + 1 < n)
            result = max(result, stoneValue[idx] + stoneValue[idx + 1] - helper(idx + 2, stoneValue));

        if (idx + 2 < n)
            result = max(result, stoneValue[idx] + stoneValue[idx + 1] + stoneValue[idx + 2] - helper(idx + 3, stoneValue));

        return dp[idx] = result;
    }

public:
    string stoneGameIII(vector<int> &stoneValue)
    {
        n = stoneValue.size();
        dp.resize(n + 1, -1);

        int diff = helper(0, stoneValue);

        if (diff > 0)
            return "Alice";
        else if (diff < 0)
            return "Bob";

        return "Tie";
    }
};

int main()
{

    return 0;
}