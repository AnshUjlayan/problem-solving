class Solution {
private:
    int func(vector<vector<int>>& dp, string& colors, vector<int>& neededTime, int prev, int idx) {
        if(idx == colors.size()) {
            return 0;
        }
        if(dp[prev][idx] != -1) {
            return dp[prev][idx];
        }
        if(colors[idx] - 'a' == prev) {
            return dp[prev][idx] = neededTime[idx] + func(dp, colors, neededTime, prev, idx + 1);
        }
        return dp[prev][idx] = min(
            neededTime[idx] + func(dp, colors, neededTime, prev, idx + 1),
            func(dp, colors, neededTime, colors[idx] - 'a', idx + 1)
        );
    }
public:
    int minCost(string colors, vector<int>& neededTime) {
        vector<vector<int>> dp(27, vector<int>(colors.size(), -1));
        return func(dp, colors, neededTime, 26, 0);
    }
};