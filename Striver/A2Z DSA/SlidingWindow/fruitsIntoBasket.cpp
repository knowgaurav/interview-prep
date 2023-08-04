#include "bits/stdc++.h"
using namespace std;

class Solution
{

    /*
        Time Complexity : O(N)
        Space Complexity : O(1)
    */

public:
    int totalFruit(vector<int> &fruits)
    {
        int res = 0;
        int start = 0, end = 0;
        map<int, int> m1;

        while (end < fruits.size())
        {
            m1[fruits[end]]++;

            // When we have more than 2 types of fruits in the map, we start to shrink the window to satisfy the condition
            while (m1.size() > 2)
            {
                int fruit = fruits[start];

                if (m1[fruit] == 1)
                {
                    m1.erase(fruit);
                }
                else
                {
                    m1[fruit]--;
                }

                start++;
            }

            res = max(res, end - start + 1);
            end++;
        }

        return res;
    }
};

int main()
{

    return 0;
}