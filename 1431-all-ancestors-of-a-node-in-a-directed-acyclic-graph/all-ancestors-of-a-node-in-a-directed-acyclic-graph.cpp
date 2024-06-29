class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        vector<vector<int>> result(n);
        vector<set<int>> ancestors(n);
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        queue<int> q;
        
        for(auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            degree[edge[1]]++;
        }

        for(int i = 0; i < n; i++) {
            if (degree[i] == 0) {
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            result[node] = vector<int>(ancestors[node].begin(), ancestors[node].end());
            for (int& child : adj[node]) {
                ancestors[child].insert(node);
                ancestors[child].insert(ancestors[node].begin(), ancestors[node].end());
                if (--degree[child] == 0) {
                    q.push(child);
                }
            }
        }
        return result;
    }
};