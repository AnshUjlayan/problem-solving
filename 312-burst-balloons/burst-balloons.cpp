class Solution {
private:
    int getNum(vector<int>& nums, int idx) {
        return idx < 0 || idx > nums.size() - 1 ? 1 : nums[idx];
    }
    int func(vector<vector<int>>& dp, vector<int>& nums, int l, int r) {
        if(l > r) {
            return 0;
        }
        if(dp[l][r] != -1) {
            return dp[l][r];
        }
        int result = 0;
        for(int i = l; i <= r; i++) {
            result = max(result, (nums[i] * getNum(nums, l - 1) * getNum(nums, r + 1)) + func(dp, nums, l, i - 1) + func(dp, nums, i + 1, r));
        }
        return dp[l][r] = result;
    }
public:
    int maxCoins(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        return func(dp, nums, 0, nums.size() - 1);
    }
};