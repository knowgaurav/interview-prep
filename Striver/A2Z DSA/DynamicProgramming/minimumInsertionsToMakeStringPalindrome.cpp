#include <bits/stdc++.h> 
int minInsertion(string &str)
{
    // Write your code here.
    string rev = string(str.rbegin(), str.rend());
    int n = str.size();
    vector<int> prev(n+1, 0);

    for(int i=1; i<=n; i++){
        vector<int> curr(n+1, 0);

        for(int j=1; j<=n; j++){
            if(str[i-1] == rev[j-1]){
                curr[j] = 1 + prev[j-1];
            }else{
                curr[j] = max(curr[j-1], prev[j]);
            }
        }

        prev = curr;
    }

    int lengthOfLongestPalindromicSubsequence = prev[n];
    return n-lengthOfLongestPalindromicSubsequence;
}