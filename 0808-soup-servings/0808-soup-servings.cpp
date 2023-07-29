class Solution {
private:
    double func(vector<vector<double>>& dp, int a, int b) {
        if(a <= 0 && b <= 0) {
            return 0.5;
        }
        if(a <= 0) {
            return 1.0;
        }
        if(b <= 0) {
            return 0.0;
        }
        if(dp[a][b] != -1) {
            return dp[a][b];
        }
        double uno = func(dp, a - 4, b);
        double dos = func(dp, a - 3, b - 1);
        double tres = func(dp, a - 2, b - 2);
        double quatro = func(dp, a - 1, b - 3);
        return dp[a][b] = 0.25 * (uno + dos + tres + quatro);
    }
public:
    double soupServings(int n) {
        if(n > 10000)
            return 1;
        n = ceil(n / 25.0);
        vector<vector<double>> dp(n + 1, vector<double>(n + 1, -1));
        return func(dp, n, n);
    }
};