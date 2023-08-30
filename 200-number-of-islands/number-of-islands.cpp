class Solution {
private:
    bool outOfBounds(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        return i < 0 || j < 0 || i >= m || j >= n;
    }

    void dfs(vector<vector<char>>& grid, int i, int j) {
        if(outOfBounds(grid, i, j) || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0, m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    result++;
                }
            }
        }
        return result;
    }
};