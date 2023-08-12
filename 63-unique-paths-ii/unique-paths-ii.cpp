class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<int> dp(obstacleGrid[0].size(), 0);
        dp[0] = 1;
        for(int i = 0; i < obstacleGrid.size(); i++) {
            vector<int> newDp(obstacleGrid[0].size() + 1, 0);
            for(int j =  0; j < obstacleGrid[0].size(); j++) {
                if(obstacleGrid[i][j] == 0) {
                    newDp[j] = dp[j];
                    if(j > 0) {
                        newDp[j] = newDp[j] + newDp[j - 1];
                    }
                    
                }
            }
            dp = newDp;
        }
        return dp[obstacleGrid[0].size() - 1];
    }
};