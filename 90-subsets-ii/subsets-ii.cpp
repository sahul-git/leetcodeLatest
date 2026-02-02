class Solution {
public:
    void solve(vector<int>& nums, vector<int>& curr,int ind, vector<vector<int>>& result ){
        
        result.push_back(curr);
        for(int i=ind; i<nums.size(); i++){
            if(i > ind && nums[i] == nums[i-1]){
                continue;
            }
            curr.push_back(nums[i]);
            solve(nums, curr, i+1, result);
            curr.pop_back();
           
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        solve(nums, curr, 0, result);
        return result;
    }
};