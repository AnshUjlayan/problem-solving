class Solution {
private:
    bool outOfBounds(vector<vector<int>>& obstacleGrid, int i, int j) {
        return i < 0 || j < 0 || i >= obstacleGrid.size() || j >= obstacleGrid[0].size();
    }
    bool goalSquare(vector<vector<int>>& obstacleGrid, int i, int j) {
        return i == obstacleGrid.size() - 1 && j == obstacleGrid[0].size() - 1;
    }
    int findPath(vector<vector<int>>& dp, vector<vector<int>>& obstacleGrid, int i, int j) {
        if(outOfBounds(obstacleGrid, i, j) || obstacleGrid[i][j] == 1) {
            return 0;
        }
        if(goalSquare(obstacleGrid, i, j)) {
            return 1;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        return dp[i][j] = findPath(dp, obstacleGrid, i + 1, j) + findPath(dp, obstacleGrid, i, j + 1);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
        return findPath(dp, obstacleGrid, 0, 0);
    }
};