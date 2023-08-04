#include "bits/stdc++.h"
using namespace std;

class Solution{
    private:
    string temp = "";
    vector<string> res;
    
    vector<char> sign = {'D', 'U', 'R', 'L'};
    vector<pair<int, int>> dirc = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}};
    
    bool isValid(int i, int j, vector<vector<bool>> &visited, vector<vector<int>> &matrix, int n){
        if(i>=0 && i<n && j>=0 && j<n && !visited[i][j] && matrix[i][j]!=0) return true;
        return false;
    }
    
    void solve(int i, int j, vector<vector<bool>> &visited, vector<vector<int>> &matrix, int n){
        if(i==n-1 && j==n-1){
            res.push_back(temp);
            return;
        }
        
        visited[i][j] = true;
        
        for(int k=0; k<4; k++){
            pair<int, int> dir = dirc[k];
            int newX = dir.first + i;
            int newY = dir.second + j;
            
            if(isValid(newX, newY, visited, matrix, n)){
                temp.push_back(sign[k]);
                visited[newX][newY] = true;
                solve(newX, newY, visited, matrix, n);
                visited[newX][newY] = false;
                temp.pop_back();
            }
        }
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[0][0] == 0) return {};
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        solve(0, 0, visited, m, n);
        
        sort(begin(res), end(res));
        return res;
    }
};

class Solution{

    /*
        Time Complexity : O(3^(n^2));
        Space Complexity : O(n^2)
    */

    private:
    vector<string> res;
    
    vector<pair<int, int>> dirc = {{+1, 0}, {0, -1}, {0, +1}, {-1, 0}};
    string dircSymbol = "DLRU";
    
    bool isValid(int i, int j, int n, vector<vector<int>> &m){
        return i>=0 and i<n and j>=0 and j<n and m[i][j]==1;
    }
    
    void helper(int i, int j, string temp, vector<vector<int>> &m){
        if(i==m.size()-1 and j==m.size()-1){
            res.push_back(temp);
            return;
        }
        
        m[i][j] = 2;
        
        for(int k=0; k<4; k++){
            int newX = i+dirc[k].first;
            int newY = j+dirc[k].second;
            
            if(isValid(newX, newY, m.size(), m)){
                helper(newX, newY, temp+dircSymbol[k], m);
            }
        }
        
        m[i][j] = 1;
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[0][0]==0) return res;
        
        helper(0, 0, "", m);
        return res;
    }
};