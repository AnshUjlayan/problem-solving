class DSU {
private:
    vector<int> parent;
    vector<int> rank;
    vector<int> groupSize;
public:
    DSU(int size) : parent(size), rank(size, 0), groupSize(size, 1) {
        for(int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }
    int find(int u) {
        if(parent[u] != u) {
            return parent[u] = find(parent[u]);
        }
        return u;
    }
    int getGroupSize(int node) {
        int parentNode = find(node);
        return groupSize[parentNode];
    }
    void join(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if(pu == pv) {
            return;
        }
        if(rank[pu] > rank[pv]) {
            parent[pv] = pu;
            groupSize[pu] += groupSize[pv];
            groupSize[pv] = 0;
        }
        else if(rank[pu] < rank[pv]) {
            parent[pu] = pv;
            groupSize[pv] += groupSize[pu];
            groupSize[pu] = 0;
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
            groupSize[pu] += groupSize[pv];
            groupSize[pv] = 0;
        }
    }
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        long long result = 0;
        for(auto& edge : edges) {
            dsu.join(edge[0], edge[1]);
        }
        for(int i = 0; i < n; i++) {
            result += (n - dsu.getGroupSize(i));
        }
        return result / 2;
    }
};