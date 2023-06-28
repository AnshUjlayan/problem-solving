class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double> probs(n, 0.0);
        vector<vector<pair<int,double>>> adj(n);
        vector<double> dp(n, -1.0);
        int i = 0;
        for(auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], succProb[i]});
            adj[edge[1]].push_back({edge[0], succProb[i++]});
        }
        priority_queue<pair<double,int>> pq;
        pq.push({1.0, start});
        probs[start] = 1.0;
        while(!pq.empty()) {
            pair<double,int> node = pq.top();
            pq.pop();
            for(auto& bro : adj[node.second]) {
                double newProb = node.first * bro.second;
                if(newProb > probs[bro.first]) {
                    probs[bro.first] = newProb;
                    pq.push({probs[bro.first], bro.first});
                }
            }
        }
        return probs[end];
    }
};