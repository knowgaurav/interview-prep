#include "bits/stdc++.h"
using namespace std;

class Solution {

/*
	Time Complexity : O(N*logN)
	Space Complexity : O(N)
*/

public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> m1;
        m1[0] = 1;
        
        int currSum = 0, res = 0;
        
        for(int i=0; i<nums.size(); i++){
            currSum += nums[i];
            int diff = currSum-k;
            
            if(m1.find(diff) != m1.end()){
                res += m1[diff];
            }
            
            m1[currSum]++;
        }
        
        return res;
    }
};