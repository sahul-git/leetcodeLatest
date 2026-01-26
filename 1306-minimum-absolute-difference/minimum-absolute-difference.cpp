class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int minidiff = INT_MAX;
        for(int i=0; i<n-1; i++){
            minidiff = min(abs(arr[i] - arr[i+1]) , minidiff);
        }
        for(int i=0; i<n-1; i++){
            if(abs(arr[i] - arr[i+1]) == minidiff)
            ans.push_back({arr[i],arr[i+1]});
        }

        return ans;

    }
};