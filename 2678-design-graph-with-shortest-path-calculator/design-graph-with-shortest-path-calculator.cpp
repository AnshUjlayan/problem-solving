class Graph {
public:
    vector<vector<pair<int,int>>> adj;

    int bfs(int curr, int goal) {
        vector<bool> visited(adj.size(), false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, curr});
        while(!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();
            visited[node] = true;
            if(node == goal) {
                return cost;
            }
            for(auto& [dest, edge] : adj[node]) {
                if(!visited[dest]) {
                    pq.push({cost + edge, dest});
                }
            }
        }
        return -1;
    }
    
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        return bfs(node1, node2);
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */