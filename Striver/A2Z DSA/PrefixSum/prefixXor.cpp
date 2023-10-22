#include "bits/stdc++.h"
using namespace std;

class Solution{
public:
    vector<int> specialXor(int N, int Q, int a[], vector<int> query[])
    {
        // code here
        vector<int> prefix(N+1, 0);
        prefix[0] = 0;
        
        for(int i=1; i<=N; i++){
            prefix[i] = prefix[i-1]^a[i-1];
        }
        
        vector<int> res;
        
        for(int j=0; j<Q; j++){
            int l = query[j][0];
            int r = query[j][1];
            
            int subarrXor = prefix[r]^prefix[l-1];
            int fullarrXor = prefix[N]^subarrXor;
            res.push_back(fullarrXor);
        }
        
        return res;
    }
}; 

int main()
{

    return 0;
}