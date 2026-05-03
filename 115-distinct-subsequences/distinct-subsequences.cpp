class Solution {
public:
    int countSub(int i, int j, string& s, string& t, int count, vector<vector<int>>& dp){
        if(i<0 || j<0){
            if(count == t.size()) return 1;
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int take = 0;
        if(s[i] == t[j]){
            take = countSub(i-1, j-1, s, t, count+1, dp);
        }
        int notTake = countSub(i-1, j, s, t, count, dp);
        return dp[i][j] = take + notTake;
    }
    int numDistinct(string s, string t) {
        int n =s.size();
        int m =t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return countSub(n-1, m-1, s, t, 0 , dp);
    }
};