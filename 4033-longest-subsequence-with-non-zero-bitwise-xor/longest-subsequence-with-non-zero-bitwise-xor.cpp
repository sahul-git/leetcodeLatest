class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int result = nums[0];
        for(int i=1; i<n; i++){
            result = result ^ nums[i];
        }

        if(result != 0){
            return n;
        } 
        for (int x : nums) {
            if (x != 0) {
                return n - 1;
            }
        }
        return 0;
    }
};