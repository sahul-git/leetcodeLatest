class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        queue<pair<int, pair<int,int>>> q;

        dist[0][0] = 1;
        q.push({1, {0, 0}});

        int dx[] = {-1,-1,-1,0,0,1,1,1};
        int dy[] = {-1,0,1,-1,1,-1,0,1};

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int row = it.second.first;
            int col = it.second.second;

            for (int i = 0; i < 8; i++) {
                int nrow = row + dx[i];
                int ncol = col + dy[i];

                if (nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] == 0 &&
                    dist[row][col] + 1 < dist[nrow][ncol]) {

                    dist[nrow][ncol] = dist[row][col] + 1;
                    q.push({dist[nrow][ncol], {nrow, ncol}});
                }
            }
        }

        return dist[n-1][n-1] == 1e9 ? -1 : dist[n-1][n-1];
    }
};