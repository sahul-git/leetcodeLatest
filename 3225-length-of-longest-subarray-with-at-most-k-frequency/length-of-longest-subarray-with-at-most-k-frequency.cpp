class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        int left = 0, right = 0;
        int maxlen = 0;
        while(right < n){
            freq[nums[right]]++;
            if(freq[nums[right]] > k){
                while(freq[nums[right]] > k){
                    freq[nums[left]]--;
                    left++;
                }
            }
            maxlen = max(maxlen, right-left+1);
            right++;
        }
        return maxlen;
    }
};