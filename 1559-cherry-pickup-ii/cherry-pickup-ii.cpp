class Solution {
private:
    vector<vector<vector<int>>> dp;
    int getSlimy(vector<vector<int>>& grid, int i, int j, int k) {
        if(k == grid.size() || i < 0 || j < 0 || i == grid[0].size() || j == grid[0].size()) {
            return 0;
        }
        if(dp[i][j][k] != -1) {
            return dp[i][j][k];
        }
        int result = 0;
        for(int p = -1; p <= 1; p++) {
            for(int q = -1; q <= 1; q++) {
                result = max(result, getSlimy(grid, i + p, j + q, k + 1));
            }
        }
        return dp[i][j][k] = (i == j ? grid[k][i] : grid[k][i] + grid[k][j]) + result;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        this->dp.resize(grid[0].size(), vector<vector<int>>(grid[0].size(), vector<int>(grid.size(), -1)));
        return getSlimy(grid, 0, grid[0].size() - 1, 0);
    }
};