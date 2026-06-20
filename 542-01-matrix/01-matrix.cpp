class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> ans(m, vector<int>(n,0));
        vector<vector<int>> visited(m, vector<int>(n,0));

        queue<pair<pair<int,int>, int>> q;
        for(int i=0; i<m;i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j}, 0});
                    visited[i][j] = 1;
                }
            }
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = row + dx[i];
                int ncol = col + dy[i];
                if(0<=nrow && nrow<m && 0<=ncol && ncol<n && !visited[nrow][ncol]){
                    q.push({{nrow, ncol}, dist+1});
                    ans[nrow][ncol] = dist+1;
                    visited[nrow][ncol] = 1;
                }
            }

        }
        return ans;
    }
};