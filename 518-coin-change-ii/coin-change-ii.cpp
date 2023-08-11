class Solution {
private:
    int func(vector<int>& coins, vector<vector<int>>& dp, int amount, int idx) {
        if(amount == 0) {
            return 1;
        }
        if(idx == coins.size() || amount < 0) {
            return 0;
        }
        if(dp[idx][amount] != -1) {
            return dp[idx][amount];
        }
        return dp[idx][amount] = func(coins, dp, amount - coins[idx], idx) + func(coins, dp, amount, idx + 1);
    }
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return func(coins, dp, amount, 0);
    }
};