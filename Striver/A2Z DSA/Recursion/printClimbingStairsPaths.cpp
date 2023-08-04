#include "bits/stdc++.h"
using namespace std;

//* Bottom Up

/*
    Time Complexity: O(3^n)
    Space Complexity: O(n)
*/

void printAllPaths(int i, int n, vector<int> &temp)
{
    if (i > n)
        return;
    if (i == n)
    {
        for (int step : temp)
        {
            cout << step << " ";
        }
        cout << endl;
        return;
    }

    // Take 1 step
    temp.push_back(1);
    printAllPaths(i + 1, n, temp);
    temp.pop_back();

    // Take 2 steps
    temp.push_back(2);
    printAllPaths(i + 2, n, temp);
    temp.pop_back();

    // Take 3 steps
    temp.push_back(3);
    printAllPaths(i + 3, n, temp);
    temp.pop_back();
}

/*
    Time Complexity: O(3^n)
    Space Complexity: O(n*3^n)
*/

void printAllPathsS(int currStep, int n, string ans)
{
    if (currStep > n)
        return;
    if (currStep == n)
    {
        cout << ans << endl;
        return;
    }

    printAllPathsS(currStep + 1, n, ans + "1 ");
    printAllPathsS(currStep + 2, n, ans + "2 ");
    printAllPathsS(currStep + 3, n, ans + "3 ");
}

//* Top Down
void printAllPathsTopDown(int n, string ans)
{
    if (n < 0)
        return;
    if (n == 0)
    {
        cout << ans << endl;
        return;
    }

    printAllPathsTopDown(n - 1, ans + "1 ");
    printAllPathsTopDown(n - 2, ans + "2 ");
    printAllPathsTopDown(n - 3, ans + "3 ");
}

int main()
{
    int n;
    cin >> n;
    vector<int> temp;

    printAllPaths(0, n, temp);
    printAllPathsS(0, n, "");
    printAllPathsTopDown(n, "");
    return 0;
}