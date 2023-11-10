class Solution {
private:
    void func(vector<int>& result, unordered_map<int,vector<int>>& adj, unordered_set<int>& visited, int node) {
        if(visited.count(node)) {
            return;
        }
        result.push_back(node);
        visited.insert(node);
        for(auto& next : adj[node]) {
            func(result, adj, visited, next);
        }
    }
    vector<int> getSlimy(unordered_map<int,vector<int>>& adj, int node) {
        vector<int> result;
        unordered_set<int> visited;
        func(result, adj, visited, node);
        return result;
    }
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>> adj;
        for(auto& adjPair : adjacentPairs) {
            adj[adjPair[0]].push_back(adjPair[1]);
            adj[adjPair[1]].push_back(adjPair[0]);
        }
        for(auto& record : adj) {
            if(record.second.size() == 1) {
                return getSlimy(adj, record.first);
            }
        }
        return {};
    }
};