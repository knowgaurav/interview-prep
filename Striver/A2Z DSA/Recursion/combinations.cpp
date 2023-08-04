#include "bits/stdc++.h"
using namespace std;

/*
    Time Complexity : O(2^n)
    Space Complexity : O(n) + O(2^n)
*/

// ninja-has-n-beautiful-paintings-labeled-from-1-to-n-he-has-to-go-to-an-exhibition-to-showcase-k-paintings-now-he-is-confused-about-which-combinations-of-paintings-he-should-choose-he-wants-to-make-all-possible-combinations-of-these-n-paintings-can-you-help-ninja-to-make-all-the-possible-combinations-of-n-paintings

void helper(int i, int n, int k, vector<int> &temp, vector<vector<int>> &res){
    // Base case
    if (k == 0) {
      res.push_back(temp);
      return;
    }
    if(i>n) return;

    // Not sufficient elements
    if(k > n-i+1) return;

    // Element Taken
    temp.push_back(i);
    helper(i+1, n, k-1, temp, res);
    temp.pop_back();

    // Not taken
    helper(i+1, n, k, temp, res);
}

vector<vector<int>> combinations(int n, int k)
{
    // Write your code here.
    vector<vector<int>> res;
    vector<int> temp;

    helper(1, n, k, temp, res);

    return res;
}

int main()
{

    return 0;
}