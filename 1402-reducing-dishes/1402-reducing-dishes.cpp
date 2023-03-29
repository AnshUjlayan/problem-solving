class Solution {
private:
    int func(vector<int>& satisfaction, vector<vector<int>>& dp, int idx, int mul) {
        if(idx == satisfaction.size())
            return 0;
        if(dp[idx][mul] != -1)
            return dp[idx][mul];
        int x = func(satisfaction, dp, idx + 1, mul);
        int y = satisfaction[idx] * mul + func(satisfaction, dp, idx + 1, mul + 1);
        return dp[idx][mul] = max(x, y);
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> dp(satisfaction.size() + 1, vector<int>(satisfaction.size() + 1, -1));
        return func(satisfaction, dp, 0, 1);
    }
};