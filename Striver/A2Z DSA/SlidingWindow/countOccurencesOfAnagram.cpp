#include "bits/stdc++.h"
using namespace std;

class Solution
{
private:
    vector<int> freqPat, freqTxt;
    int p, t;

    void matching(int &res)
    {
        for (int i = 0; i < 26; i++)
        {
            if (freqPat[i] != freqTxt[i])
                return;
        }

        res++;
    }

public:
    int search(string pat, string txt)
    {
        // code here
        int res = 0;
        freqPat.resize(26, 0);
        freqTxt.resize(26, 0);
        p = pat.length(), t = txt.length();

        for (int i = 0; i < p; i++)
        {
            freqPat[pat[i] - 'a']++;
            freqTxt[txt[i] - 'a']++;
        }

        matching(res);

        for (int i = p; i < t; i++)
        {
            int addIdx = i;
            int rmvIdx = i - p;

            freqTxt[txt[addIdx] - 'a']++;
            freqTxt[txt[rmvIdx] - 'a']--;

            matching(res);
        }

        return res;
    }
};

int main()
{

    return 0;
}