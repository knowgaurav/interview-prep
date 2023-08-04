#include "bits/stdc++.h"
using namespace std;

int helper(int idx, int target, vector<int> &arr, unordered_map<int, unordered_map<int, int>> &dp)
{
    // if(idx==0){
    //     if(target+arr[0]==0 || target-arr[0]==0){
    //       return dp[idx][target] = 1;
    //     }

    //     return dp[idx][target] = 0;
    // }

    if (idx == -1)
        return (target == 0);

    if (dp[idx].find(target) != dp[idx].end())
        return dp[idx][target];

    int add = helper(idx - 1, target + arr[idx], arr, dp);
    int subtract = helper(idx - 1, target - arr[idx], arr, dp);

    return dp[idx][target] = add + subtract;
}

int targetSum(int n, int target, vector<int> &arr)
{
    // Write your code here.
    unordered_map<int, unordered_map<int, int>> dp;
    return helper(n - 1, target, arr, dp);
    ;
}

int main()
{

    return 0;
}