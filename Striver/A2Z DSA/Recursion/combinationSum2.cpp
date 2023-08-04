#include "bits/stdc++.h"
using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> temp;
    
    void helper(int idx, int target, vector<int> &nums){
        if(target == 0){
            res.push_back(temp);
            return;
        }
        
        for(int i=idx; i<nums.size(); i++){
            // unn elements ko mat lo jo same hai ek ke baad ek
            // agar 1 ko utha lia hai toh ek recursion call mein toh
            // similar 1's ko firr se nahi uthana hai kyon ki voh duplicate combinations
            // banyenge aage jaake
            if(i>idx && nums[i]==nums[i-1]) continue;
            if(nums[i] > target) break;
            
            temp.push_back(nums[i]);
            helper(i+1, target-nums[i], nums);
            temp.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // idx, target, nums
        sort(begin(candidates), end(candidates));
        helper(0, target, candidates);
        return res;
    }
};

class Solution {
private:
    vector<vector<int>> res;
    vector<int> temp;
    
    void helper(int i, int target, vector<int> &nums){
        if(target == 0){
            res.push_back(temp);
            return;
        }
        
        if(i>=nums.size())
            return;
        
        // Include
        if(target>=nums[i]){
            temp.push_back(nums[i]);
            helper(i+1, target-nums[i], nums);
            temp.pop_back();
        }
        
        // Exclude
        while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
        // Ignore all the same elements as before combination with that
        // element has already been formed
        helper(i+1, target, nums);
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(begin(candidates), end(candidates));
        helper(0, target, candidates);
        return res;
    }
};