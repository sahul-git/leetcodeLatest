class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        if(image[sr][sc] == color) return image;

        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m, 0));
        
        q.push({sr,sc});
        
        vis[sr][sc] = 1;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(0<= nrow && nrow< n && 0<= ncol && ncol < m && image[nrow][ncol] == image[sr][sc] && vis[nrow][ncol]!=1){
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                    image[nrow][ncol] = color;
                }
            }
        }
        image[sr][sc] = color;
        return image;



    }
};