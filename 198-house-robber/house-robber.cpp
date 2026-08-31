class Solution {
public:
    int maxMoney(int ind, vector<int>&nums, vector<int>& dp){
        if(ind < 0){
            return 0;
        }
        if(dp[ind] != -1) return dp[ind];
        int take = nums[ind] + maxMoney(ind-2,nums, dp);
        int notTake = maxMoney(ind-1, nums, dp);

        return dp[ind] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return maxMoney(n-1, nums, dp);
    }
};