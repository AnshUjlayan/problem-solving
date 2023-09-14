class Solution {
private:
    bool dfs(unordered_map<string,vector<string>>& adj, unordered_map<string,vector<int>>& visited, vector<string>& result, string curr, int numEdges) {
        if(numEdges == 0) {
            return true;
        }
        for(int idx = 0; idx < adj[curr].size(); idx++) {
            if(visited[curr][idx]) {
                continue;
            }
            result.push_back(adj[curr][idx]);
            visited[curr][idx] = true;
            if(dfs(adj, visited, result, adj[curr][idx], numEdges - 1)) {
                return true;
            }
            visited[curr][idx] = false;
            result.pop_back();
        }
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>> adj;
        unordered_map<string,vector<int>> visited;
        int numEdges = 0;
        for(auto& ticket : tickets) {
            adj[ticket[0]].push_back(ticket[1]);
            numEdges++;
        }
        for(auto& [dept, dest] : adj) {
            visited[dept].resize(dest.size());
            sort(dest.begin(), dest.end());
        }
        vector<string> result {"JFK"};
        dfs(adj, visited, result, "JFK", numEdges);
        return result;
    }
};