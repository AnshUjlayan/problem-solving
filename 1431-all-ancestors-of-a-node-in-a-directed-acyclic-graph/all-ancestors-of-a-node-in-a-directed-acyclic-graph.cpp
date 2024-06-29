class Solution {
private:
    void dfs(vector<vector<int>>& result, vector<vector<int>>& adj, int ancestor, int node) {
        for(int& child : adj[node]) {
            if(!result[child].size() || (result[child].back() != ancestor)) {
                result[child].push_back(ancestor);
                dfs(result, adj, ancestor, child);
            }
        }
    }

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<vector<int>> result(n), adj(n);
        for(auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        for(int i = 0; i < n; i++) {
            dfs(result, adj, i, i);
        }
        return result;
    }
};