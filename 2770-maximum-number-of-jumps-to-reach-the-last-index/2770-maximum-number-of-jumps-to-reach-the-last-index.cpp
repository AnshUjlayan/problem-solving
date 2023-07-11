class Solution {
private:
    int func(vector<int>& nums, vector<int>& dp, int target, int idx) {
        if(idx == nums.size() - 1)
            return 0;
        if(dp[idx] != -1)
            return dp[idx];
        int result = INT_MIN;
        for(int i = idx + 1; i < nums.size(); i++) {
            if(abs(nums[i] - nums[idx]) <= target) {
                result = max(result, 1 + func(nums, dp, target, i));
            }
        }
        return dp[idx] = result;
    }
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1);
        func(nums, dp, target, 0);
        return dp[0] <= 0 ? -1 : dp[0];
    }
};