class Solution {
private:
    vector<vector<int>> dp;
    int pain(vector<int> &nums, int mx, int temp, int idx) {
        if (idx == nums.size())
            return temp == mx;
        if (dp[idx][temp] != -1)
            return dp[idx][temp];
        return pain(nums, mx, temp, idx + 1) + pain(nums, mx, temp | nums[idx], idx + 1);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size(), mx = 0, temp = 0, result = 0;
        dp.resize(n, vector<int>(1e6, -1));
        for (int &num : nums)
            mx |= num;
        return pain(nums, mx, 0, 0);
    }
};