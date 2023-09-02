class Solution {
private:
    bool outOfBounds(vector<vector<int>>& heights, int i, int j) {
        int m = heights.size(), n = heights[0].size();
        return i < 0 || j < 0 || i >= m || j >= n;
    }
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, vector<vector<int>>& dirs, int i, int j) {
        if(visited[i][j]) {
            return;
        }
        visited[i][j] = true;
        for(auto& dir : dirs) {
            int x = i + dir[0], y = j + dir[1];
            if(!outOfBounds(heights, x, y) && heights[i][j] <= heights[x][y]) {
                dfs(heights, visited, dirs, x, y);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> result, pacificEdge, atlanticEdge;
        vector<vector<bool>> visitedPacific(m, vector<bool>(n, false));
        vector<vector<bool>> visitedAtlantic(m, vector<bool>(n, false));
        vector<vector<int>> dirs {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 || j == 0) {
                    dfs(heights, visitedPacific, dirs, i, j);
                }
                if(i == m - 1 || j == n - 1) {
                    dfs(heights, visitedAtlantic, dirs, i, j);
                }
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(visitedPacific[i][j] && visitedAtlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};