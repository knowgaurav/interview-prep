#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int kthGrammar(int n, int k)
    {
        string prev = "0";

        for (int i = 2; i <= n; i++)
        {
            string curr = "";

            for (char ch : prev)
            {
                if (ch == '0')
                {
                    curr.push_back('0');
                    curr.push_back('1');
                }
                else
                {
                    curr.push_back('1');
                    curr.push_back('0');
                }
            }

            prev = curr;
        }

        return prev[k - 1] - '0';
    }
};

class Solution
{
public:
    int kthGrammar(int n, int k)
    {
        if (n == 1)
            return 0;

        int mid = pow(2, n - 1) / 2;

        if (k <= mid)
        {
            return kthGrammar(n - 1, k);
        }

        return !kthGrammar(n - 1, k - mid);
    }
};

int main()
{

    return 0;
}