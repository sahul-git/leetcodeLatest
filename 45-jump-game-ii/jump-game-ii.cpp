class Solution {
public:

    // int func(vector<int>&  nums, int ind, int jumps, vector<vector<int>>& dp){
    //     if(ind > nums.size()-1 ){
    //         return jumps;
    //     }
    //     if(dp[ind][jumps] != -1){
    //         return dp[ind][jumps];
    //     }
    //     int mini = INT_MAX;
    //     for(int i = 1; i<nums[ind]; i++){
    //         mini = min(mini, func(nums, ind + i, jumps+1 ,dp  ));
    //     }
    //     return dp[ind][jumps] = mini;
    // }
    int jump(vector<int>& nums) {
        int n =nums.size();
        int jumps = 0;
        int l = 0, r = 0;
        int farthest = 0;
        while(r< n-1){
            int farthest = 0;
            for(int i = l; i<= r ;i++){
                farthest = max(i+ nums[i], farthest);
            }
            l = r+1;
            r = farthest;
            jumps = jumps + 1;

        }
        return jumps;
    }
};