class Solution {
private:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || !grid[i][j]) {
            return 0;
        }
        int temp = grid[i][j];
        grid[i][j] = 0;
        int res = max({
            dfs(grid, i + 1, j),
            dfs(grid, i - 1, j),
            dfs(grid, i, j + 1),
            dfs(grid, i, j - 1)
        });
        grid[i][j] = temp;
        return temp + res;
    }

public:
    int getMaximumGold(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int result = 0, m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                result = max(result, dfs(grid, i, j));
            }
        }
        return result;
    }
};