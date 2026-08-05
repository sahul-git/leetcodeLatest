class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        int len = invocations.size();
        vector<vector<int>> adjList(n);
        for(int i=0; i<len; i++){
            adjList[invocations[i][0]].push_back(invocations[i][1]);
        }

        queue<int> q;
        q.push(k);
        
        vector<int> visited(n, -1);
        visited[k] = 1;
        vector<int>suspicious(n, 0);

        while(!q.empty()){
            int node = q.front();
            q.pop();
            suspicious[node] = 1;
            for(auto adj : adjList[node]){
                if(visited[adj]!= 1){
                    q.push(adj);
                    visited[adj] = 1;
                }
            }

        }

        vector<int> methods;
        for(int i=0; i<n; i++){
            methods.push_back(i);
        }
        vector<int> ans;

        for(int i=0; i<n; i++){
            if(suspicious[i] == 1){
                continue;
            }else{
                
                for(auto ele : adjList[i]){
                    if(suspicious[ele] == 1) return methods;
                }
                ans.push_back(i);
            }

        }

        return ans;


        
       

        
    }
};