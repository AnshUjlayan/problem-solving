class Solution {
private:
    int func(vector<int>& piles, vector<vector<int>>& dp, int l, int r) {
        if(l > r) {
            return 0;
        }
        if(dp[l][r] != -1) {
            return dp[l][r];
        }
        int x = piles[l] - func(piles, dp, l + 1, r);
        int y = piles[r] - func(piles, dp, l, r - 1);
        return dp[l][r] = max(x, y);
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return func(piles, dp, 0, n - 1) > 0 ? true : false;
    }
};