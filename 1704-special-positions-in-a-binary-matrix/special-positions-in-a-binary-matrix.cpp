class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> rows(m, -1);
        vector<int> cols(n, -1);

        for(int i=0; i<m; i++){
            int sum = 0;
            for(int j=0; j<n; j++){
                sum+= mat[i][j];
            }
            rows[i] = sum;
        }
        for(int j=0; j<n; j++){
            int sum = 0;
            for(int i=0; i<m; i++){
                sum+= mat[i][j];
            }
            cols[j] = sum;
        }
        int count = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 1 && rows[i] == 1 && cols[j] == 1){
                    count++;
                }
            }
        }
        return count;
    }
};