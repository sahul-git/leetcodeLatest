class Solution {
public:
    void dfs(int srow, int scol,int m, int n, vector<vector<char>>& board, vector<vector<int>>& visited){
        visited[srow][scol] = 1;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};

        for(int i=0; i<4; i++){
            int nrow = srow + dx[i];
            int ncol = scol + dy[i];
            if(0<= nrow && nrow < m && 0<= ncol && ncol < n && board[nrow][ncol] == 'O' && visited[nrow][ncol] != 1)
                dfs(nrow, ncol, m, n, board, visited);
        }
    }
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for(int j=0; j<n; j++){
            if(board[0][j] == 'O' && !visited[0][j]){
                dfs(0, j, m, n, board, visited);
            }
        }
        for(int j=0; j<n; j++){
            if(board[m-1][j] == 'O' && !visited[m-1][j]){
                dfs(m-1, j, m, n, board, visited);
            }
        }
        for(int i=0; i<m; i++){
            if(board[i][0] == 'O' && visited[i][0] != 1){
                dfs(i, 0, m, n, board, visited);
            }
        }
        for(int i=0; i<m; i++){
            if(board[i][n-1] == 'O' && visited[i][n-1] != 1){
                dfs(i, n-1, m, n, board, visited);
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O' && visited[i][j]!= 1){
                    board[i][j] = 'X';
                }
            }
        }

    }
};