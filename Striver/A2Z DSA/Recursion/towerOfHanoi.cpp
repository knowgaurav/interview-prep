#include "bits/stdc++.h"
using namespace std;

// src, helper, destination
void towerOfHanoi(int n, char d1, char d2, char d3){
    if(n==0) return;

    towerOfHanoi(n-1, d1, d3, d2);
    cout << "Move disk from " << d1 << " to " << d3 << endl;
    towerOfHanoi(n-1, d2, d1, d3);
}

int main()
{
    int n; cin >> n;

    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}