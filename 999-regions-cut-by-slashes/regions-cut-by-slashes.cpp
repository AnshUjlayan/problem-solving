class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        int result = 0;
        const int n = grid.size();
        vector<vector<bool>> dard(n * 3, vector<bool>(n * 3, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '/') {
                    dard[i * 3][j * 3 + 2] = true;
                    dard[i * 3 + 1][j * 3 + 1] = true;
                    dard[i * 3 + 2][j * 3] = true;
                }
                else if (grid[i][j] == '\\') {
                    dard[i * 3][j * 3] = true;
                    dard[i * 3 + 1][j * 3 + 1] = true;
                    dard[i * 3 + 2][j * 3 + 2] = true;
                }
            }
        }

        function<void(int, int)> dfs = [&dfs, &dard, &n] (const int i, const int j) {
            if (i < 0 || j < 0 || i >= n * 3 || j >= n * 3 || dard[i][j])
                return;
            dard[i][j] = true;
            dfs(i, j - 1);
            dfs(i, j + 1);
            dfs(i + 1, j);
            dfs(i - 1, j);
        };

        for (int i = 0; i < n * 3; i++) {
            for (int j = 0; j < n * 3; j++) {
                if (!dard[i][j]) {
                    dfs(i, j);
                    result++;
                }
            }
        }

        return result;
    }
};