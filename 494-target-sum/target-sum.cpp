class Solution {
public:
    int reachTarget(int ind, vector<int>& nums, int target, vector<vector<int>>& dp){
        if(ind == 0){

            if(nums[ind] == 0 && target == 0){
                return 2;
            }
            if(target == 0 || nums[ind] == target){
                return 1;
            }

            return 0;
        }
        if(dp[ind][target]!= -1) return dp[ind][target];
        int take = 0;
        if(nums[ind] <= target){
            take = reachTarget(ind-1, nums, target-nums[ind], dp);
        }
        int notTake = reachTarget(ind-1, nums, target, dp);
        
        return dp[ind][target] = take + notTake;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        int totalSum = 0;
        for(int i=0; i<n; i++){
            totalSum += nums[i];
        }
        if(totalSum - target < 0) return 0;
        if((totalSum + target) % 2 == 1) return 0;
        if(abs(target) > totalSum) return 0;
        int mytarget = (totalSum + target)/2;
        vector<vector<int>> dp(n, vector<int>(mytarget+1,-1));

        return reachTarget(n-1, nums, mytarget, dp);
    }
};