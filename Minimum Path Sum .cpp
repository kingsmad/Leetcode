class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
           int m = grid.size() - 1;
           int n = grid.front().size() - 1;
           if(m==0 && n ==0)
           		return grid[0][0];

           int dp[m+1][n+1];

           dp[0][0] = grid[0][0];
           for(int i=1; i<n+1; ++i){
           		dp[0][i] = dp[0][i-1] + grid[0][i];
           }
           for(int j=1; j<m+1; ++j) {
           		dp[j][0] = dp[j-1][0] + grid[j][0];
           }
           
           if(m > 0 && n >0)
           for(int i=1; i<m+1; ++i) {
           		for(int j=1; j<n+1; ++j){
           			dp[i][j] = std::min(dp[i][j-1], dp[i-1][j]) + grid[i][j];
           		}
           }

           return dp[m][n];
    }
};