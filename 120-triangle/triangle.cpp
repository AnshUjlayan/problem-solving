class Solution {
private:
    int func(vector<vector<int>>& dp, vector<vector<int>>& triangle, int level, int idx) {
        if(level == triangle.size()) {
            return 0;
        }
        if(dp[level][idx] != -1) {
            return dp[level][idx];
        }
        return dp[level][idx] = triangle[level][idx] + min(func(dp, triangle, level + 1, idx), func(dp, triangle, level + 1, idx + 1));
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(triangle[n - 1].size(), -1));
        return func(dp, triangle, 0, 0);
    }
};