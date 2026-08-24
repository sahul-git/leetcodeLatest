class Solution {
public:
    bool solve(int i, string temp, vector<string>& words, string s,
               vector<vector<int>>& dp) {

        if(temp == s)
            return true;

        if(i < 0)
            return false;

        if(dp[i][temp.size()] != -1)
            return dp[i][temp.size()];

        bool take = false;

        if(temp.size() + words[i].size() <= s.size() &&
           s.substr(temp.size(), words[i].size()) == words[i]) {

            take = solve(words.size() - 1,
                         temp + words[i],
                         words, s, dp);
        }

        bool notTake = solve(i - 1, temp, words, s, dp);

        return dp[i][temp.size()] = take || notTake;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = wordDict.size();

        vector<vector<int>> dp(n, vector<int>(s.size() + 1, -1));

        return solve(n - 1, "", wordDict, s, dp);
    }
};