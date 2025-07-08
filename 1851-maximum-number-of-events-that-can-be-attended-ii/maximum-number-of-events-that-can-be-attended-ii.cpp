class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr) || cout.tie(nullptr);
        int n = events.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        sort(events.begin(), events.end());
        auto comp = [](int val, const vector<int>& event) { return val < event[0]; };
        for (int i = 0; i < n; i++) {
            int idx = upper_bound(events.begin() + i + 1, events.end(), events[i][1], comp) - events.begin();
            for (int j = 0; j < k; j++) {
                dp[idx][j + 1] = max(dp[idx][j + 1], dp[i][j] + events[i][2]);
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            }
        }
        int res = 0;
        for (int i = 0; i < dp.size(); ++i) res = max(res, *max_element(dp[i].begin(), dp[i].end()));
        return res;
    }
};