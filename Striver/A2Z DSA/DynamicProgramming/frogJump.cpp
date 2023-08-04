#include "bits/stdc++.h"
using namespace std;

#include <bits/stdc++.h> 

int solve(int idx, vector<int> &heights, vector<int> &dp){

    /*
        Time Complexity : O(n)
        Space Complexity : O(n) + O(n)
    */

    if(idx == 0) return 0;

    if(dp[idx]!=-1) return dp[idx];

    int jumpOf1 = solve(idx-1, heights, dp) + abs(heights[idx]-heights[idx-1]);
    int jumpOf2 = INT_MAX;
    if(idx>=2){
        jumpOf2 = solve(idx-2, heights, dp) + abs(heights[idx]-heights[idx-2]);
    }
    
    return dp[idx] = min(jumpOf1, jumpOf2);
}

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n+1, -1);
    return solve(n-1, heights, dp);
}

int frogJump(int n, vector<int> &heights)
{

    /*
        Time Complexity : O(n)
        Space Complexity : O(n)
    */

    // Write your code here.
    vector<int> dp(n, -1);
    dp[0] = 0;

    for(int i=1; i<n; i++){
        int jumpOf1 = dp[i-1] + abs(heights[i]-heights[i-1]);
        int jumpOf2 = INT_MAX;
        
        if(i>1){
            jumpOf2 = dp[i-2] + abs(heights[i]-heights[i-2]);
        }

        dp[i] = min(jumpOf1, jumpOf2);
    }

    return dp[n-1];
}

int frogJump(int n, vector<int> &heights)
{
    /*
        Time Complexity : O(n)
        Space Complexity : O(1)
    */

    // Write your code here.
    int prev2 = 0, prev = 0;

    for(int i=1; i<heights.size(); i++){
        int jumpOf1 = prev + abs(heights[i]-heights[i-1]);
        int jumpOf2 = INT_MAX;
        if(i>1){
            jumpOf2 = prev2 + abs(heights[i]-heights[i-2]);
        }

        int curr = min(jumpOf1, jumpOf2);
        prev2 = prev;
        prev = curr;
    }
    
    return prev;
}

int main()
{

    return 0;
}