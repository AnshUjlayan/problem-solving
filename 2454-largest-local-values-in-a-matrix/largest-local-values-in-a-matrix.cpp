class Solution {
private:
    int maxLocal(vector<vector<int>>& grid, int i, int j) {
        return max({
            grid[i][j], 
            grid[i - 1][j - 1], grid[i - 1][j], grid[i - 1][j + 1],
            grid[i][j - 1], grid[i][j], grid[i][j + 1],
            grid[i + 1][j - 1], grid[i + 1][j], grid[i + 1][j + 1],
        });
    }

public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> result;
        vector<int> temp;
        for(int i = 1; i < n - 1; i++) {
            temp.clear();
            for(int j = 1; j < n - 1; j++) {
                temp.push_back(maxLocal(grid, i, j));
            }
            result.push_back(temp);
        }
        return result;
    }
};