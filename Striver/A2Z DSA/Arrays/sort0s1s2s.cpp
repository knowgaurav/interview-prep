#include "bits/stdc++.h"
using namespace std;

class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here 
        int low, mid, high;
        low = mid = 0;
        high = n-1;
        
        // we have to keep 0-low-1 with zeroes
        // low to mid with ones
        // high+1 to n-1 with twos
        
        while(mid <= high){
            if(a[mid] == 0){
                swap(a[low], a[mid]);
                low++;
                mid++;
            }else if(a[mid] == 2){
                swap(a[mid], a[high]);
                high--;
            }else{
                mid++;
            }
        }
    }
};