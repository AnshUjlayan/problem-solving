class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k == 0 || n >= k - 1 + maxPts) {
            return 1.0;
        }
        double sum = 1.0, prob = 0.0;
        vector<double> dp(n + 1, 0.0);
        dp[0] = 1;
        for(int i = 1; i <= n; i++) {
            dp[i] = sum / maxPts;
            if(i < k) {
                sum += dp[i];
            }
            else {
                prob += dp[i];
            }
            if(i >= maxPts) {
                sum -= dp[i - maxPts];
            }
        }
        return prob;
    }
};