class Solution {
public:
    int longestSub(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        if(i < 0){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];

        int take = 0;
        if(j==nums.size() || nums[i] < nums[j]){
            take = 1 + longestSub(i-1, i, nums, dp);
        }
        int notTake = longestSub(i-1, j, nums, dp);

        return dp[i][j] = max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return longestSub(n-1, n, nums, dp);
    }
};