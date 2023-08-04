#include "bits/stdc++.h"
using namespace std;

class Solution
{

    /*
        Time Complexity : O(N)
        Space Complexity : O(1)
    */

private:
    vector<int> freqS, freqP;
    int n, m;

public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> res;
        freqS.resize(26, 0);
        freqP.resize(26, 0);
        n = s.length(), m = p.length();

        if (m > n)
            return res;

        for (int i = 0; i < m; i++)
        {
            freqP[p[i] - 'a']++;
            freqS[s[i] - 'a']++;
        }

        if (freqS == freqP)
            res.push_back(0);

        for (int i = m; i < n; i++)
        {
            int addIdx = i;
            int rmvIdx = i - m;

            freqS[s[addIdx] - 'a']++;
            freqS[s[rmvIdx] - 'a']--;

            if (freqS == freqP)
            {
                res.push_back(rmvIdx + 1);
            }
        }

        return res;
    }
};

int main()
{

    return 0;
}