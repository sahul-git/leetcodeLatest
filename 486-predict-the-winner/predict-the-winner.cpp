class Solution {
public:
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        if(i > j) return 0;
        if(i==j) return nums[i];
        if(dp[i][j] != -1) return dp[i][j];

        int takei = nums[i] + min(solve(i+2, j, nums, dp), solve(i+1, j-1, nums, dp));
        int takej = nums[j] + min(solve(i, j-2, nums, dp), solve(i+1, j-1, nums, dp));

        return dp[i][j] = max(takei , takej);
    }
    bool predictTheWinner(vector<int>& nums) {
        int  n = nums.size();
        int total_score = 0;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int i=0; i<nums.size(); i++){
            total_score += nums[i];
        }

        int player1_score = solve(0, n-1, nums, dp);

        int player2_score = total_score - player1_score;

        return player1_score >= player2_score;

    }
};