class Solution {
private:
    int func(vector<int>& dp, int low, int high, int zero, int one, int len) {
        if (len > high) {
            return 0;
        }
        if (dp[len] != -1) {
            return dp[len];
        }
        return dp[len] = (1ll * (len >= low) + func(dp, low, high, zero, one, len + zero) +
                          func(dp, low, high, zero, one, len + one)) %
                         (int)(1e9 + 7);
    }

public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, -1);
        return func(dp, low, high, zero, one, 0);
    }
};