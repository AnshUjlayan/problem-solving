class Solution {
private:
    bool dfs(vector<vector<int>>& graph, vector<int>& colour, int node, int parent) {
        bool flag = true;
        colour[node] = 1 - colour[parent];
        for(int child : graph[node]) {
            if(colour[child] == -1 && !dfs(graph, colour, child, node)) {
                return false;
            }
            if(colour[child] == colour[node]) {
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colour(n, -1);
        for(int i = 0; i < n; i++) {
            if(colour[i] == -1 && !dfs(graph, colour, i, 0)) {
                return false;
            }
        }
        return true;
    }
};