class Solution {
public:
    string shortestCommonSupersequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                int take = 0;
                if(word1[i-1] == word2[j-1]){
                    take = dp[i-1][j-1] + 1;
                }else{
                    take = max(dp[i-1][j], dp[i][j-1]);
                }
                dp[i][j] = take;
            }
        }

        int i = n, j=m;
        string str = "";

        while(i > 0 && j > 0){
            if(word1[i-1] == word2[j-1]){
                str.push_back(word1[i-1]);
                i--; j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                str.push_back(word1[i-1]);
                i--;
            }
            else{
                str.push_back(word2[j-1]);
                j--;
            }
        }

        while(i > 0){
            str.push_back(word1[i-1]);
            i--;
        }

        while(j > 0){
            str.push_back(word2[j-1]);
            j--;
        }

        reverse(str.begin(), str.end());
        
        return str;
    }
};