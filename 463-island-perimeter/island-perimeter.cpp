class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int result = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int top = i == 0 ? 0 : grid[i - 1][j];
                int left = j == 0 ? 0 : grid[i][j - 1];
                int bottom = i == m - 1 ? 0 : grid[i + 1][j];
                int right = j == n - 1 ? 0 : grid[i][j + 1];
                int curr = grid[i][j];
                result += (curr ^ top) + (curr ^ left) + (curr ^ bottom) + (curr ^ right);
            }
        }
        for(int i = 0; i < m; i++) {
            if(grid[i][0]) result++;
            if(grid[i][n - 1]) result++;
        }
        for(int j = 0; j < n; j++) {
            if(grid[0][j]) result++;
            if(grid[m - 1][j]) result++;
        }
        return result / 2;
    }
};