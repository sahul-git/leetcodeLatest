class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int,int>>, 
                       vector<pair<int, pair<int,int>>>, 
                       greater<pair<int, pair<int,int>>>> pq;
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row == n-1 && col == m-1) return diff;
            for(int d = 0; d<4; d++){
                int nrow = row + dr[d];
                int ncol = col + dc[d];
                if(nrow >=0 && ncol>=0 && nrow < n && ncol < m){
                    int newEffort = max(abs(heights[row][col] - heights[nrow][ncol]), diff);
                    if(newEffort < dist[nrow][ncol]){
                        dist[nrow][ncol] = newEffort;
                        pq.push({dist[nrow][ncol], {nrow, ncol}});
                    }

                }
            }
            




        }
        return 0;


    }
};