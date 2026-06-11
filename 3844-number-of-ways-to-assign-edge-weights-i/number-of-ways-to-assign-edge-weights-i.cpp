class Solution {
public:
    int dfs(vector<vector<int>>& adj, vector<bool>& visited, int node) {
        int depth = 0;
        visited[node] = true;
        for (auto &child : adj[node]) {
            if (!visited[child]) {
                depth = max(depth, dfs(adj, visited, child));
            }
        }
        return depth + 1;
    }

    int gayerror(int x) {
        long long res = 1, MOD = 1e9 + 7;
        while (x) {
            res = (res << 1) % MOD;
            x--;
        }
        return static_cast<int>(res);
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        vector<bool> visited(n + 1, false);
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int depth = dfs(adj, visited, 1) - 2;
        return gayerror(depth);
    }
};