class Solution {
private:
    void dfs(vector<vector<int>>& grid, vector<pair<int, int>>& island1, vector<pair<int, int>>& island2, int i, int j, int check) {
        if(i >= grid.size() || j >= grid.size() || i < 0 || j < 0 || grid[i][j] != 1) {
            return;
        }
        grid[i][j]++;
        if(check == 0) {
            island1.push_back({i, j});
        }
        else {
            island2.push_back({i, j});
        }
        dfs(grid, island1, island2, i + 1, j, check);
        dfs(grid, island1, island2, i - 1, j, check);
        dfs(grid, island1, island2, i, j + 1, check);
        dfs(grid, island1, island2, i, j - 1, check);
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        vector<pair<int, int>> island1, island2;
        int check = 0, result = INT_MAX;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid.size(); j++) {
                if(grid[i][j] == 1) {
                    dfs(grid, island1, island2, i, j, check);
                    check++;
                }
            }
        }
        for(int i = 0; i < island1.size(); i++) {
            for(int j = 0; j < island2.size(); j++) {
                int x = abs(island1[i].first - island2[j].first);
                int y = abs(island1[i].second - island2[j].second);
                result = min(result, x + y - 1);
            }
        }
        return result;
    }
};