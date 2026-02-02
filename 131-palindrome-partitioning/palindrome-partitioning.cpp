class Solution {
public:
    bool check(string& s,int i, int j, vector<vector<int>>& dp){
        if(i>= j){
           return true;
        }
        if (dp[i][j] != -1)
        return dp[i][j] ;

        if (s[i] != s[j])
            return dp[i][j] = 0;
        return dp[i][j] = check(s, i+1, j-1, dp);
    }

    void solve(string& s, vector<string>& curr, int ind, vector<vector<int>>& dp, vector<vector<string>>& ans){
        if(ind==s.size()){
            ans.push_back(curr);
            return;
        }
         for(int i=ind; i<s.size(); i++){
            if(check(s, ind, i , dp) == true){
                curr.push_back(s.substr(ind, i-ind + 1));
                solve(s, curr, i+1, dp, ans);
                curr.pop_back();
            }
         }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string> curr;
        vector<vector<int>> temp(n, vector<int>(n, -1));
        solve(s, curr, 0, temp, ans );
        return ans;
    }
};