class Solution {
public:
    void reqComb(int ind, int target, vector<int>& candidates, vector<int>& comb, vector<vector<int>>& ans){
        if(ind < 0){
            if(target == 0) ans.push_back(comb);
            return;
        }
        if(candidates[ind] <= target){
            comb.push_back(candidates[ind]);
            reqComb(ind, target-candidates[ind], candidates, comb, ans);
            comb.pop_back();
        }
        reqComb(ind-1, target, candidates, comb, ans);
        

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> comb;
        vector<vector<int>> ans;
        reqComb(n-1, target, candidates, comb, ans);
        return ans;
    }
};