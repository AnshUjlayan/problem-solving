class Solution {
private:
    bool check(vector<int>& nums, int idx) {
        return (nums[idx] == nums[idx + 1] && nums[idx + 1] == nums[idx + 2]) || (nums[idx] == nums[idx + 1] - 1 && nums[idx + 1] == nums[idx + 2] - 1);
    }
    bool func(vector<int>& dp, vector<int>& nums, int idx) {
        if(idx == nums.size()) {
            return true;
        }
        if(idx == nums.size() - 1) {
            return false;
        }
        if(dp[idx] != -1) {
            return dp[idx];
        }
        if(idx + 2 <= nums.size() && nums[idx] == nums[idx + 1] && func(dp, nums, idx + 2)) {
            return dp[idx] = 1;
        }
        if(idx + 3 <= nums.size() && check(nums, idx) && func(dp, nums, idx + 3)) {
            return dp[idx] = 1;
        }
        return dp[idx] = 0;
    }
public:
    bool validPartition(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return func(dp, nums, 0);
    }
};