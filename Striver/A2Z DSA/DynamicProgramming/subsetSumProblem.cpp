#include "bits/stdc++.h"
using namespace std;

class Solution
{

    /*
        Memoization:
        Time Complexity : O(n*target)
        Space Complexity : O(n) + O(n*target)
    */

private:
    int n;

    int helper(int idx, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (target == 0)
            return true;
        if (idx == 0)
            return arr[0] == target;

        if (dp[idx][target] != -1)
            return dp[idx][target];

        bool notTake = helper(idx - 1, target, arr, dp);
        bool take = false;
        if (arr[idx] <= target)
        {
            take = helper(idx - 1, target - arr[idx], arr, dp);
        }

        return dp[idx][target] = take || notTake;
    }

public:
    bool isSubsetSum(vector<int> arr, int sum)
    {
        // code here
        n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

        return helper(n - 1, sum, arr, dp);
    }
};

class Solution
{

    /*
        Tabulation:
        Time Complexity : O(n*target)
        Space Complexity : O(n*target)
    */

public:
    bool isSubsetSum(vector<int> arr, int sum)
    {
        // code here
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

        // Base case
        for (int i = 0; i < n; i++)
            dp[i][0] = true;
        dp[0][arr[0]] = true;

        for (int idx = 1; idx < n; idx++)
        {
            for (int target = 1; target <= sum; target++)
            {
                bool notTake = dp[idx - 1][target];
                bool take = false;
                if (arr[idx] <= target)
                    take = dp[idx - 1][target - arr[idx]];

                dp[idx][target] = take or notTake;
            }
        }

        return dp[n - 1][sum];
    }
};

class Solution
{

    /*
        Space Optimised:
        Time Complexity : O(n*target)
        Space Complexity : O(target)
    */

public:
    bool isSubsetSum(vector<int> arr, int sum)
    {
        // code here
        int n = arr.size();
        vector<bool> prev(sum + 1, false);
        prev[0] = true;

        // Base case
        prev[arr[0]] = true;

        for (int idx = 1; idx < n; idx++)
        {
            vector<bool> curr(sum + 1, false);
            curr[0] = true;

            for (int target = 1; target <= sum; target++)
            {
                bool notTake = prev[target];
                bool take = false;
                if (arr[idx] <= target)
                    take = prev[target - arr[idx]];

                curr[target] = take or notTake;
            }

            prev = curr;
        }

        return prev[sum];
    }
};

int main()
{

    return 0;
}