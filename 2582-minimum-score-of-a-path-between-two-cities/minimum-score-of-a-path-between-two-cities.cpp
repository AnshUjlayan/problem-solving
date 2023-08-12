class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n + 1);
        vector<bool> visited(n + 1, false);
        queue<int> q;
        for(auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        q.push(1);
        int result = 1e4;
        while(!q.empty()) {
            vector<pair<int,int>> cities = adj[q.front()];
            q.pop();
            for(auto& city : cities) {
                result = min(result, city.second);
                if(!visited[city.first]) {
                    q.push(city.first);
                    visited[city.first] = true;
                }
            }
        }
        return result;
    }
};