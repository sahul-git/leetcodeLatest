class DisjointSet {
private:
    vector<int> rank, size;
    vector<int> parent;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findParent(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findParent(parent[node]);
    }

    bool find(int u, int v) {
        return findParent(u) == findParent(v);
    }

    void unionByRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv)
            return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else if (rank[pu] == rank[pv]) {
            parent[pv] = pu;
            rank[pu]++;
        }
        else {
            parent[pv] = pu;
        }
    }

    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv)
            return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        if(connections.size() < n-1) return -1;

        DisjointSet ds(n);

        int connection = n;

        for(int i=0; i<connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];
            if(ds.findParent(u) != ds.findParent(v)){
                ds.unionBySize(u, v);
                connection--;
            }
        }

        return connection-1;

    }
};