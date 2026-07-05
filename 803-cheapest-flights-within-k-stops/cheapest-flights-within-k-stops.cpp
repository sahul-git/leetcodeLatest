class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adjList(n);

        for(int i=0; i<flights.size(); i++){
            adjList[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        queue<pair<int, pair<int, int>>> q;

        q.push({0,{src, 0}});

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int cost = it.first;
            int node = it.second.first;
            int stops = it.second.second;
            if(stops > k){
                continue;
            }

            for(auto adj : adjList[node]){
                int adjNode = adj.first;
                int price = adj.second;
                if(cost + price < dist[adjNode] && stops<=k){
                    dist[adjNode] = cost + price;
                    q.push({dist[adjNode], {adjNode, stops + 1}});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};