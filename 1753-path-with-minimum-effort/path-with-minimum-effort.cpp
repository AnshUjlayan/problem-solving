class Solution {
private:
    vector<pair<int,int>> dirs {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool bfs(vector<vector<int>>& heights, int maxDiff) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        auto outOfBounds = [&] (int x, int y) ->bool {
            return x < 0 || y < 0 || x >= m || y >= n;
        };
        queue<pair<int,int>> q;
        q.push({0, 0});
        visited[0][0] = true;
        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            if(i == m - 1 && j == n - 1) {
                return true;
            }
            for(auto& [dirX, dirY] : dirs) {
                int x = i + dirX, y = j + dirY;
                if(!outOfBounds(x, y) && !visited[x][y] && abs(heights[i][j] - heights[x][y]) <= maxDiff) {
                    q.push({x, y});
                    visited[x][y] = true;
                }
            }
        }
        return false;
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int l = 0, r = 1e6;
        while(l <= r) {
            int mid = l + (r -l) / 2;
            if(bfs(heights, mid)) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return r + 1;
    }
};