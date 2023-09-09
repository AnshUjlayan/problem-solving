class Solution {
private:
    int func(vector<int>& dp, vector<int>& nums, int target) {
        if(target == 0) {
            return 1;
        }
        if(target < 0) {
            return 0;
        }
        if(dp[target] != -1) {
            return dp[target];
        }
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            ans += func(dp, nums, target - nums[i]);
        }
        return dp[target] = ans;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        func(dp, nums, target);
        return dp[target];
    }
};