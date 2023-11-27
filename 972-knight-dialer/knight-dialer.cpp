class Solution {
private:
    int mod = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    vector<pair<int,int>> dirs {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

    bool valid(int i, int j) {
        if(i == 3) {
            return j == 1;
        }
        return i >= 0 && i < 4 && j >= 0 && j < 3;
    }

    int func(int i, int j, int k) {
        if(!valid(i, j)) {
            return 0;
        }
        if(!k) {
            return 1;
        }
        if(dp[i][j][k] != -1) {
            return dp[i][j][k];
        }
        long long res = 0;
        for(auto& [dirX, dirY] : dirs) {
            int x = i + dirX;
            int y = j + dirY;
            res += func(x, y, k - 1);
            res %= mod;
        }
        return dp[i][j][k] = (int)res;
    }
public:
    int knightDialer(int n) {
        dp.resize(4, vector<vector<int>>(3, vector<int>(n, -1)));
        long long result = 0;
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 3; j++) {
                result += func(i, j, n - 1);
                result %= mod;
            }
        }
        return (int)result;
    }
};