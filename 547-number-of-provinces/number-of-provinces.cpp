class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited){
        visited[node] = 1;
        for(auto it : adj[node]){
            if(visited[it]!=1){
                dfs(it, adj, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> visited(n);
        int count = 0;
        for(int i=0; i<n; i++){
            if(visited[i] != 1){
                count++;
                dfs(i, adj, visited);
                
            }
        }
        return count;



    }
};