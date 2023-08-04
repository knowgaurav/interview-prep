#include "bits/stdc++.h"
using namespace std;

int countWays(int n){
    if(n<=2) return n;
    if(n==3) return 4;

    return countWays(n-1)+countWays(n-2)+countWays(n-3);
}

int main()
{
    int n=0; cin >> n;
    cout << countWays(n);

    return 0;
}