class Solution {
private:
    int dfs(vector<vector<int>>& adj, vector<int>& informTime, int cost, int node) {
        if(adj[node].empty()) {
            return 0;
        }
        int totalCost = 0;
        for(auto child : adj[node]) {
            totalCost = max(totalCost, dfs(adj, informTime, cost, child));
        }
        return informTime[node] + totalCost;
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++) {
            if(manager[i] == -1) {
                continue;
            }
            adj[manager[i]].push_back(i);
        }
        int result = 0;
        return dfs(adj, informTime, 0, headID);
    }
};