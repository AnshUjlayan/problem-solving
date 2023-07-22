class Solution {
private:
    bool outOfBounds(int n, int i, int j) {
        return i < 0 || j < 0 || i >= n || j >= n;
    }
    double func(vector<vector<vector<double>>>& dp, vector<vector<int>>& moves, int n, int k, int row, int column) {
        if(outOfBounds(n, row, column)) {
            return 0.0;
        }
        if(k == 0) {
            return 1.0;
        }
        if(dp[row][column][k] != 0.0) {
            return dp[row][column][k];
        }
        double result = 0.0;
        for(auto& move : moves) {
            result += func(dp, moves, n, k - 1, row + move[0], column + move[1]);
        }
        return dp[row][column][k] = result / 8.0;
    }
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k + 1, 0.0)));
        vector<vector<int>> moves = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
        return func(dp, moves, n, k, row, column);
    }
};