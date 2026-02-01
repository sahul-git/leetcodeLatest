class Solution {
public:
    void generate(vector<vector<int>>& ans, vector<int>& arr, vector<int>& nums, int i, int n){
        if(i == n){
            ans.push_back(arr);
            return;
        }
        generate(ans, arr, nums, i+1, n);
        arr.push_back(nums[i]);
        generate(ans, arr,nums,  i+1, n );
        arr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> temp;
        generate(ans, temp, nums, 0, n);
        return ans;


    }
};