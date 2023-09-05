class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<int> dp(2001, 0);
        dp[1000] = 1;
        for(int i = 0; i < nums.size(); i++) {
            vector<int> nextDp(2001, 0);
            for(int j = 0; j < 2001; j++) {
                nextDp[j] += j - nums[i] >= 0 ? dp[j - nums[i]] : 0;
                nextDp[j] += j + nums[i] < 2000 ? dp[j + nums[i]] : 0;
            }
            dp = nextDp;
        }
        return dp[1000 + target];
    }
};