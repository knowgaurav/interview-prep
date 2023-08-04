#include "bits/stdc++.h"
using namespace std;

int kDistinctChars(int k, string &str)
{
    // Write your code here
    int res = 0;
    int start = 0, end = 0;
    map<char, int> m1;

    while (end < str.length())
    {
        m1[str[end]]++;

        while (m1.size() > k)
        {
            char ch = str[start];

            if (m1[ch] == 1)
            {
                m1.erase(ch);
            }
            else
            {
                m1[ch]--;
            }

            start++;
        }

        res = max(res, end - start + 1);
        end++;
    }

    return res;
}

int main()
{

    return 0;
}