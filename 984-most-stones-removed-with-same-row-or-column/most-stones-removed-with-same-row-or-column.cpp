class DSU {
private:
    int groups;
    unordered_map<int,int> parent;
    unordered_map<int,int> size;


public:
    DSU(int n) {
        groups = n;
    }

    int getGroups() {
        return groups;
    }

    int find(int u) {
        if (parent.find(u) == parent.end() || parent[u] == u)
            return u;
        return parent[u] = find(parent[u]);
    }

    void join(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) {
            return;
        }
        if (size[pv] >= size[pu]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        groups--;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int n = stones.size();
        DSU dsu(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    int u = stones[i][0] * 1e4 + stones[i][1];
                    int v = stones[j][0] * 1e4 + stones[j][1];
                    dsu.join(u, v);
                }
            }
        }
        return n - dsu.getGroups();
    }
};