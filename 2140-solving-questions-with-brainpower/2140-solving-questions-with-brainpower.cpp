class Solution {
private:
    long long func(vector<vector<int>>& questions, vector<long long>& dp, int idx) {
        if(idx >= questions.size()) {
            return 0;
        }
        if(dp[idx] != -1) {
            return dp[idx];
        }
        return dp[idx] = max(questions[idx][0] + func(questions, dp, idx + 1 + questions[idx][1]), func(questions, dp, idx + 1));
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(), -1);
        return func(questions, dp, 0);
    }
};