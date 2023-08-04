#include "bits/stdc++.h"
using namespace std;

// Brute Force
class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    // code here 
	    vector<int> nonZeroes;
	    
	    for(int i=0; i<n; i++){
	        if(arr[i]){
	            nonZeroes.push_back(arr[i]);
	        }
	    }
	    
	    for(int i=0; i<nonZeroes.size(); i++){
	        arr[i] = nonZeroes[i];
	    }
	    
	    for(int j=nonZeroes.size(); j<n; j++){
	        arr[j] = 0;
	    }
	}
};

// Optimal Solution
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroIdx = -1;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                zeroIdx = i;
                break;
            }
        }
        
        if(zeroIdx == -1) return;
        
        for(int i=zeroIdx+1; i<nums.size(); i++){
            if(nums[i]){
                swap(nums[i], nums[zeroIdx]);
                zeroIdx++;
            }
        }
    }
};