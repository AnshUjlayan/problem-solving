class Solution {
private:
    int mod = 1e9 + 7;
    vector<vector<int>> dp;
    int func(int n, int k, int target) {
        if(!n) {
            return target == 0;
        }
        if(target < 0) {
            return 0;
        }
        if(dp[n][target] != -1) {
            return dp[n][target];
        }
        long long result = 0;
        for(int i = 1; i <= k; i++) {
            result += func(n - 1, k, target - i);
            result %= mod;
        }
        return dp[n][target] = (int)result;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        this->dp.resize(n + 1, vector<int>(target + 1, -1));
        return func(n, k, target);
    }
};