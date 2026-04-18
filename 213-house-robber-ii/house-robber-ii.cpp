class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        int prev1 =max(nums[0], nums[1]);
        int prev2 = nums[0];
        for(int i = 2; i < n-1; i++){
            int curr = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }

        
        int prev3 =max(nums[1], nums[2]);
        int prev4 = nums[1];
        for(int i = 3; i < n; i++){
            int curr = max(nums[i] + prev4, prev3);
            prev4 = prev3;
            prev3 = curr;
        }

        return max(prev1, prev3);
    }
};