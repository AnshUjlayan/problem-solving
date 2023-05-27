class Solution {
private:
    int func(vector<int>& piles, vector<vector<int>>& dp, int m, int idx) {
        if(idx >= piles.size()) {
            return 0;
        }
        if(dp[idx][m] != -1) {
            return dp[idx][m];
        }
        int sum = 0;
        int result = INT_MIN;
        for(int x = 0; x < 2 * m; x++) {
            if(idx + x >= piles.size()) {
                break;
            }
            sum += piles[idx + x];
            result = max(result, sum - func(piles, dp, max(m, x + 1), idx + x + 1));
        }
        return dp[idx][m] = result;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int sum = accumulate(piles.begin(), piles.end(), 0);
        return (func(piles, dp, 1, 0) + sum) / 2;
    }
};