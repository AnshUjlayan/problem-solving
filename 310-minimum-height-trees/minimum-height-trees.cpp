class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<vector<int>> adj(n);
        vector<int> result, degree(n, 0);
        queue<int> q;
        for(auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        for(int i = 0; i < n; i++) {
            if(degree[i] <= 1) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            result.clear();
            int length = q.size();
            while(length--) {
                int node = q.front();
                q.pop();
                result.push_back(node);
                for(int& neighbour : adj[node]) {
                    if(--degree[neighbour] == 1) {
                        q.push(neighbour);
                    }
                }
            }
        }
        return result;
    }
};