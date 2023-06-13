class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int result = 0, n = grid.size();
        vector<vector<int>> col(n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                col[i].push_back(grid[j][i]);
                
        for(auto row : grid)
            for(int i = 0; i < n; i++)
                if(row == col[i])
                    result++;
        return result;
    }
};