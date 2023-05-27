class Solution {
private:
    int func(vector<int>& stoneValue, vector<int>& dp, int idx) {
        if(idx >= stoneValue.size()) {
            return 0;
        }
        if(dp[idx] != -1) {
            return dp[idx];
        }
        int sum = 0;
        int result = INT_MIN;
        for(int x = 0; x < 3; x++) {
            if(idx + x >= stoneValue.size()) {
                break;
            }
            sum += stoneValue[idx + x];
            result = max(result, sum - func(stoneValue, dp, idx + x + 1));
        }
        return dp[idx] = result;
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n, -1);
        int x = func(stoneValue, dp, 0);
        return x == 0 ? "Tie" : (x > 0 ? "Alice" : "Bob");
    }
};