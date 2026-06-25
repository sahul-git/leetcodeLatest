class Solution {
public:
    void dfs(int srow, int scol, vector<vector<char>>& grid, vector<vector<int>>& visited){
        int m = grid.size();
        int n = grid[0].size();
        visited[srow][scol] = 1;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};

        for(int i=0; i<4; i++){
            int row = srow + dx[i];
            int col = scol + dy[i];
            if(0 <= row && row< m && 0<= col && col < n && grid[row][col] == '1' && visited[row][col] == 0)  dfs(row, col, grid, visited);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        int countIslands = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1' && visited[i][j] == 0){
                    dfs(i, j, grid, visited);
                    countIslands++;
                }
            }
        }
        return countIslands;
    }
};