#include <bits/stdc++.h> 
using namespace std;

//* Just reverse the input string and perform LCS

int longestPalindromeSubsequence(string s)
{
    // Write your code here.
    string rev = string(s.rbegin(), s.rend());
    int n = s.length();
    vector<int> prev(n+1, 0);

    for(int i=1; i<=n; i++){
        vector<int> curr(n+1, 0);

        for(int j=1; j<=n; j++){
            if(s[i-1] == rev[j-1]){
                curr[j] = 1 + prev[j-1];
            }else{
                curr[j] = max(curr[j-1], prev[j]);
            }
        }

        prev = curr;
    }

    return prev[n];
}