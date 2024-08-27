class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        vector<vector<pair<int,double>>> adj(n);
        priority_queue<pair<double,int>> pq;
        vector<double> result(n, 0.0);
        result[start_node] = 1.0;
        pq.push({1.0, start_node});

        for (int i = 0; i < succProb.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        while (!pq.empty()) {
            auto [prob, node] = pq.top();
            pq.pop();
            result[node] = prob;
            if (node == end_node)
                break;
            for (auto& [neighbour, neighbourProb] : adj[node]) {
                if (result[neighbour] == 0.0) {
                    pq.push({prob * neighbourProb, neighbour});
                }
            }
        }
        return result[end_node];
    }
};