class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        vector<int> arr(101, -1);
        for(int i=0; i<nums.size(); i++){
            arr[nums[i]] = 1;
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }
        vector<int> ans;
        for(int i = mini; i<= maxi; i++){
            if(arr[i] != 1) ans.push_back(i);
        }
        return ans;

    }
};