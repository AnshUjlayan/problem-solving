class Solution {
private:
    int func(vector<vector<int>>& events, vector<vector<int>>& dp, int k, int prev, int idx) {
        if(k == 0 || idx == events.size()) {
            return 0;
        }
        if(prev >= events[idx][0]) {
            return func(events, dp, k, prev, idx + 1);
        }
        if(dp[idx][k] != -1) {
            return dp[idx][k];
        }
        return dp[idx][k] = max(events[idx][2] + func(events, dp, k - 1, events[idx][1], idx + 1), func(events, dp, k, prev, idx + 1));
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        vector<vector<int>> dp(events.size(), vector<int>(k + 1, -1));
        return func(events, dp, k, 0, 0);
    }
};