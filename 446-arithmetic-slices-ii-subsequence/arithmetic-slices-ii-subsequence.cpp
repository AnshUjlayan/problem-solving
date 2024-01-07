class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int result = 0, n = nums.size();
        vector<map<long long,int>> dp(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                long long diff = (long long)nums[j] - nums[i];
                dp[i][diff]++;
                if(dp[j].count(diff)) {
                    dp[i][diff] += dp[j][diff];
                    result += dp[j][diff];
                }
            }
        }
        return result;
    }
};