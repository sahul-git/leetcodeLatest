class Solution {
public:
    bool isPalindrome(string& s, int i, int j){
        int left = i;
        int right = j;
        while(left < right){
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    int solve(string& s, int k, int i, int j, vector<vector<int>>& dp){
        if(i >= s.size() || j>= s.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(isPalindrome(s, i, j)){
            int take = 1 + solve(s, k, j+1, j+k, dp);
            int grow = solve(s, k, i, j+1, dp);
            int slide = solve(s, k, i+1, j+1, dp);

            return dp[i][j] = max({take, grow, slide});

        }

        int grow = solve(s, k, i, j+1, dp);
        int slide = solve(s, k, i+1, j+1, dp);

        return dp[i][j] = max(grow, slide);
    }
    int maxPalindromes(string s, int k) {
        int n = s.size();
        if( k == 1) return n;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(s, k, 0, k-1, dp);
    }
};