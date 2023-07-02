class Solution {
private:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return 0;
        }
        if(grid[i][j] == 1) {
            return 1;
        }
        grid[i][j] = 1;
        int a = dfs(grid, i + 1, j);
        int b = dfs(grid, i - 1, j);
        int c = dfs(grid, i, j + 1);
        int d = dfs(grid, i, j - 1);
        if(a && b && c && d) {
            return 1;
        }
        return 0;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int result = 0, n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    result += dfs(grid, i, j);
                } 
            }
        }
        return result;
    }
};