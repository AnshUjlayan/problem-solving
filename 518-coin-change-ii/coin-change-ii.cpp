class Solution {
private:
    int func(vector<int>& coins, vector<vector<int>>& dp, int amount, int idx) {
        if(idx == coins.size()) {
            if(amount == 0) {
                return 1;
            }
            return 0;
        }
        if(dp[idx][amount] != -1) {
            return dp[idx][amount];
        }
        int res = 0;
        for(int i = 0; i <= amount / coins[idx]; i++) {
            res += func(coins, dp, amount - (i * coins[idx]), idx + 1);
        }
        return dp[idx][amount] = res;
    }
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return func(coins, dp, amount, 0);
    }
};