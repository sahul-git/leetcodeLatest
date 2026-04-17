class Solution {
public:

    
    // int robber(vector<int>& nums, int ind, vector<int>& dp){
    //     if(ind < 0) return 0;
    //     if(ind == 0) return nums[ind];
    //     if(dp[ind] != -1){
    //         return dp[ind];
    //     }
        
    //     int pick = nums[ind] + robber(nums, ind - 2, dp);
    //     int notPick = robber(nums, ind-1, dp );

    //     return dp[ind] = max(pick, notPick);

    // }

    // int rob(vector<int>& nums) {
    //     vector<int> dp(nums.size(), -1);
    //     return robber(nums, nums.size()-1, dp);
    // }


    int rob(vector<int>& nums) {
        int n =nums.size();
        if(n == 1) return nums[n-1];
        vector<int> dp(nums.size(), -1);
        dp[0] = nums[0];
        

        for(int i=1; i<nums.size(); i++){
            int pick = nums[i];
            if(i>1){
                 pick = nums[i] + dp[i-2];
            }
            int notPick = dp[i-1];

            dp[i] = max(pick, notPick);

        }
        return dp[n-1];
    }
};