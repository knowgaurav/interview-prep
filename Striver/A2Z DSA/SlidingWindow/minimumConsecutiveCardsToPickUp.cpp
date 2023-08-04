#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int minimumCardPickup(vector<int> &cards)
    {
        int start = 0, end = 0, res = INT_MAX;
        unordered_map<int, int> m1;

        while (end < cards.size())
        {
            int card = cards[end];
            if (m1.find(card) != m1.end())
            {
                res = min(res, end - m1[card] + 1);
            }

            m1[card] = end;
            end++;
        }

        return res == INT_MAX ? -1 : res;
    }
};

int main()
{

    return 0;
}