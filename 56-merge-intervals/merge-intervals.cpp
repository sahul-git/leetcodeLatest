class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for(int i=1; i<n; i++){
            vector<int> temp = ans.back();
            

            if(temp[1] >= intervals[i][0]){
                temp[0] = min(intervals[i][0], temp[0]);
                temp[1] = max(intervals[i][1], temp[1]);
                ans.pop_back();
                ans.push_back(temp);
            }else{
                ans.push_back(intervals[i]);
            }


        }

        return ans;
    }
};