class Solution {
public:
    bool dfs(int i,int col, vector<int>& color, vector<vector<int>>& graph){
        color[i] = col;

        for(auto adj : graph[i]){
            if(color[adj] == -1 && dfs(adj, !col, color, graph) == false){
                return false;
            }else if(color[adj] == col) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n, -1);
        for(int i=0; i<n; i++){
            if(color[i] == -1){
                if(dfs(i, 0, color, graph) == false) return false;
            }
        }
        return true;
    }
};