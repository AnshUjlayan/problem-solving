class Solution {
private:
    int func(vector<unordered_map<int,int>>& dp, vector<int>& nums, int target, int idx) {
        if(idx == nums.size()) {
            return target == 0;
        }
        if(dp[idx].find(target) != dp[idx].end()) {
            return dp[idx][target];
        }
        return dp[idx][target] = func(dp, nums, target + nums[idx], idx + 1) + func(dp, nums, target - nums[idx], idx + 1);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<unordered_map<int,int>> dp(nums.size());
        return func(dp, nums, target, 0);
    }
};