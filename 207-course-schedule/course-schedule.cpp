class Solution {
public:
    bool dfs(int src, vector<int>& vis, vector<int>& pathVis, vector<vector<int>>& adjList){
        vis[src] = 1;
        pathVis[src] = 1;

        for(int adj : adjList[src]){
            if(!vis[adj]){
                if(!dfs(adj, vis, pathVis, adjList)){
                    return false;
                }
            }else if(pathVis[adj]){
                return false;
            }
        }
        pathVis[src] = 0;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for(int i=0; i<prerequisites.size(); i++){
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        for(int i=0; i<numCourses; i++){
            if(vis[i]!= 1){
                if(dfs(i, vis, pathVis, adjList) == false){
                    return false;
                }
            }
        }
        return true;
    }
};