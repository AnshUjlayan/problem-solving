class Solution {
private:
    bool slimy(vector<int>& dp, vector<vector<int>>& graph, int node) {
        if(graph[node].size() == 0) {
            return true;
        }
        if(dp[node] != -1) {
            return dp[node];
        }
        dp[node] = false;
        bool slime = true;
        for(int& neighbour : graph[node]) {
            slime = slime && slimy(dp, graph, neighbour);
        }
        return dp[node] = slime;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> dp(n, -1), result;
        for(int i = 0; i < n; i++) {
            if(slimy(dp, graph, i)) {
                result.push_back(i);
            }
        }
        return result;
    }
};