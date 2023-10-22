#include "bits/stdc++.h"
using namespace std;

class Solution {

    /*
        Time Complexity : O(N^3)
        Space Complexity : O(N^2)
    */

  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int m = matrix.size(), n = matrix[0].size();
	    
	    for(int i=0; i<m; i++){
	        for(int j=0; j<n; j++){
	            if(matrix[i][j] == -1){
	                matrix[i][j] = (1e9);
	            }
	        }
	    }
	    
	    for(int via=0; via<n; via++){
	        for(int i=0; i<m; i++){
	            for(int j=0; j<n; j++){
	                matrix[i][j] = min(matrix[i][j],
	                matrix[i][via] + matrix[via][j]);
	            }
	        }
	    }
	    
	    for(int i=0; i<m; i++){
	        for(int j=0; j<n; j++){
	            if(matrix[i][j] == 1e9){
	                matrix[i][j] = -1;
	            }
	        }
	    }
	}
};

int main()
{

    return 0;
}