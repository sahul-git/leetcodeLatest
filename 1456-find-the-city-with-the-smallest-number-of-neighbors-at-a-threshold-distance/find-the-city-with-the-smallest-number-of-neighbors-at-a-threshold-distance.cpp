class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mat(n, vector<int>(n, 1e4 + 1));
        for(int i = 0; i<n ;i++){
            mat[i][i] = 0;
        }
        for(int i=0; i< edges.size(); i++){
            mat[edges[i][0]][edges[i][1]] =  edges[i][2];
            mat[edges[i][1]][edges[i][0]] =  edges[i][2];
        }
        for(int k=0; k< n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }

            }
        }
        
        int city = -1;
        int maxCount = INT_MAX;
        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=0;j < n ; j++){
                if(mat[i][j] <= distanceThreshold){
                    count++;
                }
            }
            if(maxCount > count){
                maxCount = count;
                city = i;
            }else if( maxCount == count){
                city = max(city, i);
            }
        }
        return city;

    }
};