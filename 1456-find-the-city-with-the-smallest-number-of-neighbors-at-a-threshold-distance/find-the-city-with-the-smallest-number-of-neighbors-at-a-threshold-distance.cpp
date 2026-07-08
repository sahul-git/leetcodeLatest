class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        for(int i=0; i<edges.size(); i++){
            dist[edges[i][0]][edges[i][1]] = edges[i][2];
            dist[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        for(int i=0; i<n; i++){
            dist[i][i] = 0;
        }

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dist[i][k]!= 1e9 && dist[k][j]!= 1e9){
                        dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
                    }
                }
            }
        }

        int ans = 0;
        int mini = n;
        for(int i=0; i<n; i++){
            int neighbors = 0;
            for(int j=0; j<n; j++){
                if(dist[i][j] <= distanceThreshold){
                    neighbors++;
                }
            }
            if(neighbors <= mini){
                mini = neighbors;
                ans = i;
            }
        }


        return ans;

    }
};