class Solution {
public:
    void combSum(int i, int n, vector<int>& candidates, vector<int>&arr,vector<vector<int>>& ans, int target, int sum){
        if(sum == target){
            ans.push_back(arr);
            return;
        }
        if(i >= n || sum> target){
            return ;
        }
        arr.push_back(candidates[i]);
        combSum(i, n, candidates, arr, ans, target, sum+candidates[i]);
        arr.pop_back();
        combSum(i+1, n, candidates, arr, ans, target, sum);
         
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        combSum(0,  candidates.size(),candidates,  arr, ans, target, 0);
        return ans;

    }
};