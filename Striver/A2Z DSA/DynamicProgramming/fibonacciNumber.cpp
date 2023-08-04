#include "bits/stdc++.h"
using namespace std;

class Solution {
    
    /*
        Time Complexity = O(n)
        Space Complexity = O(1)
    */
    
public:
    int fib(int n) {
        if(n<=1) return n;
        
        int prev2 = 0, prev = 1;
        int res = -1;
        
        for(int i=2; i<=n; i++){
            res = prev + prev2;
            prev2 = prev;
            prev = res;
        }
        
        return res;
    }
};

int main()
{

    return 0;
}