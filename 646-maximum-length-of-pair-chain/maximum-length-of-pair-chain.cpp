class Solution {
private:
    int func(vector<vector<int>>& dp, vector<vector<int>>& pairs, int pos, int idx) {
        if(idx == pairs.size()) {
            return 0;
        }
        if(dp[idx][pos + 1001] != -1) {
            return dp[idx][pos + 1001];
        }
        dp[idx][pos + 1001] = func(dp, pairs, pos, idx + 1);
        if(pos < pairs[idx][0]) {
            return dp[idx][pos + 1001] = max(dp[idx][pos + 1001], 1 + func(dp, pairs, pairs[idx][1], idx + 1));
        }
        return dp[idx][pos + 1001];
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        vector<vector<int>> dp(pairs.size(), vector<int>(2002, -1));
        return func(dp, pairs, -1001, 0);
    }
};