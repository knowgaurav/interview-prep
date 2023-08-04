#include "bits/stdc++.h"
using namespace std;

class Solution{
private:
    bool canBeUsed(int color, int node, bool graph[101][101], int colorArr[], int n){
        for(int i=0; i<n; i++){
            if(i!=node && graph[i][node] && colorArr[i] == color){
                return false;
            }
        }
        
        return true;
    }

    bool solve(int curr, int noOfColors, int colorArr[], bool graph[101][101], int n){
        if(curr == n){
            return true;
        }
        
        for(int i=1; i<=noOfColors; i++){
            if(canBeUsed(i, curr, graph, colorArr, n)){
                colorArr[curr] = i;
                if(solve(curr+1, noOfColors, colorArr, graph, n)) return true;
                colorArr[curr] = 0;
            }
        }
        
        return false;
    }
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        int color[n] = {0};
        
        // node, no. of colors, color arr, graph, N
        if(solve(0, m, color, graph, n)) return true;
        
        return false;
    }
};