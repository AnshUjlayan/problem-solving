class Solution {
private:
    bool dfs(vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& pathVis, int node) {
        if(pathVis[node])
            return true;
        if(visited[node])
            return false;
        visited[node] = true;
        pathVis[node] = true;
        for(int& neighbour : adj[node]) {
            if(dfs(adj, visited, pathVis, neighbour)) {
                return true;
            }
        }
        pathVis[node] = false;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses), pathVis(numCourses);
        vector<vector<int>> adj(numCourses);
        for(auto& prerequisite : prerequisites) {
            adj[prerequisite[1]].push_back(prerequisite[0]);
        }
        for(int i = 0; i < numCourses; i++) {
            if(dfs(adj, visited, pathVis, i)) {
                return false;
            }
        }
        return true;
    }
};