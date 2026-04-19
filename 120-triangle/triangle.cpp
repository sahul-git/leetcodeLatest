class Solution {
public:
    int minPath(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(i==0 && j==0){
            return triangle[0][0];
        }
        if(j<0 || j>=triangle[i].size()) return INT_MAX;

        if(dp[i][j] != -1) return dp[i][j];

        
        return dp[i][j] = triangle[i][j] + min(minPath(i-1, j, triangle, dp), minPath(i-1, j-1, triangle, dp));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int minSum = INT_MAX;

        for(int j=0; j<triangle[m-1].size(); j++){
            minSum = min(minSum, minPath(m-1, j, triangle, dp));
        }
        return minSum;
    }
};