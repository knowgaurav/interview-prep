#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> dist(n, vector<int>(n, 1e8));

        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            dist[u][v] = w;
            dist[v][u] = w;
        }

        for (int i = 0; i < n; i++)
        {
            dist[i][i] = 0;
        }

        // Floyd Warshall Algo
        for (int via = 0; via < n; via++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }

        vector<int> countCitiesWithinThres(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][j] <= distanceThreshold)
                {
                    countCitiesWithinThres[i]++;
                }
            }
        }

        int minCities = *min_element(countCitiesWithinThres.begin(), countCitiesWithinThres.end());

        for (int i = n - 1; i >= 0; i--)
        {
            if (countCitiesWithinThres[i] == minCities)
            {
                return i;
            }
        }

        return -1;
    }
};

int main()
{

    return 0;
}