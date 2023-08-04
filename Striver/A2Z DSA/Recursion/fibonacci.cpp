#include "bits/stdc++.h"
using namespace std;

class Solution {
  private:
    int mod = 1000000007;
  public:
    long long int nthFibonacci(long long int n){
        // code here
        vector<long long int> dp(n+1, 0);
        
        dp[0] = 0;
        dp[1] = 1;
        
        for(long long int i=2; i<=n; i++){
            dp[i] = (dp[i-1]+dp[i-2])%mod;
        }
        
        return dp[n]%mod;
    }
};