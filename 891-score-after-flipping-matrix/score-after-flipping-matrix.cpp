class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++) {
            if(!grid[i][0]) {
                for(int& x : grid[i]) {
                    x = 1 - x;
                }
            }
        }
        int result = 0;
        for(int j = 0; j < n; j++) {
            int cnt = 0;
            for(int i = 0; i < m; i++) {
                cnt += grid[i][j];
            }
            cnt = cnt <= m / 2 ? m - cnt : cnt;
            result += (1 << (n - j - 1)) * cnt;
        }
        return result;
    }
};