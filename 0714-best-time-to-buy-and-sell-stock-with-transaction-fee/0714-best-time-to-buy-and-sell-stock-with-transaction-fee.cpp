class Solution {
private:
    int func(vector<int>& prices, int& fee, vector<vector<int>>& dp, int idx, int canBuy) {
        if(idx >= prices.size())
            return 0;
        if(dp[idx][canBuy] != -1)
            return dp[idx][canBuy];
        if(!canBuy)
            return dp[idx][canBuy] = max(prices[idx] + func(prices, fee, dp, idx + 1, 1), func(prices, fee, dp, idx + 1, 0));
        return dp[idx][canBuy] = max(func(prices, fee, dp, idx + 1, 0) - fee - prices[idx], func(prices, fee, dp, idx + 1, 1));
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return func(prices, fee, dp, 0, 1);
    }
};