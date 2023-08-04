#include "bits/stdc++.h"
using namespace std;

class Solution
{
private:
    vector<vector<int>> res;
    vector<int> temp;

    bool isValid(int i, int j, vector<string> &board)
    {
        int row = i, col = j;

        // Left Upper Diagonal
        while (row >= 0 && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }

        row = i, col = j;
        // Left Lower Diagonal
        while (col >= 0 && row < board.size())
        {
            if (board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }

        row = i, col = j;
        // Towards left
        while (col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            col--;
        }

        return true;
    }

    void helper(int col, vector<string> &board, int n)
    {
        if (col == n)
        {
            res.push_back(temp);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isValid(row, col, board))
            {
                board[row][col] = 'Q';
                temp.push_back(row + 1);
                helper(col + 1, board, n);
                temp.pop_back();
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<int>> nQueen(int n)
    {
        // code here
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            board.push_back(s);
        }

        // col, board, n
        helper(0, board, n);
        return res;
    }
};

// Optimal

/*
    Time Complexity : O(n^2)
    Space Complexity : O(2*n) + O(n) - Auxiliary Space Complexity
*/

void addBoard(vector<vector<int>> &board, vector<vector<int>> &res)
{
    vector<int> temp;
    int n = board.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }

    res.push_back(temp);
}

void helper(int col, vector<vector<int>> &board, int n, vector<bool> &leftRow,
            vector<bool> &leftUpperDiagonal, vector<bool> &leftLowerDiagonal, vector<vector<int>> &res)
{
    if (col == n)
    {
        addBoard(board, res);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (!leftRow[row] && !leftLowerDiagonal[row + col] && !leftUpperDiagonal[n - 1 + col - row])
        {
            board[row][col] = 1;
            leftRow[row] = true;
            leftLowerDiagonal[row + col] = true;
            leftUpperDiagonal[n - 1 + col - row] = true;
            helper(col + 1, board, n, leftRow, leftUpperDiagonal, leftLowerDiagonal, res);
            leftRow[row] = false;
            leftLowerDiagonal[row + col] = false;
            leftUpperDiagonal[n - 1 + col - row] = false;
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n)
{
    // Write your code here.
    vector<bool> leftRow(n, false);
    vector<bool> leftUpperDiagonal(2 * n - 1, false);
    vector<bool> leftLowerDiagonal(2 * n - 1, false);

    vector<vector<int>> res, board(n, vector<int>(n, 0));

    helper(0, board, n, leftRow, leftUpperDiagonal, leftLowerDiagonal, res);

    return res;
}

class Solution
{

    /*
        Time Complexity : O(n!)
        Space Complexity : O(n)
    */

private:
    vector<int> upperLeftDiagnal;
    vector<int> upperRightDiagnal;
    vector<int> upperCol;

    vector<vector<string>> res;
    vector<string> board;

    void helper(int row, int size)
    {
        if (row == size)
        {
            res.push_back(board);
            return;
        }

        for (int col = 0; col < size; col++)
        {
            if (upperCol[col] == 0 and
                upperLeftDiagnal[row + col] == 0 and
                upperRightDiagnal[(size - 1) + col - row] == 0)
            {
                board[row][col] = 'Q';
                upperCol[col] = upperLeftDiagnal[row + col] = upperRightDiagnal[(size - 1) + col - row] = 1;
                helper(row + 1, size);
                upperCol[col] = upperLeftDiagnal[row + col] = upperRightDiagnal[(size - 1) + col - row] = 0;
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        upperLeftDiagnal.resize(2 * n - 1, 0);
        upperRightDiagnal.resize(2 * n - 1, 0);
        upperCol.resize(n, 0);

        board.resize(n);
        string s(n, '.');

        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }

        // row, size
        helper(0, n);

        return res;
    }
};

class Solution
{

    // Check is solution exists or not and print only first solution if it exists

private:
    vector<int> upperLeftDiagnal;
    vector<int> upperRightDiagnal;
    vector<int> upperCol;

    vector<vector<string>> res;
    vector<string> board;

    bool helper(int row, int size)
    {
        if (row == size)
        {
            res.push_back(board);
            return true;
        }

        for (int col = 0; col < size; col++)
        {
            if (upperCol[col] == 0 and
                upperLeftDiagnal[row + col] == 0 and
                upperRightDiagnal[(size - 1) + col - row] == 0)
            {
                board[row][col] = 'Q';
                upperCol[col] = upperLeftDiagnal[row + col] = upperRightDiagnal[(size - 1) + col - row] = 1;
                if (helper(row + 1, size))
                    return true;
                upperCol[col] = upperLeftDiagnal[row + col] = upperRightDiagnal[(size - 1) + col - row] = 0;
                board[row][col] = '.';
            }
        }

        return false;
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        upperLeftDiagnal.resize(2 * n - 1, 0);
        upperRightDiagnal.resize(2 * n - 1, 0);
        upperCol.resize(n, 0);

        board.resize(n);
        string s(n, '.');

        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }

        // row, size
        if (helper(0, n))
            cout << "Solution Found" << endl;
        else
            cout << "Solution not found!" << endl;

        return res;
    }
};