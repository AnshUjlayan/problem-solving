class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int mod = 1e9 + 7;
        vector<int> dp(target + 1, 0);
        dp[target] = 1;
        for(int i = 0; i < n; i++) {
            int m = dp.size();
            vector<int> nextDp(m - 1, 0);
            for(int j = 0; j < m; j++) {
                for(int x = 1; x <= k; x++) {
                    if(j - x < 0) {
                        continue;
                    }
                    long long calc = (long long)dp[j] + nextDp[j - x];
                    calc %= mod;
                    nextDp[j - x] = calc;
                }
            }
            dp = nextDp;
        }
        return dp[0];
    }
};