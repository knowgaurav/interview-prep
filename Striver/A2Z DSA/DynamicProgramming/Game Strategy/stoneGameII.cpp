#include "bits/stdc++.h"
using namespace std;

class Solution
{

    /*
        Time Complexity : O(n^3)
        Space Complexity : O(1)
    */

private:
    int n;
    int dp[2][101][101];

    int solveForAlice(int i, int player, int M, vector<int> &piles)
    {
        if (i >= n)
            return 0;

        if (dp[player][i][M] != -1)
            return dp[player][i][M];

        int stones = 0, result;
        result = (player == 1) ? -1 : INT_MAX;

        for (int X = 1; X <= min(2 * M, n - i); X++)
        {
            if (player == 1)
            {
                stones += piles[i + X - 1];

                result = max(result, stones + solveForAlice(i + X, 0, max(M, X), piles));
            }
            else
            {
                result = min(result, solveForAlice(i + X, 1, max(M, X), piles));
            }
        }

        return dp[player][i][M] = result;
    }

public:
    int stoneGameII(vector<int> &piles)
    {
        n = piles.size();
        memset(dp, -1, sizeof(dp));

        return solveForAlice(0, 1, 1, piles);
    }
};

int main()
{

    return 0;
}