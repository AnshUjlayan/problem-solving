class Solution {
private:
    struct graphNode {
        int node, color, dist;
        graphNode(int node, int color, int dist) : node(node), color(color), dist(dist) {}
    };
    vector<int> bfs(vector<vector<pair<int,int>>>& adj, int n) {
        vector<int> result(n, -1);
        vector<vector<bool>> visited(n, vector<bool>(2, false));
        visited[0][0] = true;
        visited[0][1] = true;
        queue<graphNode> q;
        q.push(graphNode(0, -1, 0));
        result[0] = 0;
        while(!q.empty()) {
            auto [node, color, dist] = q.front();
            q.pop();
            for(auto& [neighbour, newColor] : adj[node]) {
                if(!visited[neighbour][newColor] && newColor != color) {
                    visited[neighbour][newColor] = true;
                    q.push(graphNode(neighbour, newColor, dist + 1));
                    if(result[neighbour] == -1) {
                        result[neighbour] = dist + 1;
                    }
                }
            }
        }
        return result;
    }
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& edge : redEdges) {
            adj[edge[0]].push_back({edge[1], 0});
        }
        for(auto& edge : blueEdges) {
            adj[edge[0]].push_back({edge[1], 1});
        }
        return bfs(adj, n);
    }
};