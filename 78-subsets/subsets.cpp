class Solution {
public:
    void formSubsets(int i, int n, vector<int>& nums, vector<int>&arr, vector<vector<int>>& ans){
        if(i >= n){
            ans.push_back(arr);
            return;
        }
        arr.push_back(nums[i]);
        formSubsets(i+1, n, nums, arr, ans);
        arr.pop_back();
        formSubsets(i+1, n, nums, arr, ans);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> arr;
        formSubsets(0, n, nums, arr, ans);
        return ans;
    }
};