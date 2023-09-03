class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
public:
    UnionFind(int nodes) {
        rank.resize(nodes, 0);
        parent.resize(nodes);
        for(int i = 0; i < nodes; i++) {
            parent[i] = i;
        }
    }
    int find(int u) {
        if(parent[u] != u) {
            return find(parent[u]);
        }
        return parent[u];
    }
    void join(int u, int v) {
        int uParent = find(u);
        int vParent = find(v);
        if(rank[uParent] < rank[vParent]) {
            parent[uParent] = vParent;
        }
        else if(rank[uParent] > rank[vParent]) {
            parent[vParent] = uParent;
        }
        else {
            parent[vParent] = uParent;
            rank[uParent]++;
        }
    }
    bool same(int u, int v) {
        return find(u) == find(v);
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind uf(edges.size() + 1);
        for(auto& edge : edges) {
            if(uf.same(edge[0], edge[1])) {
                return edge;
            }
            uf.join(edge[0], edge[1]);
        }
        return {};
    }
};