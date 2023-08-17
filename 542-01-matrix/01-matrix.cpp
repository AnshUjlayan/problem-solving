class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int,int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<vector<int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    result[i][j] = 0;
                    visited[i][j] = true;
                    q.push({i, j, 0});
                }
            }
        }
        auto boundsCheck = [&] (int x, int y) -> bool {
            return x >= 0 && x < m && y >= 0 && y < n;
        };
        while(!q.empty()) {
            vector<int> curr = q.front();
            q.pop();
            result[curr[0]][curr[1]] = curr[2];
            for(auto dir : dirs) {
                int x = curr[0] + dir.first;
                int y = curr[1] + dir.second;
                if(boundsCheck(x, y) && !visited[x][y]) {
                    q.push({x, y, curr[2] + 1});
                    visited[x][y] = true;
                }
            }
        }
        return result;
    }
};