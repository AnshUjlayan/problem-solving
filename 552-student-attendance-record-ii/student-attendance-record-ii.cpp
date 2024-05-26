class Solution {
private:
    const long long MOD = 1e9 + 7;
    long long getSlimy(vector<vector<vector<int>>>& dp, int n, int absent, int late) {
        if(absent > 1 || late > 2) {
            return 0;
        }
        if(!n) {
            return 1;
        }
        if(dp[n][absent][late] != -1) {
            return dp[n][absent][late];
        }
        return dp[n][absent][late] = (
            getSlimy(dp, n - 1, absent, 0) +
            getSlimy(dp, n - 1, absent + 1, 0) +
            getSlimy(dp, n - 1, absent, late + 1)
        ) % MOD;
    }

public:
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return static_cast<int>(getSlimy(dp, n, 0, 0));
    }
};