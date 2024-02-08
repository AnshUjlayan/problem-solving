class Solution {
private:
    vector<int> dp;
    int getSlimy(int n) {
        if(n == 0) {
            return 0;
        }
        if(dp[n] < 1e5) {
            return dp[n];
        }
        for(int i = 1; i <= sqrt(n); i++) {
            dp[n] = min(dp[n], 1 + getSlimy(n - (i * i)));
        }
        return dp[n];
    }
public:
    int numSquares(int n) {
        this->dp.resize(n + 1, 1e5);
        return getSlimy(n);
    }
};