class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> result, degree(n, 0);
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int& node : graph[i]) {
                adj[node].push_back(i);
                degree[i]++;
            }
        }
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(degree[i] == 0)
                q.push(i);
        }
        vector<bool> safeNode(n, false);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            safeNode[node] = true;
            for(int& neighbour : adj[node]) {
                if(--degree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }
        for(int i = 0; i < n; i++) {
            if(safeNode[i])
                result.push_back(i);
        }
        return result;
    }
};