class Solution {
private:
    int func(vector<vector<int>>& dp, vector<int>& prices, int canBuy, int idx) {
        if(idx >= prices.size()) {
            return 0;
        }
        if(dp[idx][canBuy] != -1) {
            return dp[idx][canBuy];
        }
        int a = INT_MIN, b = INT_MIN;
        if(canBuy) {
            return dp[idx][canBuy] = max(-prices[idx] + func(dp, prices, 1 - canBuy, idx + 1), func(dp, prices, canBuy, idx + 1));
        }
        return dp[idx][canBuy] = max(prices[idx] + func(dp, prices, 1 - canBuy, idx + 2), func(dp, prices, canBuy, idx + 1));
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return func(dp, prices, 1, 0);
    }
};