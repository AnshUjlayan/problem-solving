class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> dp(n, 0);
        long long sum = accumulate(nums.begin(), nums.begin() + k, 0ll);
        long long res = sum;
        dp[k - 1] = sum;
        for (int i = k; i < n; i++) {
            sum += nums[i] - nums[i - k];
            dp[i] = max(sum, dp[i - k] + sum);
            res = max(res, dp[i]);
        }
        return res;
    }
};