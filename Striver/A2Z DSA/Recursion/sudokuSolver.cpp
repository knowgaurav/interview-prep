#include "bits/stdc++.h"
using namespace std;

bool canUse(int digit, vector<vector<int>> &sudoku, int row, int col, int n)
{
    int rowLevel = (row / 3) * 3;
    int colLevel = (col / 3) * 3;

    for (int i = 0; i < 9; i++)
    {
        if (sudoku[row][i] == digit || sudoku[i][col] == digit)
            return false;
        if (sudoku[rowLevel + i / 3][colLevel + i % 3] == digit)
            return false;
    }

    return true;
}

bool solve(vector<vector<int>> &sudoku, int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (sudoku[i][j] == 0)
            {

                for (int digit = 1; digit <= 9; digit++)
                {

                    if (canUse(digit, sudoku, i, j, n))
                    {
                        sudoku[i][j] = digit;

                        if (solve(sudoku, n))
                        {
                            return true;
                        }
                        else
                        {
                            sudoku[i][j] = 0;
                        }
                    }
                }

                return false;
            }
        }
    }

    return true;
}

void solveSudoku(vector<vector<int>> &sudoku)
{
    // Write your code here
    // No need to print the final sudoku
    // Just fill the values in the given matrix
    int n = sudoku.size();
    solve(sudoku, n);
}

int main()
{

    return 0;
}