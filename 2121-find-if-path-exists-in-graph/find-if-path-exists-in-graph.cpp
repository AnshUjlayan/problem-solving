class Solution {
private:
    bool dfs(vector<vector<int>>& adj, vector<bool>& visited, int node, int dest) {
        if(node == dest) return true;
        if(visited[node]) return false;
        visited[node] = true;
        for(int& neighbour : adj[node]) {
            if(dfs(adj, visited, neighbour, dest)) return true;
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        for(auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return dfs(adj, visited, source, destination);
    }
};