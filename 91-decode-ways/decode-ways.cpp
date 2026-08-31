class Solution {
public:
    int waysToDecode(int ind, string s, int n, vector<int>& dp){
        if(ind == n) return 1; //Successfully reached the end.
        if(s[ind] == '0') return 0; // 0 cannot be decoded

        if(dp[ind] != -1) return dp[ind];

        int take1 = waysToDecode(ind + 1, s, n, dp);

        int take2 = 0;

        if(ind + 1 < n){
            int num = stoi(s.substr(ind, 2));

            if(num >= 10 && num <= 26){
                take2 = waysToDecode(ind + 2, s, n, dp);
            }
        }

        return dp[ind] = take1 + take2;


    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return waysToDecode(0, s, n, dp);
    }
};