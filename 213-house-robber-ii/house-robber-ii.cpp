class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        auto func = [&](int l, int r) ->int {
            vector<int> dp(r + 1);
            dp[r] = 0;
            dp[r - 1] = nums[r - 1];
            for(int i = r - 2; i >= l; i--) {
                dp[i] = max(dp[i + 1], nums[i] + dp[i + 2]);
            }
            return dp[l];
        };
        return n == 1 ? nums[0] : max(func(0, n - 1), func(1, n));
    }
};