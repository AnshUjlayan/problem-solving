class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(triangle[n - 1].size() + 1, 0);
        for(int i = n - 1; i >= 0; i--) {
            vector<int> newDp(triangle[i].size());
            for(int j = 0; j < triangle[i].size(); j++) {
                newDp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
            dp = newDp;
        }
        return dp[0];
    }
};