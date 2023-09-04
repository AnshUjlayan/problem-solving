class DSU {
private:
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int nodes) {
        this->rank.resize(nodes, 0);
        this->parent.resize(nodes);
        for(int i = 0; i < nodes; i++) {
            this->parent[i] = i;
        }
    }
    int find(int u) {
        if(this->parent[u] != u) {
            return this->parent[u] = find(this->parent[u]);
        }
        return this->parent[u];
    }
    void join(int u, int v) {
        int parentU = find(u);
        int parentV = find(v);
        if(this->rank[parentU] > this->rank[parentV]) {
            this->parent[parentV] = parentU;
        }
        else if(this->rank[parentU] < this->rank[parentV]) {
            this->parent[parentU] = parentV;
        }
        else {
            this->parent[parentV] = parentU;
            this->rank[parentU]++;
        }
    }
    bool same(int u, int v) {
        return find(u) == find(v);
    }
};

class Solution {
private:
    int getMST(vector<vector<int>>& edges, int nodes) {
        DSU dsu(nodes);
        int cost = 0;
        for(auto& edge : edges) {
            if(!dsu.same(edge[1], edge[2])) {
                dsu.join(edge[1], edge[2]);
                cost += edge[0];
            }
        }
        return cost;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> edges;
        for(int i = 0; i < points.size(); i++) {
            for(int j = i + 1; j < points.size(); j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist, i, j});
            }
        }
        sort(edges.begin(), edges.end());
        return getMST(edges, points.size());
    }
};