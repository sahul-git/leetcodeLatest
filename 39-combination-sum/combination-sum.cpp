class Solution {
public:
    vector<vector<int>> ans;
    void generate(vector<int>& arr, vector<int>& candidates,int sum,  int target,int i, int n){
        if(sum == target ){
            ans.push_back(arr);
            return ;
        }else if( i == n || sum > target){
            return;
        }
        arr.push_back(candidates[i]);
        generate(arr, candidates, sum + candidates[i], target, i, n);
        arr.pop_back();
        generate(arr, candidates, sum , target, i+1, n);

        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> arr;
        int sum = 0;
        generate(arr, candidates, sum, target, 0, n);
        return ans;
    }
};