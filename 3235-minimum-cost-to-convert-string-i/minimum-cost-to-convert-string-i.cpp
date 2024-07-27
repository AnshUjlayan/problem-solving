class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        int m = source.size(), n = original.size();
        vector<vector<int>> dist(26, vector<int>(26, INT_MAX));

        for (int i = 0; i < 26; i++) {
            dist[i][i] = 0;
        }

        for (int i = 0; i < n; i++) {
            dist[original[i] - 97][changed[i] - 97] =
                min(dist[original[i] - 97][changed[i] - 97], cost[i]);
        }

        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    if (dist[i][k] < INT_MAX && dist[k][j] < INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        long long result = 0;
        for (int i = 0; i < m; i++) {
            if (dist[source[i] - 97][target[i] - 97] == INT_MAX) {
                return -1;
            }
            result += dist[source[i] - 97][target[i] - 97];
        }

        return result;
    }
};