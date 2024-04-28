class Solution {
private:
    int dist(int i, int j, int n) {
        if(i > j) return dist(j, i, n);
        int a = j - i;
        int b = i + (n - j);
        return min(a, b);
    }

    int func(vector<vector<int>>& dp, vector<vector<int>>& adj, string& ring,
             string& key, int i, int j) {
        if (j == key.size()) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (ring[i] == key[j]) {
            return dp[i][j] = 1 + func(dp, adj, ring, key, i, j + 1);
        }
        int result = 1e9;
        for (int& idx : adj[key[j] - 'a']) {
            if (idx != i) {
                result = min(result, dist(i, idx, ring.size()) +
                                         func(dp, adj, ring, key, idx, j));
            }
        }
        return dp[i][j] = result;
    }

public:
    int findRotateSteps(string& ring, string& key) {
        int n = ring.size();
        vector<vector<int>> dp(n, vector<int>(key.size(), -1)), adj(26);
        for (int i = 0; i < n; i++) {
            adj[ring[i] - 'a'].push_back(i);
        }
        return func(dp, adj, ring, key, 0, 0);
    }
};