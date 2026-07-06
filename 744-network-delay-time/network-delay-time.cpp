class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adjList(n+1);

        for(int i=0; i<times.size(); i++){
            adjList[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> pq;
        vector<int> dist(n+1, 1e9);

        pq.push({0, k});
        dist[k] = 0;
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto adj : adjList[node]){
                if(dis + adj.second < dist[adj.first]){
                    dist[adj.first] = dis + adj.second;
                    pq.push({dist[adj.first], adj.first});
                }
            }
        }
        int minTime = 0;

        for(int i=1; i<=n; i++){
            if(dist[i] == 1e9){
                return -1;
            }else{
                minTime = max(minTime, dist[i]);
            }
        }
        return minTime;

        

    }
};