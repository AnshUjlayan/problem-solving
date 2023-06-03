class Solution {
private:
    bool conditionMet(vector<vector<int>>& bombs, int i, int j) {
        double x = pow(bombs[i][0] - bombs[j][0], 2);
        double y = pow(bombs[i][1] - bombs[j][1], 2);
        return sqrt(x + y) <= bombs[i][2];
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size(), result = 0;
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j && conditionMet(bombs, i, j)) {
                    adj[i].push_back(j);
                }
            }
        }
        for(int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            queue<int> q;
            q.push(i);
            visited[i] = true;
            int count = 0;
            while(!q.empty()) {
                count++;
                int x = q.front();
                q.pop();
                for(int node : adj[x]) {
                    if(!visited[node]) {
                        visited[node] = true;
                        q.push(node);
                    }
                }
            }
            result = max(result, count);
        }
        return result;
    }
};