class Solution {
private:
    const int mod = 1e9 + 7;
    int dfs(vector<vector<int>>& grid, int (&dp)[1001][1001], int m, int n, int i, int j, int last) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] <= last)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        pair<int,int> p[] = {{i + 1, j}, {i - 1, j}, {i, j + 1}, {i, j - 1}};
        int res = 1;
        for(pair<int,int> &idx : p) {
            res = (res + (dfs(grid, dp, m, n, idx.first, idx.second, grid[i][j]) % mod)) % mod;
        }
        return dp[i][j] = res;
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        int result = 0, m = grid.size(), n = grid[0].size();
        int dp[1001][1001];
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                result = (result + (dfs(grid, dp, m, n, i, j, INT_MIN) % mod)) % mod;
        return result;
    }
};