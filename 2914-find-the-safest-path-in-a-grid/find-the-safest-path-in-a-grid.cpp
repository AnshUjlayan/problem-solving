class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> thief;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    thief.push({i, j});
                }
            }
        }
        while (!thief.empty()) {
            auto [i, j] = thief.front();
            thief.pop();
            for (auto& [dirX, dirY] : dirs) {
                int x = i + dirX, y = j + dirY;
                if (x >= 0 && y >= 0 && x < m && y < n && !grid[x][y]) {
                    thief.push({x, y});
                    grid[x][y] = grid[i][j] + 1;
                }
            }
        }
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;
        while (!pq.empty()) {
            auto safenessFactor = pq.top().first;
            auto [i, j] = pq.top().second;
            pq.pop();
            if (i == m - 1 && j == n - 1) {
                return safenessFactor - 1;
            }
            for (auto& [dirX, dirY] : dirs) {
                int x = i + dirX, y = j + dirY;
                if (x >= 0 && y >= 0 && x < m && y < n && !visited[x][y]) {
                    pq.push({min(safenessFactor, grid[x][y]), {x, y}});
                    visited[x][y] = true;
                }
            }
        }
        return -1;
    }
};