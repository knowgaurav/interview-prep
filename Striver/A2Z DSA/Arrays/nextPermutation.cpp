#include "bits/stdc++.h"
using namespace std;

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        int idx = -1;
        
        // Step 1. Find the idx that satisfy this condition - i<i+1
        for(int i=N-2; i>=0; i--){
            if(arr[i] < arr[i+1]){
                idx = i;
                break;
            }
        }
        
        if(idx == -1){
            reverse(arr.begin(), arr.end());
            return arr;
        }
        
        // Step 2. Find the just greater element than arr[idx] element
        for(int i=N-1; i>idx; i--){
            if(arr[i] > arr[idx]){
                swap(arr[i], arr[idx]);
                break;
            }
        }
        
        // Step 3. reverse the array from idx+1 to end
        reverse(arr.begin()+idx+1, arr.end());
        return arr;
    }
};