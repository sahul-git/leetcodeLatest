class Solution {
public:
    bool dfs(int src, vector<int>& vis, vector<int>& pathVis, vector<vector<int>>& graph, vector<int>& check){
        vis[src] = 1;
        pathVis[src] = 1;
        check[src] = 0;

        for(int adj : graph[src]){
            if(!vis[adj]){
                if(dfs(adj, vis, pathVis, graph, check)){
                    check[src] = 0;
                    return true;
                }
            }else if(pathVis[adj]){
                check[src] = 0;
                return true;
            }
        }
        check[src] = 1;
        pathVis[src] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);
        vector<int> check(n);

        for(int i=0; i<n; i++){
            if(vis[i]!= 1){
               dfs(i, vis, pathVis, graph, check);
            }
        }
        vector<int> safeNode;
        for(int i=0; i<n; i++){
            if(check[i]==1){
                safeNode.push_back(i);
            }
        }
        return safeNode;
    }
};