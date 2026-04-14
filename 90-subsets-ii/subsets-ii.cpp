class Solution {
public:
    void formSubsets(int i, int n, vector<int>& nums, vector<int>&arr, vector<vector<int>>& ans){ 
        ans.push_back(arr);
            
        for(int ind = i; ind<n; ind++){
            if(ind>i && nums[ind] == nums[ind-1]){
                continue;
            }
            arr.push_back(nums[ind]);
            formSubsets(ind+1, n, nums, arr, ans);
            arr.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> arr;
        sort(nums.begin(), nums.end());
        formSubsets(0, n, nums, arr, ans);
        return ans;
    }
};