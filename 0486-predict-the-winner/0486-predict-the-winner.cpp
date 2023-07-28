class Solution {
private:
    int func(vector<vector<vector<int>>>& dp, vector<int>& nums, int turn, int l, int r) {
        if(l > r)
            return 0;
        if(dp[l][r][turn] != -1) 
            return dp[l][r][turn];
        int result;
        if(turn)
            result = max(nums[l] + func(dp, nums, 1 - turn, l + 1, r), nums[r] + func(dp, nums, 1 - turn, l, r - 1));
        else
            result = min(-nums[l] + func(dp, nums, 1 - turn, l + 1, r), -nums[r] + func(dp, nums, 1 - turn, l, r - 1));
        return dp[l][r][turn] = result;
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<vector<int>>> dp(nums.size(), vector<vector<int>>(nums.size(), vector<int>(2, -1)));
        return func(dp, nums, 1, 0, nums.size() - 1) >= 0;
    }
};