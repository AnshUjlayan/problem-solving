class Solution {
private:
    void dfs(vector<vector<int>>& grid, int i, int j, int n, int m) {
        if(i < 0 || i > n - 1 || j < 0 || j > m - 1 || grid[i][j] == 0) {
            return;
        }
        grid[i][j] = 0;
        dfs(grid, i + 1, j, n, m);
        dfs(grid, i - 1, j, n, m);
        dfs(grid, i, j + 1, n, m);
        dfs(grid, i, j - 1, n, m);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int result = 0, n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if((i == 0 || i == n - 1 || j == 0 || j == m - 1) && grid[i][j] == 1) {
                    dfs(grid, i, j, n, m);
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    result++;
                }
            }
        }
        return result;
    }
};