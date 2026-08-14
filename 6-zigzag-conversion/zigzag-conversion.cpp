class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();

        if (numRows == 1 || numRows >= n)
            return s;

        int cycle = 2 * (numRows - 1);

        int pairs = (n + cycle - 1) / cycle;
        int cols = pairs * (numRows - 1);
        vector<vector<char>> mat (numRows, vector<char>(cols, '&'));
        int k = 0;
        int j = 0;
        while(k<n){
            for(int i=0; i<numRows && k<n; i++){
                mat[i][j] = s[k];
                k++;
            }
            j++;
            for(int i=numRows-2; i>0 && k<n; i--){
                mat[i][j] = s[k];
                j++;
                k++;
            }
        }
        string ans;
        for(int i=0; i<numRows; i++){
            for(int j=0; j<cols; j++){
                if(mat[i][j] != '&') ans.push_back(mat[i][j]);
            }
        }

        return ans;
        
    }
};