class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < coins.size(); i++) {
            vector<int> nextDp = dp;
            for(int j = 0; j < amount + 1; j++) {
                if(j - coins[i] >= 0) {
                    nextDp[j] += nextDp[j - coins[i]];
                }
            }
            dp = nextDp;
        }
        return dp[amount];
    }
};