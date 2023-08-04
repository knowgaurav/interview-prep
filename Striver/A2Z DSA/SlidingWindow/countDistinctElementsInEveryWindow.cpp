#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> countDistinct(int A[], int n, int k)
    {
        // code here.
        vector<int> res;
        map<int, int> m1;

        for (int i = 0; i < k; i++)
        {
            m1[A[i]]++;
        }
        res.push_back(m1.size());

        for (int i = k; i < n; i++)
        {
            int addIdx = i;
            int rmvIdx = i - k;

            if (m1[A[rmvIdx]] == 1)
                m1.erase(A[rmvIdx]);
            else
                m1[A[rmvIdx]]--;

            m1[A[addIdx]]++;

            res.push_back(m1.size());
        }

        return res;
    }
};

int main()
{

    return 0;
}