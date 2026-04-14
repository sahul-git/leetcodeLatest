class Solution {
public:
    void combSum(int i, int k, int n, vector<int>& arr, vector<vector<int>>& ans, int sum){
        if(sum == n && k<1){
            ans.push_back(arr);
            return;
        } 
        if(i > 9 || k < 1){
            return;
        }
        if(sum + i <= n){
            arr.push_back(i);
            combSum(i+1, k-1, n,  arr, ans, sum+i);
            arr.pop_back();
        }
        
        combSum(i+1, k, n,  arr, ans, sum);
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> arr;
        combSum(1, k, n, arr, ans, 0);
        return ans;
    }
};