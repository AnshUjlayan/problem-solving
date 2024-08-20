class Solution {
private:
    int getSlimy(vector<vector<int>>& dp, vector<int>& piles, int idx, int m) {
        if (idx >= piles.size())
            return 0;
        
        if (dp[idx][m] != INT_MIN)
            return dp[idx][m];
        
        int sum = 0;
        for (int i = 0; i < 2 * m; i++) {
            if (idx + i >= piles.size())
                break;
            sum += piles[idx + i];
            dp[idx][m] = max(dp[idx][m], sum - getSlimy(dp, piles, idx + i + 1, max(m, i + 1)));
        }
        return dp[idx][m];
    }

public:
    int stoneGameII(vector<int>& piles) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<vector<int>> dp(piles.size(), vector<int>(piles.size() + 1, INT_MIN));
        return (getSlimy(dp, piles, 0, 1) + accumulate(piles.begin(), piles.end(), 0)) / 2;
    }
};