class DSU {
private:
    void makeSet() {
        for(int i = 0; i < parent.size(); i++) {
            parent[i] = i;
        }
    }
public:
    vector<int> parent, rank;
    DSU(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        makeSet();
    }
    int getParent(int node) {
        if(parent[node] == node) {
            return node;
        }
        return parent[node] = getParent(parent[node]);
    }
    void unionSets(int u, int v) {
        int parent_u = getParent(u);
        int parent_v = getParent(v);
        if(parent_u == parent_v) {
            return;
        }
        else if(rank[parent_u] < rank[parent_v]) {
            parent[parent_u] = parent_v;
        }
        else if(rank[parent_u] > rank[parent_v]) {
            parent[parent_v] = parent_u;
        }
        else {
            parent[parent_u] = parent_v;
            rank[parent_v]++;
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU dsu(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j] == 1) {
                    dsu.unionSets(i, j);
                }
            }
        }
        unordered_set<int> ust;
        for(int i = 0; i < n; i++) {
            ust.insert(dsu.getParent(i));
        }
        return ust.size();
    }
};