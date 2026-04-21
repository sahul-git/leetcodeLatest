class Solution {
public:
    bool PartSum(int i, vector<int>& nums, int sum, vector<vector<int>>& dp){
        if(sum == 0) return true;
        if(i>= nums.size()) return false;
        if(dp[i][sum] != -1) return dp[i][sum];
        bool take = false;
        if(nums[i] <= sum){
            take = PartSum(i+1, nums, sum-nums[i], dp);
        }
        bool notTake = PartSum(i+1, nums, sum, dp );
        return dp[i][sum] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int totalsum = 0;
        
        for(int i=0; i<nums.size();i++){
            totalsum += nums[i];
        }
        
        if(totalsum%2 == 1) return false;
        vector<vector<int>> dp (nums.size(), vector<int>(totalsum/2 + 1, -1));
        return PartSum(0, nums, totalsum/2, dp);
    }
};