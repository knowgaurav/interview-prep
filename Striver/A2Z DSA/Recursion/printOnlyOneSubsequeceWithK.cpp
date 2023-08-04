#include "bits/stdc++.h"
using namespace std;

// Print Only One Subsequence with given sum
bool solve(int idx, int currSum, int target, vector<int> &temp, vector<int> &arr){
    if(idx >= arr.size()){
        if(currSum  == target){
            cout << "First Subsequence with sum k = ";
            for(int &ele : temp) cout << ele << " ";
            cout << endl;
            return true;
        }
        return false;
    }

    // Include
    currSum += arr[idx];
    temp.push_back(arr[idx]);
    if(solve(idx+1, currSum, target, temp, arr)) return true;
    temp.pop_back();
    currSum -= arr[idx];

    // Exclude
    if(solve(idx+1, currSum, target, temp, arr)) return true;
    
    return false;
}

// Count number of subsequences with given sum
int countSubsequences(int idx, int currSum, int target, vector<int> &arr){
    if(idx >= arr.size()){
        if(currSum == target) return 1;
        return 0;
    }

    // Include
    currSum += arr[idx];
    int include = countSubsequences(idx+1, currSum, target, arr);
    currSum -= arr[idx];

    // Exclude
    int exclude = countSubsequences(idx+1, currSum, target, arr);

    return include + exclude;
}

int main(){
    vector<int> arr = {3,2,1,1};
    vector<int> temp;

    // idx, sum, temp, arr
    solve(0, 0, 2, temp, arr);

    // Number of subsequences
    cout << "Number of subsequences with sum k are = " << countSubsequences(0, 0, 2, arr);
    return 1;
}
