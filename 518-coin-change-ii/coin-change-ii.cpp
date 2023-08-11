class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> oldDp(amount + 1, 0);
        oldDp[0] = 1;
        for(int i = coins.size() - 1; i >= 0; i--) {
            vector<int> dp(amount + 1, 0);
            dp[0] = 1;
            for(int j = 1; j < amount + 1; j++) {
                dp[j] = oldDp[j];
                if(j - coins[i] >= 0) {
                    dp[j] += dp[j - coins[i]];
                }
            }
            oldDp = dp;
        }
        return oldDp[amount];
    }
};