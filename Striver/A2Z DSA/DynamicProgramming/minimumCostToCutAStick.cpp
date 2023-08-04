#include "bits/stdc++.h"
using namespace std;

class Solution {
    
    /*
        Time Complexity : O(n^3)
        Space Complexity : O(n^2)
    */
    
    int c;
    
    int helper(int i, int j, vector<int> &cuts, vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int res = INT_MAX;
        
        for(int idx=i; idx<=j; idx++){
            int cost = cuts[j+1] - cuts[i-1] + helper(i, idx-1, cuts, dp)
                + helper(idx+1, j, cuts, dp);
            
            res = min(res, cost);
        }
        
        return dp[i][j] = res;
    }
    
public:
    int minCost(int n, vector<int>& cuts) {
        c = cuts.size();
        cuts.push_back(n);
        cuts.insert(begin(cuts), 0);
        sort(begin(cuts), end(cuts));
        
        vector<vector<int>> dp(c+1, vector<int> (c+1, -1));
        
        return helper(1, c, cuts, dp);
    }
};

class Solution {
    
    /*
        Time Complexity : O(n^3)
        Space Complexity : O(n^2)
    */
    
    int c;

public:
    int minCost(int n, vector<int>& cuts) {
        c = cuts.size();
        cuts.push_back(n);
        cuts.insert(begin(cuts), 0);
        sort(begin(cuts), end(cuts));
        
        vector<vector<int>> dp(c+2, vector<int> (c+2, 0));
        
        for(int i=c; i>0; i--){
            for(int j=1; j<=c; j++){
                if(i>j) continue;
                
                int res = INT_MAX;
        
                for(int idx=i; idx<=j; idx++){
                    int cost = cuts[j+1] - cuts[i-1] + dp[i][idx-1]
                        + dp[idx+1][j];

                    res = min(res, cost);
                }

                dp[i][j] = res;
            }
        }
        
        return dp[1][c];
    }
};

int main()
{

    return 0;
}