#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
    {
        // Code here
        queue<pair<string, int>> q1;
        q1.push({startWord, 1});
        unordered_set<string> s1(wordList.begin(), wordList.end());

        while (!q1.empty())
        {
            string word = q1.front().first;
            int len = q1.front().second;
            q1.pop();

            if (word == targetWord)
                return len;

            for (int i = 0; i < word.length(); i++)
            {
                char org = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;

                    if (s1.find(word) != s1.end())
                    {
                        q1.push({word, len + 1});
                        s1.erase(word);
                    }
                }

                word[i] = org;
            }
        }

        return 0;
    }
};

int main()
{

    return 0;
}