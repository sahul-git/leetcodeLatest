class Solution {
public:
    void combSum(int i, int n, vector<int>& candidates, vector<int>& arr,
                 vector<vector<int>>& ans, int target, int sum) {

        if(sum == target){
            ans.push_back(arr);
            return;
        }

        if(i >= n || sum > target){
            return;
        }

        for(int ind = i; ind < candidates.size(); ind++){  

            // skip duplicates
            if(ind > i && candidates[ind] == candidates[ind-1]) continue;

            if(sum + candidates[ind] > target) break;  

            arr.push_back(candidates[ind]);

            combSum(ind + 1, n, candidates, arr, ans, target,
                    sum + candidates[ind]); 
            arr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> arr;

        sort(candidates.begin(), candidates.end());

        combSum(0, candidates.size(), candidates, arr, ans, target, 0);
        return ans;
    }
};