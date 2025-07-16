class Solution {
private:
    int func(vector<vector<vector<int>>>& dp, vector<vector<int>>& adj, string& label, int u, int v, int mask) {
        if (dp[max(u, v)][min(u, v)][mask] != -1) {
            return dp[max(u, v)][min(u, v)][mask];
        }
        int res = 0;
        for (int a : adj[u]) {
            for (int b : adj[v]) {
                if (a != b && label[a] == label[b] && !(mask & (1 << a)) && !(mask & (1 << b))) {
                    res = max(res, func(dp, adj, label, a, b, mask | (1 << a) | (1 << b)));
                }
            }
        }
        return dp[max(u, v)][min(u, v)][mask] = res + 2;
    }
    
public:
    int maxLen(int n, vector<vector<int>>& edges, string label) {
        int res = 0;
        vector<vector<int>> adj(n);
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(1 << n, -1)));
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for (int i = 0; i < n; i++) {
            res = max(res, func(dp, adj, label, i, i, 1 << i) - 1);
        }
        for (auto& edge : edges) {
            if (label[edge[0]] == label[edge[1]]) {
                res = max(res, func(dp, adj, label, edge[0], edge[1], (1 << edge[0]) | (1 << edge[1])));
            }
        }
        return res;
    }
};