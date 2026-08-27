class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        vector<vector<int>> dis(n, vector<int>(n, 1e9));

        queue<pair<int, pair<int, int>>> q;

        q.push({1, {0,0}});
        dis[0][0] = 1;

        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while(!q.empty()){
            auto node = q.front();
            int dist = node.first;
            int row = node.second.first;
            int col = node.second.second;
            q.pop();

            for(int d=0; d<8; d++){
                int nrow = row + dx[d];
                int ncol = col + dy[d];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 0 && 
                dis[row][col] + 1 < dis[nrow][ncol]){
                    dis[nrow][ncol] = dis[row][col] + 1;
                    q.push({dis[nrow][ncol], {nrow, ncol}});
                }
            }
        }

        return dis[n-1][n-1] == 1e9 ? -1 : dis[n-1][n-1];

    }
};