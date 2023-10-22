#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> &wordList)
    {
        // code here
        unordered_set<string> s1(wordList.begin(), wordList.end());
        queue<vector<string>> q1;
        vector<string> usedOnLevel;
        q1.push({beginWord});
        usedOnLevel.push_back(beginWord);
        int lvl = 0;
        vector<vector<string>> ans;

        while (!q1.empty())
        {
            vector<string> curr = q1.front();
            q1.pop();

            if (curr.size() > lvl)
            {
                lvl++;

                for (auto &it : usedOnLevel)
                {
                    s1.erase(it);
                }

                usedOnLevel.clear();
            }

            string word = curr.back();

            if (word == endWord)
            {
                if (ans.size() == 0)
                {
                    ans.push_back(curr);
                }
                else if (ans[0].size() == curr.size())
                {
                    ans.push_back(curr);
                }
            }

            for (int i = 0; i < word.size(); i++)
            {
                char org = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;

                    if (s1.find(word) != s1.end())
                    {
                        curr.push_back(word);
                        usedOnLevel.push_back(word);
                        q1.push(curr);
                        curr.pop_back();
                    }
                }

                word[i] = org;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}