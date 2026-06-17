class Solution {
public:
    bool dfs(int node, vector<int>& visited, vector<vector<int>>& adjList, vector<int>& pathVis){
        visited[node] = 1;
        pathVis[node] = 1;
        for(auto adjNode : adjList[node]){
            if(!visited[adjNode]){
                if(dfs(adjNode, visited, adjList, pathVis) == true) return true;
            }else if(pathVis[adjNode]){
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> adjList(numCourses);

        for(int i=0; i<n; i++){
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> visited(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        
        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                if(dfs(i, visited, adjList, pathVis) == true) return false;
            }
        }
        return true;
    }
};