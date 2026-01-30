class Solution {
public:
    bool solve(string &s, int i, int j, vector<vector<int>>& t){
        if(i >= j) return true;
        if(t[i][j] != -1) return t[i][j];

        if(s[i] != s[j]){
            return t[i][j] = false;
        }
        return t[i][j] = solve(s, i+1, j-1, t);
    }

    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> t(n, vector<int>(n, -1));

        int maxi = 0;
        int startPoint = 0;

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(solve(s, i, j, t)){
                    if(maxi < j - i + 1){
                        maxi = j - i + 1;
                        startPoint = i;
                    }
                }
            }
        }
        return s.substr(startPoint, maxi);
    }
};
