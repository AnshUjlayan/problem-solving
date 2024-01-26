class Solution {
private:
    int MOD = 1e9 + 7;
    vector<pair<int,int>> dirs {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<vector<int>>> dp;
    bool outOfBounds(int m, int n, int i, int j) {
        return i >= m || j >= n || i < 0 || j < 0;
    }
    int getSlimy(int m, int n, int i, int j, int moves) {
        if(outOfBounds(m, n, i, j)) {
            return 1;
        }
        if(!moves) {
            return 0;
        }
        if(dp[i][j][moves] != -1) {
            return dp[i][j][moves];
        }
        long long result = 0;
        for(auto& [dirX, dirY] : dirs) {
            result += getSlimy(m, n, i + dirX, j + dirY, moves - 1);
        }
        return dp[i][j][moves] = int(result % MOD);
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        this->dp.resize(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return getSlimy(m, n, startRow, startColumn, maxMove);
    }
};