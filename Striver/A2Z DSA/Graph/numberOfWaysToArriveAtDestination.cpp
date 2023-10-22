#include "bits/stdc++.h"
using namespace std;

/*
    Time Complexity : O(ElogV)
    Space Complexity : O(n+n)
*/

class Solution {
  private:
    typedef pair<int, int> P;
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<vector<P>> adjL(n, vector<P>());
        
        for(auto &it : roads){
            int u = it[0];
            int v = it[1];
            int t = it[2];
            
            adjL[u].push_back({v, t});
            adjL[v].push_back({u, t});
        }
        
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<int> totalTime(n, INT_MAX), ways(n, 0);
        
        pq.push({0, 0});
        totalTime[0] = 0;
        ways[0] = 1;
        
        long long int mod = (int)(1e9+7);
        
        while(!pq.empty()){
            long currN = pq.top().second;
            long currT = pq.top().first;
            pq.pop();
            
            for(auto neighbour : adjL[currN]){
                long node = neighbour.first;
                long timeTaken = neighbour.second;
                
                if(timeTaken+currT < totalTime[node]){
                    totalTime[node] = timeTaken + currT;
                    ways[node] = ways[currN];
                    pq.push({totalTime[node], node});
                }else if(timeTaken+currT == totalTime[node]){
                    ways[node] = (ways[node] + ways[currN]) % mod;
                }
            }
        }
        
        return ways[n-1]%mod;
    }
};

int main()
{

    return 0;
}