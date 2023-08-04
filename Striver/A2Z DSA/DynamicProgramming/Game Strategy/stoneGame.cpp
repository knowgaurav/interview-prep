#include "bits/stdc++.h"
using namespace std;

class Solution
{
private:
    int n;

    int helper(int l, int r, vector<int> &piles, bool turn, vector<vector<int>> &dp)
    {
        if (l >= r)
            return 0;

        if (dp[l][r] != -1)
        {
            return dp[l][r];
        }

        int v1 = helper(l + 1, r, piles, !turn, dp);
        int v2 = helper(l, r - 1, piles, !turn, dp);

        if (turn)
        {
            return dp[l][r] = max(piles[l] + v1, piles[r] + v2);
        }
        else
        {
            return dp[l][r] = min(v1, v2);
        }
    }

public:
    bool stoneGame(vector<int> &piles)
    {
        n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        int aliceStones = helper(0, n - 1, piles, true, dp);
        int totalStones = accumulate(begin(piles), end(piles), 0);
        int bobStones = totalStones - aliceStones;

        if (aliceStones > bobStones)
            return true;
        return false;
    }
};

int main()
{

    return 0;
}