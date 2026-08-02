class Solution {
public:
    int solve (int i, int j, vector<int>& piles, vector<vector<int>>& dp){
        if(i == j) return piles[i];
        if(i > j)  return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int takei = piles[i] + min( solve(i+2, j, piles, dp), solve(i+1, j-1, piles, dp));
        int takej = piles[j] + min( solve(i, j-2, piles, dp), solve(i+1, j-1, piles, dp));

        return dp[i][j] = max(takei, takej);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int totalScore = 0;
        for(int i=0; i<n; i++){
            totalScore += piles[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, -1));

        int aliceScore = solve(0, n-1, piles, dp);
        int bobScore = totalScore - aliceScore;

        return aliceScore > bobScore;
    }
};