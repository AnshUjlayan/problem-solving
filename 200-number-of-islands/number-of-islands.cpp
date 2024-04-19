class Solution {
private:
    bool outOfBounds(int& m, int& n, int& i, int& j) {
        return i < 0 || j < 0 || i == m || j == n;
    }
    void dfs(vector<vector<char>>& grid, int& m, int& n, int i, int j) {
        if (outOfBounds(m, n, i, j) || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        dfs(grid, m, n, i + 1, j);
        dfs(grid, m, n, i - 1, j);
        dfs(grid, m, n, i, j + 1);
        dfs(grid, m, n, i, j - 1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0, m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, m, n, i, j);
                    result++;
                }
            }
        }
        return result;
    }
};