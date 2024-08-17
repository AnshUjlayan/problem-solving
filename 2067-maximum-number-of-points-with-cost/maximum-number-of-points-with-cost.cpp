class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        const int n = points[0].size();
        long long mx = INT_MIN;
        vector<long long> dp(n), nextDp(n), temp(n);
        for (vector<int>& row : points) {
            vector<long long> nextDp(row.begin(), row.end());
            temp.resize(n, 0);
            for (int i = n - 1; i >= 0; i--) {
                mx = max(mx, dp[i]);
                temp[i] = mx--;
            }
            mx = INT_MIN;
            for (int i = 0; i < n; i++) {
                mx = max(mx, dp[i]);
                nextDp[i] = max(nextDp[i] + temp[i], nextDp[i] + mx--);
            }
            dp = nextDp;
        }
        return *max_element(dp.begin(), dp.end());
    }
};