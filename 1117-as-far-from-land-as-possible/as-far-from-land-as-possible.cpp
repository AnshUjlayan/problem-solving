class Solution {
private:
    bool checkBounds(int n, int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < n;
    }
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), result = -1;
        queue<vector<int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<pair<int,int>> paths = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j, 0});
                    visited[i][j] = true;
                }
            }
        }
        while(!q.empty()) {
            vector<int> front = q.front();
            q.pop();
            for(auto& path : paths) {
                int x = front[0] + path.first;
                int y = front[1] + path.second;
                if(checkBounds(n, x, y) && !visited[x][y]) {
                    q.push({x, y, front[2] + 1});
                    visited[x][y] = true;
                    result = max(result, front[2] + 1);
                }
            }
        }
        return result;
    }
};