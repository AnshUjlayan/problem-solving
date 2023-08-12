class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n);
        dp[0] = 1;
        for(int i = 0; i < m; i++) {
            vector<int> newDp = dp;
            for(int j = 0; j < n; j++) {
                if(j > 0) {
                    newDp[j] += newDp[j - 1];
                }
            }
            dp = newDp;
        }
        return dp[n - 1];
    }
};