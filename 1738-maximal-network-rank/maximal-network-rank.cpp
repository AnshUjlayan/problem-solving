class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int result = 0;
        vector<vector<int>> adj(n);
        vector<int> deg(n, 0);
        for(auto& road : roads) {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
            deg[road[0]]++;
            deg[road[1]]++;
        }
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int network = deg[i] + deg[j];
                if(find(adj[i].begin(), adj[i].end(), j) != adj[i].end() || find(adj[j].begin(), adj[j].end(), i) != adj[j].end()) {
                    network--;
                }
                result = max(result, network);
            }
        }
        return result;
    }
};