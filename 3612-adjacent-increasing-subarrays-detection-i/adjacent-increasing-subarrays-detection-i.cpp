class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int incr = 1;
        int prevIncr = 0;
        
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i-1]) {
                incr++;
            } else {
                prevIncr = incr;
                incr = 1;
            }
            if (incr / 2 >= k || min(prevIncr, incr) >= k) {
                return true;
            }
        }
        return false;
    }
};
