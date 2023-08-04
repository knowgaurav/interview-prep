#include "bits/stdc++.h"
using namespace std;

class Solution {
    /*
        Time Complexity : O(N*N)
        Space Complexity : O(1)
    */
private:
    vector<int> generateRow(int row){
        vector<int> res;
        long long ans = 1;
        res.push_back(ans);
        
        for(int col=1; col<row; col++){
            ans = ans*(row-col);
            ans = ans/col;
            res.push_back(ans);
        }
        
        return res;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        for(int i=1; i<=numRows; i++){
            ans.push_back(generateRow(i));
        }
        
        return ans;
    }
};