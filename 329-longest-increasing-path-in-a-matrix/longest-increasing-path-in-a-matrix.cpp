class Solution {
private:
    bool outOfBounds(vector<vector<int>>& matrix, int i, int j) {
        int m = matrix.size(), n = matrix[0].size();
        return i < 0 || j < 0 || i >= m || j >= n;
    }
    int dfs(vector<vector<int>>& dp, vector<pair<int,int>>& dirs, vector<vector<int>>& matrix, int i, int j) {
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        dp[i][j] = 1;
        for(auto& [dirX, dirY] : dirs) {
            int x = i + dirX, y = j + dirY;
            if(!outOfBounds(matrix, x, y) && matrix[x][y] > matrix[i][j]) {
                dp[i][j] = max(dp[i][j], 1 + dfs(dp, dirs, matrix, x, y));
            }
        }
        return dp[i][j];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), result = 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        vector<pair<int,int>> dirs {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                result = max(result, dfs(dp, dirs, matrix, i, j));
            }
        }
        return result;
    }
};