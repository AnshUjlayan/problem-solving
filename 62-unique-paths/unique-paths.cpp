class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n);
        dp[0] = 1;
        for(int i = 0; i < m; i++) {
            vector<int> nextDp = dp;
            for(int j = 0; j < n; j++) {
                if(j > 0) {
                    nextDp[j] += nextDp[j - 1];
                }
            }
            dp = nextDp;
        }
        return dp[n - 1];
    }
};