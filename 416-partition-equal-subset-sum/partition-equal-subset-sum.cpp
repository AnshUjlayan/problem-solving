class Solution {
private:
    int dp[201][20001];
    bool func(vector<int>& nums, int sum, int idx) {
        if(sum == 0) {
            return true;
        }
        if(idx == nums.size() || sum < 0) {
            return false;
        }
        if(dp[idx][sum] != -1) {
            return dp[idx][sum];
        }
        return dp[idx][sum] = func(nums, sum, idx + 1) || func(nums, sum - nums[idx], idx + 1);
    }
public:
    bool canPartition(vector<int>& nums) {
        int target = accumulate(nums.begin(), nums.end(), 0);
        if(target & 1) {
            return false;
        }
        target /= 2;
        memset(dp, -1, sizeof(dp));
        return func(nums, target, 0);
    }
};