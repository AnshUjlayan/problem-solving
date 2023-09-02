class Solution {
private:
    bool outOfBounds(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        return i < 0 || j < 0 || i >= m || j >= n;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), result = 0, freshCount = 0;
        vector<vector<int>> dirs {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<vector<int>> rotten;
        vector<vector<int>> visited(m, vector<int>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    visited[i][j] = true;
                    rotten.push({i, j, 0});
                }
                freshCount += grid[i][j] == 1 ? 1 : 0;
            }
        }
        while(!rotten.empty() && freshCount) {
            vector<int> orange = rotten.front();
            rotten.pop();
            for(auto& dir : dirs) {
                int x = orange[0] + dir[0], y = orange[1] + dir[1];
                if(!outOfBounds(grid, x, y) && !visited[x][y] && grid[x][y] == 1) {
                    freshCount--;
                    visited[x][y] = true;
                    rotten.push({x, y, orange[2] + 1});
                    result = orange[2] + 1;
                }
            }
        }
        return freshCount == 0 ? result : -1;
    }
};