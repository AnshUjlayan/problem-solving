class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);
        for(auto& time : times) {
            adj[time[0]].push_back({time[1], time[2]});
        }
        vector<int> minTime(n + 1, 1e9);
        minTime[0] = 0;
        minTime[k] = 0;
        queue<pair<int,int>> q;
        q.push({k, 0});
        while(!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();
            for(auto& [neighbour, cost] : adj[node]) {
                if(minTime[neighbour] > dist + cost) {
                    minTime[neighbour] = dist + cost;
                    q.push({neighbour, minTime[neighbour]});
                }
            }
        }
        int result = *max_element(minTime.begin(), minTime.end());
        return result == 1e9 ? -1 : result;
    }
};