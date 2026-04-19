class Solution {
public:

    // int minPath(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
    //     if(i<0 || j<0) return INT_MAX;
    //     if(i==0 && j==0) return grid[i][j];
    //     if(dp[i][j] != -1) return dp[i][j];

    //     return dp[i][j] = grid[i][j] + min(minPath(i-1, j, grid, dp), minPath(i, j-1, grid, dp));
    // }

    // int minPathSum(vector<vector<int>>& grid) {
    //     int m = grid.size();
    //     int n = grid[0].size();
    //     vector<vector<int>> dp(m, vector<int>(n, -1));
    //     return minPath(m-1, n-1, grid, dp);
    // }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0){
                    dp[i][j] = grid[i][j];
                }else{
                    int up = grid[i][j];
                    if(i>0) up+= dp[i-1][j];
                    else up+= 1e9;

                    int left = grid[i][j];
                    if(j>0) left+= dp[i][j-1];
                    else left+= 1e9;

                    dp[i][j] = min(left , up);
                }
            }
        }
        return dp[m-1][n-1];
    }
};