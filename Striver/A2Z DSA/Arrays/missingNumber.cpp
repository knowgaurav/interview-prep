#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        // int n = nums.size();
        // for(int i=0; i<=n; i++){
        //     bool flag = false;

        //     for(int j=0; j<n; j++){
        //         if(i == nums[j]){
        //             flag = true;
        //             break;
        //         }
        //     }

        //     if(!flag) return i;
        // }

        // return -1;

        // int n = nums.size();
        // int arrSum = 0, totalSum = n*(n+1)/2;

        // for(int num : nums){
        //     arrSum += num;
        // }

        // return totalSum - arrSum;

        // Optimal using XOR
        int n = nums.size();
        int xor1 = 0, xor2 = 0;

        for (int i = 0; i < n; i++)
        {
            xor1 ^= i;
            xor2 ^= nums[i];
        }

        xor1 ^= n;
        return xor1 ^ xor2;
    }
};